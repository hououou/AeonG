# Copyright 2021 Memgraph Ltd.
#
# Use of this software is governed by the Business Source License
# included in the file licenses/BSL.txt; by using this file, you agree to be bound by the terms of the Business Source
# License, and you may not use this file except in compliance with the Business Source License.
#
# As of the Change Date specified in that file, in accordance with
# the Business Source License, use of this software will be governed
# by the Apache License, Version 2.0, included in the file
# licenses/APL.txt.

import atexit
import json
import os
import re
import subprocess
import tempfile
import time


def wait_for_server(port, delay=0.1):
    cmd = ["nc", "-z", "-w", "1", "127.0.0.1", str(port)]
    while subprocess.call(cmd) != 0:
        time.sleep(0.01)
    time.sleep(delay)


def _convert_args_to_flags(*args, **kwargs):
    flags = list(args)
    for key, value in kwargs.items():
        key = "--" + key.replace("_", "-")
        if type(value) == bool:
            flags.append(key + "=" + str(value).lower())
        else:
            flags.append(key)
            flags.append(str(value))
    return flags


def _get_usage(pid):
    total_cpu = 0
    with open("/proc/{}/stat".format(pid)) as f:
        total_cpu = (sum(map(int, f.read().split(")")[1].split()[11:15])) /
                     os.sysconf(os.sysconf_names["SC_CLK_TCK"]))
    peak_rss = 0
    with open("/proc/{}/status".format(pid)) as f:
        for row in f:
            tmp = row.split()
            if tmp[0] == "VmHWM:":
                peak_rss = int(tmp[1]) * 1024
    return {"cpu": total_cpu, "memory": peak_rss}


class Memgraph:
    def __init__(self, memgraph_binary, temporary_dir, properties_on_edges, memgraph_port, memory_limit, anchor_num,
                 snapshot_interval_sec=60, real_time_flag=False, graph_operations=10000, storage_gc_cycle_sec=30,
                 storage_snapshot_on_exit="true", query_modules_directory="", retention_on_startup=False,
                 retention_interval_sec=60, retention_period_sec=15):
        self._memgraph_binary = memgraph_binary
        self._directory = temporary_dir
        self._properties_on_edges = properties_on_edges
        self._proc_mg = None
        self._port = memgraph_port
        self._snapshot_interval_sec = snapshot_interval_sec
        self._query_modules_directory = query_modules_directory
        self._memory_limit = memory_limit
        self._anchor_num = anchor_num
        self._graph_operations = graph_operations
        self._storage_snapshot_on_exit = storage_snapshot_on_exit
        self._storage_gc_cycle_sec = storage_gc_cycle_sec
        self._real_time_flag = real_time_flag
        self._retention_on_startup = retention_on_startup
        self._retention_interval_sec = retention_interval_sec  # 默认每60秒check一次是否删除
        self._retention_period_sec = retention_period_sec

        atexit.register(self._cleanup)

        if retention_interval_sec != 0:
            self._retention_on_startup = True
        self._memgraph_version = (0, 50, 0)

    def _get_args(self, **kwargs):
        data_directory = os.path.join(self._directory, "memgraph")  # self._directory.name
        if self._memgraph_version >= (0, 50, 0):
            kwargs["data_directory"] = data_directory
            # kwargs["port"] =7688 wzy edit
        else:
            kwargs["durability_directory"] = data_directory
        if self._memgraph_version >= (0, 50, 0):
            kwargs["storage_properties_on_edges"] = self._properties_on_edges
        else:
            assert self._properties_on_edges, \
                "Older versions of Memgraph can't disable properties on edges!"
        return _convert_args_to_flags(self._memgraph_binary, **kwargs)

    def _start(self, **kwargs):
        if self._proc_mg is not None:
            raise Exception("The database process is already running!")
        args = self._get_args(**kwargs)
        # print("_start",args)
        self._proc_mg = subprocess.Popen(args, stdout=subprocess.DEVNULL)  # subprocess.PIPE subprocess.DEVNULL
        time.sleep(0.2)
        if self._proc_mg.poll() is not None:
            self._proc_mg = None
            raise Exception("The database process died prematurely!")
        wait_for_server(self._port)
        ret = self._proc_mg.poll()
        assert ret is None, "The database process died prematurely " \
                            "({})!".format(ret)

    def _cleanup(self):
        if self._proc_mg is None:
            return 0
        usage = _get_usage(self._proc_mg.pid)
        self._proc_mg.terminate()
        ret = self._proc_mg.wait()
        self._proc_mg = None
        return ret, usage

    def start_preparation(self):
        if self._memgraph_version >= (0, 50, 0):
            self._start(storage_snapshot_on_exit=True, bolt_port=self._port)
        else:
            self._start(snapshot_on_exit=True)

    def start_benchmark(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            query_modules_directory=self._query_modules_directory, memory_limit=self._memory_limit,
                            anchor_num=self._anchor_num, storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag)
            else:
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit, anchor_num=self._anchor_num,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag)  # memory_limit=self._memory_limit

        else:
            self._start(db_recover_on_startup=True)

    def start_clockg_benchmark(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            query_modules_directory=self._query_modules_directory, memory_limit=self._memory_limit,
                            storage_snapshot_on_exit=False, storage_gc_cycle_sec=self._storage_gc_cycle_sec)
            else:
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit, storage_snapshot_on_exit=False,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)  # memory_limit=self._memory_limit

        else:
            self._start(db_recover_on_startup=True)

    def start_tgql_benchmark(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            query_modules_directory=self._query_modules_directory, memory_limit=self._memory_limit,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)
            else:
                self._start(storage_recover_on_startup=True, bolt_port=self._port, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)  # memory_limit=self._memory_limit

        else:
            self._start(db_recover_on_startup=True)

    def start_dataset(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            query_modules_directory=self._query_modules_directory, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit, anchor_num=self._anchor_num,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag)  # ,isolation_level="READ_UNCOMMITTED"
            else:
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            storage_properties_on_edges="true", memory_limit=self._memory_limit,
                            anchor_num=self._anchor_num, storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag)  # ,storage_gc_cycle_sec=6000,isolation_level="READ_UNCOMMITTED"
        else:
            self._start(db_recover_on_startup=True)

    def start_tgdb_clean_dataset(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            query_modules_directory=self._query_modules_directory,
                            storage_properties_on_edges="true", memory_limit=self._memory_limit,
                            anchor_num=self._anchor_num, storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag
                            , retention_on_startup=self._retention_on_startup,
                            retention_interval_sec=self._retention_interval_sec,
                            retention_period_sec=self._retention_period_sec)  # ,isolation_level="READ_UNCOMMITTED"
            else:
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            storage_properties_on_edges="true", memory_limit=self._memory_limit,
                            anchor_num=self._anchor_num, storage_gc_cycle_sec=self._storage_gc_cycle_sec,
                            real_time_flag=self._real_time_flag
                            , retention_on_startup=self._retention_on_startup,
                            retention_interval_sec=self._retention_interval_sec,
                            retention_period_sec=self._retention_period_sec)  # ,storage_gc_cycle_sec=6000,isolation_level="READ_UNCOMMITTED"
        else:
            self._start(db_recover_on_startup=True)

    def start_tgql_dataset(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            query_modules_directory=self._query_modules_directory, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)  # ,isolation_level="READ_UNCOMMITTED"
            else:
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            storage_properties_on_edges="true", memory_limit=self._memory_limit,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)
        else:
            self._start(db_recover_on_startup=True)

    def start_clockg_dataset(self):
        # TODO: support custom benchmarking config files!
        if self._memgraph_version >= (0, 50, 0):
            if self._query_modules_directory != "":
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            query_modules_directory=self._query_modules_directory, storage_properties_on_edges="true",
                            memory_limit=self._memory_limit, graph_operations=self._graph_operations,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)  # ,isolation_level="READ_UNCOMMITTED"
            else:
                self._start(storage_snapshot_on_exit=True, storage_recover_on_startup=True,
                            storage_snapshot_interval_sec=self._snapshot_interval_sec, bolt_port=self._port,
                            storage_properties_on_edges="true", memory_limit=self._memory_limit,
                            graph_operations=self._graph_operations,
                            storage_gc_cycle_sec=self._storage_gc_cycle_sec)
        else:
            self._start(db_recover_on_startup=True)

    def stop(self):
        ret, usage = self._cleanup()
        assert ret == 0, "The database process exited with a non-zero " \
                         "status ({})!".format(ret)
        return usage


class Client:
    def __init__(self, client_binary, temporary_directory, memgraph_port):
        self._client_binary = client_binary
        self._directory = temporary_directory
        self._port = memgraph_port

    def _get_args(self, **kwargs):
        return _convert_args_to_flags(self._client_binary, **kwargs)

    def execute(self, queries=None, file_path=None, num_workers=1):
        if (queries is None and file_path is None) or \
                (queries is not None and file_path is not None):
            raise ValueError("Either queries or input_path must be specified!")

        # TODO: check `file_path.endswith(".json")` to support advanced
        # input queries

        queries_json = False
        if queries is not None:
            queries_json = True
            file_path = queries
            with open(file_path, "w") as f:
                for query in queries:
                    print("query", query)

        args = self._get_args(input=file_path, num_workers=num_workers,
                              queries_json=queries_json, max_retries=10000, port=self._port)
        # print("args:",args)
        ret = subprocess.run(args, stdout=subprocess.PIPE, check=True)
        data = ret.stdout.decode("utf-8").strip().split("\n")
        lists = list()
        for key in data:
            if "[client.hpp" in key:
                continue
            if "Running a bolt client" in key or "[info] " in key:
                continue
            lists.append(json.loads(key))
        return lists
