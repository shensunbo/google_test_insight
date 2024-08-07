
# add_new_test()
#
# add a new test case
#
# Parameters:
#   [REQ] TEST_NAME - The name of the test
#   [REQ] SRCS - The sources file for the test
#   [OPT] DEP_SRCS - The dependent sources files for the test (default: "")
#   [OPT] HEADER_DIR - The header directory for the test (default: "")
#   [OPT] LIB_DEP - The library dependency for the test (default: "")
#
# Usage:
#   add_new_test(
#       TEST_NAME
#           new_test
#       SRCS
#           unitTest/DelegatingCalls2RealObject_test.cpp   
#       DEP_SRCS
#           "dep.cpp"
#       HEADER_DIR
#           "${GTEST_HEADER_DIR}"
#       LIB_DEP
#           "${GTEST_LIB_DEP}"
#   )

function(add_new_test)
    set(options "")
    set(oneValueArgs "TEST_NAME;SRCS")
    set(multiValueArgs "DEP_SRCS;HEADER_DIR;LIB_DEP")
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # check input
    if(NOT ARG_TEST_NAME)
        message(FATAL_ERROR "TEST_NAME is required")
    endif()

    if(NOT ARG_SRCS)
        message(FATAL_ERROR "SRCS is required")
    endif()

    if(NOT ARG_DEP_SRCS)
        set(ARG_DEP_SRCS "")
    endif()

    if(NOT ARG_HEADER_DIR)
        set(ARG_HEADER_DIR "")
    endif()

    if(NOT ARG_LIB_DEP)
        set(ARG_LIB_DEP "")
    endif()

    # create test
    add_executable(${ARG_TEST_NAME} ${ARG_SRCS} ${ARG_DEP_SRCS})

    if(ARG_HEADER_DIR)
        target_include_directories(${ARG_TEST_NAME} PRIVATE "${ARG_HEADER_DIR}")
    endif()

    if(ARG_LIB_DEP)
        target_link_libraries(${ARG_TEST_NAME} PRIVATE "${ARG_LIB_DEP}")
    endif()

    set_target_properties(${ARG_TEST_NAME} PROPERTIES
        OUTPUT_NAME ${ARG_TEST_NAME}
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )

    add_test(NAME ${ARG_TEST_NAME} COMMAND ${CMAKE_BINARY_DIR}/bin/${ARG_TEST_NAME})
endfunction()

#
# old style add test
#
## dependencyInjection_test
#add_executable(dependencyInjection_test unitTest/dependencyInjection_test.cpp ${DEP_SOURCES})
#target_include_directories(dependencyInjection_test  PRIVATE "${GTEST_HEADER_DIR}")
#target_link_libraries(dependencyInjection_test PRIVATE "${GTEST_LIB_DEP}")
#set_target_properties(dependencyInjection_test PROPERTIES
#    OUTPUT_NAME dependencyInjection_test
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#)
#add_test(NAME dependencyInjection_test COMMAND ${CMAKE_BINARY_DIR}/bin/dependencyInjection_test)