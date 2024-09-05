
set(DEP_SOURCES
    dependencyInjection/RealDep.cpp
)

add_executable(dependencyInjection ${DEP_SOURCES} main.cpp)

target_include_directories(dependencyInjection PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencyInjection 
    ${CMAKE_CURRENT_SOURCE_DIR}/Matcher 
    ${CMAKE_CURRENT_SOURCE_DIR}/nonVirualFuncMock
    ${CMAKE_CURRENT_SOURCE_DIR}/DelegatingCalls2RealObject
)

#
# unit test
#
include(${CUSTOM_CMAKE_DIR}/unit_test_helper.cmake)
enable_testing()

set(GTEST_LIB_DEP
    ${GTEST_LIB_DIR}/libgtest.a
    ${GTEST_LIB_DIR}/libgmock.a
    ${GTEST_LIB_DIR}/libgtest_main.a
    ${GTEST_LIB_DIR}/libgmock_main.a
)

# dependencyInjection_test
add_new_test(
    TEST_NAME
        dependencyInjection_test
    SRCS
        unitTest/dependencyInjection_test.cpp
    DEP_SRCS
        ${DEP_SOURCES}
    HEADER_DIR
        "${GTEST_HEADER_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencyInjection"
        "${CMAKE_CURRENT_SOURCE_DIR}/Matcher"
    LIB_DEP
        "${GTEST_LIB_DEP}"
)

target_compile_options(dependencyInjection_test PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
target_link_options(dependencyInjection_test PUBLIC -fprofile-arcs -ftest-coverage)

# nonVirualFuncMock_test
add_new_test(
    TEST_NAME
        nonVirualFuncMock_test
    SRCS
        unitTest/nonVirualFuncMock.cpp
    HEADER_DIR
        "${GTEST_HEADER_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/nonVirualFuncMock"
    LIB_DEP
        "${GTEST_LIB_DEP}"
)

target_compile_options(nonVirualFuncMock_test PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
target_link_options(nonVirualFuncMock_test PUBLIC -fprofile-arcs -ftest-coverage)

# DelegatingCalls2RealObject_test
add_new_test(
    TEST_NAME
        DelegatingCalls2RealObject_test
    SRCS
        unitTest/DelegatingCalls2RealObject_test.cpp
    HEADER_DIR
        "${GTEST_HEADER_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/DelegatingCalls2RealObject"
    LIB_DEP
        "${GTEST_LIB_DEP}"
)

target_compile_options(DelegatingCalls2RealObject_test PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
target_link_options(DelegatingCalls2RealObject_test PUBLIC -fprofile-arcs -ftest-coverage)

# matcher_test
add_new_test(
    TEST_NAME
        matcher_test
    SRCS
        unitTest/matcher_test.cpp
    HEADER_DIR
        "${GTEST_HEADER_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/Matcher"
    LIB_DEP
        "${GTEST_LIB_DEP}"
)

target_compile_options(matcher_test PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
target_link_options(matcher_test PUBLIC -fprofile-arcs -ftest-coverage)

# common
add_new_test(
    TEST_NAME
        common_test
    SRCS
        unitTest/common_test.cpp
    HEADER_DIR
        "${GTEST_HEADER_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/common"
    LIB_DEP
        "${GTEST_LIB_DEP}"
)

target_compile_options(common_test PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
target_link_options(common_test PUBLIC -fprofile-arcs -ftest-coverage)