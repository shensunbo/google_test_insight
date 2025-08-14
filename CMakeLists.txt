# check in-source build
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
        FATAL: In-source builds are not allowed.
            You should create a separate directory for build files.
        ")
endif()

cmake_minimum_required(VERSION 3.10)
project(gtest_insight)

set(GTEST_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GTEST_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest)

set(CUSTOM_CMAKE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

# gen coverage report
option(GEN_REPORT "gen coverage report" OFF)

add_subdirectory(src)
