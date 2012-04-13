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

cmake_minimum_required (VERSION 2.6)

project (PmLogLib)

set (PMLOGLIB_API_VERSION_MAJOR 2)
set (PMLOGLIB_API_VERSION_MINOR 0)
set (PMLOGLIB_API_VERSION_PATCH 0)
set (PMLOGLIB_LIBRARY_VERSION "${PMLOGLIB_API_VERSION_MAJOR}.${PMLOGLIB_API_VERSION_MINOR}.${PMLOGLIB_API_VERSION_PATCH}")
set (PMLOGLIB_LIBRARY_NAME "${CMAKE_PROJECT_NAME}")
set (PMLOGLIB_PRIVATE_NAME "${CMAKE_PROJECT_NAME}-private")

# Make sure the build system's version of this component matches what we're building.
# The intent is for it to pass in PMLOGLIB_COMPONENT_VERSION via the command line.
if (DEFINED PMLOGLIB_COMPONENT_VERSION)
	if (NOT (PMLOGLIB_LIBRARY_VERSION STREQUAL PMLOGLIB_COMPONENT_VERSION))
		message(FATAL_ERROR "Component version from build system (${PMLOGLIB_COMPONENT_VERSION}) != configured version (${PMLOGLIB_LIBRARY_VERSION})")
	endif ()
endif ()

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Release")
endif ()

message ("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message ("CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
message ("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# Build the private interface to PmLogLib (PmLogLib-private)
# To enable this option run "cmake -D BUILD_PRIVATE=ON"
if (BUILD_PRIVATE)
	configure_file (${PROJECT_SOURCE_DIR}/config/${PMLOGLIB_PRIVATE_NAME}.pc.in
			${PROJECT_BINARY_DIR}/config/${PMLOGLIB_PRIVATE_NAME}.pc @ONLY)
	install (DIRECTORY "include/${PMLOGLIB_PRIVATE_NAME}" DESTINATION "include/" FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
	install (FILES "${PROJECT_BINARY_DIR}/config/${PMLOGLIB_PRIVATE_NAME}.pc" DESTINATION "lib/pkgconfig")
	return ()
endif ()

configure_file (${PROJECT_SOURCE_DIR}/config/${PMLOGLIB_LIBRARY_NAME}.pc.in
		${PROJECT_BINARY_DIR}/config/${PMLOGLIB_LIBRARY_NAME}.pc @ONLY)
configure_file (${PROJECT_SOURCE_DIR}/doc/Doxyfile.in
		${PROJECT_BINARY_DIR}/doc/Doxyfile)


include_directories ("${PROJECT_SOURCE_DIR}/include/${PMLOGLIB_LIBRARY_NAME}")
include_directories ("${PROJECT_SOURCE_DIR}/include/${PMLOGLIB_PRIVATE_NAME}")

macro (add_flags flags)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flags}")
endmacro ()

macro (add_linker_flags flags)
	# Appending to CMAKE_EXE_LINKER_FLAGS fails to add them to the link command line -- why?
	# Note that using add_definitions() also fails to add to the link command line
	add_flags ("${flags}")
endmacro ()


# We use <stdint.h>
add_definitions ("-std=c99")

# Turn on all warnings and make them into errors
add_definitions ("-Wall -Werror")

# Specify which symbols are to be exported
add_linker_flags ("-Wl,--version-script=${PROJECT_SOURCE_DIR}/src/${PMLOGLIB_LIBRARY_NAME}Exports.map")

# Require that all undefined symbols are satisfied by the libraries from target_link_libraries()
add_linker_flags ("-Wl,--no-undefined")
# XXX_ The libraries that come with gcc fail when --no-allow-shlib-undefined is specified
#add_linker_flags ("-Wl,--no-allow-shlib-undefined")


add_library (${PMLOGLIB_LIBRARY_NAME}
	SHARED
	src/PmLogLib.c
)

# NB. pthread supplies the sem_*() routines
target_link_libraries (${PMLOGLIB_LIBRARY_NAME}
	dl
	pthread
)

set_target_properties (${PMLOGLIB_LIBRARY_NAME} PROPERTIES VERSION ${PMLOGLIB_LIBRARY_VERSION} SOVERSION ${PMLOGLIB_API_VERSION_MAJOR})

install (DIRECTORY "include/${PMLOGLIB_LIBRARY_NAME}" DESTINATION "include/" FILES_MATCHING PATTERN "*.h" PATTERN ".*" EXCLUDE)
install (TARGETS "${PMLOGLIB_LIBRARY_NAME}" LIBRARY DESTINATION "lib${LIB_SUFFIX}/")
install (FILES "${PROJECT_BINARY_DIR}/config/${PMLOGLIB_LIBRARY_NAME}.pc" DESTINATION "lib/pkgconfig")


# This adds a target called "docs" (i.e., make docs). doxygen and dot
# (from graphviz) are expected to be available.
# ${PROJECT_BINARY_DIR} is the build directory and ${PROJECT_SOURCE_DIR}
# is the source directory.
add_custom_target (docs 
			doxygen ${PROJECT_BINARY_DIR}/doc/Doxyfile
			SOURCES ${PROJECT_SOURCE_DIR}/doc/Doxyfile.in
			WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/doc)

