cmake_minimum_required(VERSION 3.10)
project(rpios C ASM)

# Set Makefile verbose off
set(CMAKE_VERBOSE_MAKEFILE false)

# Set crosscompiling variable to true.
SET(CMAKE_CROSSCOMPILING 1)

# Include headers files from "include/".
include_directories(include/)

# Include sources files from "src/".
file(GLOB_RECURSE SRC_FILES src/*) 

# Set target name, cflags and path of the linker script.
set(TARGET_NAME rpios)
set(CMAKE_C_FLAGS "-mcpu=cortex-a7 -O0")
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/ldscript/link.ld)

add_executable(${TARGET_NAME} ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS 
	"-nostartfiles -T ${LINKER_SCRIPT}")