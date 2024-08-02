cmake_minimum_required(VERSION 3.10)
project(gtest_insight)

set(GTEST_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GTEST_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest)

add_subdirectory(src)
