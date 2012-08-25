# @@@LICENSE
#
#      Copyright (c) 2007-2012 Hewlett-Packard Development Company, L.P.
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

project (PmLogLib C)
include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC3)
webos_component(2 1 0)

# Build the private interface to PmLogLib (PmLogLib-private)
# To enable this option run "cmake -D BUILD_PRIVATE=ON"
if(BUILD_PRIVATE)
	webos_build_pkgconfig(files/pkgconfig/PmLogLib-private)
	install(DIRECTORY "include/private/" DESTINATION @WEBOS_INSTALL_INCLUDEDIR@ FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
	return()
endif()

webos_build_pkgconfig(files/pkgconfig/PmLogLib)
include_directories(include/public include/private)

webos_add_compiler_flags(ALL -Wall)
webos_add_linker_options(ALL --version-script=${CMAKE_SOURCE_DIR}/src/PmLogLibExports.map)
webos_add_linker_options(ALL --no-undefined)

webos_configure_source_files(SOURCE_FILES src/PmLogLib.c)
add_library(PmLogLib SHARED ${SOURCE_FILES})
target_link_libraries(PmLogLib dl pthread)
webos_build_library()

webos_config_build_doxygen(doc Doxyfile)
