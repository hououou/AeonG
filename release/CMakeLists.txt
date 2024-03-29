# Install systemd service (must use absolute path).
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/memgraph.service
        DESTINATION /lib/systemd/system)

# ---- Setup CPack --------

# General setup
set(CPACK_PACKAGE_NAME memgraph)
set(CPACK_PACKAGE_VENDOR "Memgraph Ltd.")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "High performance, in-memory, transactional graph database")

# DEB specific
# Instead of using "name <email>" format, we use "email (name)" to prevent
# errors due to full stop, '.' at the end of "Ltd". (See: RFC 822)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "tech@memgraph.com (Memgraph Ltd.)")
set(CPACK_DEBIAN_PACKAGE_SECTION non-free/database)
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE https://memgraph.com)
set(CPACK_DEBIAN_PACKAGE_VERSION "${MEMGRAPH_VERSION_DEB}")
set(CPACK_DEBIAN_FILE_NAME "memgraph_${MEMGRAPH_VERSION_DEB}_amd64.deb")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/conffiles;"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/copyright;"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/preinst;"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/prerm;"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/postrm;"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/postinst;")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
# Description formatting is important, summary must be followed with a newline and 1 space.
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "${CPACK_PACKAGE_DESCRIPTION_SUMMARY}
 Contains Memgraph, the graph database. It aims to deliver developers the
 speed, simplicity and scale required to build the next generation of
 applications driver by real-time connected data.")
# Add `openssl` package to dependencies list. Used to generate SSL certificates.
# We also depend on `python3` because we embed it in Memgraph.
set(CPACK_DEBIAN_PACKAGE_DEPENDS "openssl (>= 1.1.0), python3 (>= 3.5.0)")

# RPM specific

set(MG_ARCH_EXTENSION "noarch")

if (${MG_ARCH} STREQUAL "x86_64")
    set(MG_ARCH_EXTENSION "x86_64")
elseif (${MG_ARCH} STREQUAL "ARM64")
    set(MG_ARCH_EXTENSION  "aarch64")
endif()

set(CPACK_RPM_PACKAGE_URL https://memgraph.com)
set(CPACK_RPM_PACKAGE_VERSION "${MEMGRAPH_VERSION_RPM}")
set(CPACK_RPM_FILE_NAME "memgraph-${MEMGRAPH_VERSION_RPM}-1.${MG_ARCH_EXTENSION}.rpm")
set(CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION
  /var /var/lib /var/log /etc/logrotate.d
  /lib /lib/systemd /lib/systemd/system /lib/systemd/system/memgraph.service)
set(CPACK_RPM_PACKAGE_REQUIRES_PRE "shadow-utils")
set(CPACK_RPM_USER_BINARY_SPECFILE "${CMAKE_CURRENT_SOURCE_DIR}/rpm/memgraph.spec.in")
set(CPACK_RPM_PACKAGE_LICENSE "Memgraph License")
# Description formatting is important, no line must be greater than 80 characters.
set(CPACK_RPM_PACKAGE_DESCRIPTION "Contains Memgraph, the graph database.
It aims to deliver developers the speed, simplicity and scale required to build
the next generation of applications driver by real-time connected data.")
# Add `openssl` package to dependencies list. Used to generate SSL certificates.
# We also depend on `python3` because we embed it in Memgraph.
set(CPACK_RPM_PACKAGE_REQUIRES "openssl >= 1.0.0, curl >= 7.29.0, python3 >= 3.5.0")

# All variables must be set before including.
include(CPack)
