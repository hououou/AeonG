find_package(gflags REQUIRED)
find_package(BZip2 REQUIRED)
find_package(ZLIB REQUIRED)

# STATIC library used to store key-value pairs
add_library(mg-kvstore STATIC kvstore.cpp)
target_link_libraries(mg-kvstore stdc++fs mg-utils rocksdb BZip2::BZip2 ZLIB::ZLIB gflags)

# STATIC library for dummy key-value storage
# add_library(mg-kvstore-dummy STATIC kvstore_dummy.cpp)
# target_link_libraries(mg-kvstore-dummy mg-utils)

include_directories(/usr/local/include/aws)
link_directories(/usr/local/lib64)

add_library(rocksdb_cloud_static_lib STATIC IMPORTED)
set_property(TARGET rocksdb_cloud_static_lib PROPERTY IMPORTED_LOCATION "/home/aeong/libs/rocksdb-cloud/librocksdb.a")

# add_definitions(-DUSE_AWS=1)
include_directories("/home/aeong/libs/rocksdb-cloud/include")

add_executable(cloud_durable_example rocksdb_cloud_durable_example.cpp)
target_link_libraries(cloud_durable_example rocksdb aws-cpp-sdk-core aws-cpp-sdk-s3)
