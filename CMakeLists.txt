# @@@LICENSE
#
# Copyright (c) 2007-2014 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# LICENSE@@@

#
# PmLogLib/CMakeLists.txt
#

cmake_minimum_required (VERSION 2.8.7)

if(BUILD_PRIVATE)
	project(PmLogLib NONE)
else()
	project(PmLogLib C)
endif()

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC6)
webos_component(3 2 0)
webos_include_install_paths()

set(ENABLE_LOGGING TRUE CACHE BOOL "Enable logging")

if(ENABLE_LOGGING)
	set(PMLOG_ENABLE_LOGGING 1)
else()
	set(PMLOG_ENABLE_LOGGING 0)
endif()

# Build the private interface to PmLogLib (PmLogLib-private)
# To enable this option run "cmake -D BUILD_PRIVATE=ON"
if(BUILD_PRIVATE)
	webos_build_pkgconfig(files/pkgconfig/PmLogLib-private)
	install(DIRECTORY "include/private/" DESTINATION @WEBOS_INSTALL_INCLUDEDIR@ FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
	return()
endif()

# Install headers separately from the library. To enable this
# option, use "cmake -D SHIP_HEADERS_ONLY=ON". To avoid
# installing them again, use "cmake -D BUILD_WITHOUT_HEADERS=ON"
# in following builds.
if(NOT BUILD_WITHOUT_HEADERS)
	webos_build_pkgconfig(files/pkgconfig/PmLogLib-headers)
	webos_configure_header_files(include/public INSTALL)
	install(DIRECTORY "include/public/" DESTINATION @WEBOS_INSTALL_INCLUDEDIR@ FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
	if(SHIP_HEADERS_ONLY)
		return()
	endif()
endif()

include(FindPkgConfig)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS_OTHER})

pkg_check_modules(PBNJSON_C REQUIRED pbnjson_c)
include_directories(${PBNJSON_C_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${PBNJSON_C_CFLAGS_OTHER})

webos_build_pkgconfig(files/pkgconfig/PmLogLib)
include_directories(include/public include/private)

webos_add_compiler_flags(ALL --std=c99)
if(WEBOS_DISTRO_PRERELEASE STREQUAL "")
	webos_add_compiler_flags(ALL -Wall -DWEBOS_MASS_PRODUCTION)
else()
	webos_add_compiler_flags(ALL -Wall)
endif()

if(PARSE_DEFAULT_ONLY)
	pkg_check_modules(NYXLIB REQUIRED nyx)
	include_directories(${NYXLIB_INCLUDE_DIRS})
	webos_add_compiler_flags(ALL ${NYXLIB_CFLAGS_OTHER} -DPARSE_DEFAULT_ONLY)
endif()

webos_add_linker_options(ALL --version-script=${CMAKE_SOURCE_DIR}/src/PmLogLibExports.map)
webos_add_linker_options(ALL --no-undefined)

add_library(PmLogLib SHARED src/PmLogLib.c)

if(PARSE_DEFAULT_ONLY)
	target_link_libraries(PmLogLib ${GLIB2_LDFLAGS} ${PBNJSON_C_LDFLAGS} ${NYXLIB_LDFLAGS} dl pthread)
else()
	target_link_libraries(PmLogLib ${GLIB2_LDFLAGS} ${PBNJSON_C_LDFLAGS} dl pthread)
endif()

webos_build_library(NOHEADERS)

# Default config file for pmloglib
# Each component should provide its own config file
webos_build_configured_file(files/conf/pmlog/default.conf SYSCONFDIR pmlog.d)

webos_config_build_doxygen(doc Doxyfile)
