project(aphos C ASM)
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME aphOS)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_REV 1)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REV})

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
 message(FATAL_ERROR "In-source builds are not allowed as it clutters the source directory.
Please create a directory and run cmake from there
This process created 'CMakeFiles' and 'CMakeCache.txt', please delete them.")
endif()

cmake_policy(VERSION 2.8.2)

set(APHOS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(APHOS_MAIN_INCLUDE_DIR ${APHOS_SRC_DIR}/include)
set(APHOS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${APHOS_BINARY_DIR}/bin)

configure_file(
	${CMAKE_SOURCE_DIR}/src/kernel/config.h.in
	${CMAKE_BINARY_DIR}/src/kernel/config.h
	)

include_directories(
	${CMAKE_BINARY_DIR}/src/kernel
	)

add_subdirectory(src)

add_custom_target(run COMMAND qemu-system-i386 -kernel ${CMAKE_CURRENT_BINARY_DIR}/bin/aphos)