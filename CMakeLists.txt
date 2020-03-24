cmake_minimum_required(VERSION 3.10)
project(rpios C ASM)

#set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

include_directories(include/)

# Include sources files
file(GLOB_RECURSE SRC_FILES src/*) 

set(TARGET_NAME rpios)
set(CMAKE_C_FLAGS "-mcpu=cortex-a7 -O0")
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/ldscripts/link.ld)

add_executable(${TARGET_NAME} ${SRC_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS 
	"-nostartfiles -T ${LINKER_SCRIPT}")
