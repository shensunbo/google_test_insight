enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencyInjection ${CMAKE_CURRENT_SOURCE_DIR}/toolBox ${CMAKE_CURRENT_SOURCE_DIR}/nonVirualFuncMock)

set(DEP_SOURCES
    dependencyInjection/RealDep.cpp
)

add_executable(dependencyInjection ${DEP_SOURCES} main.cpp)


# unit test
set(GTEST_LIB_DEP
    ${GTEST_LIB_DIR}/libgtest.a
    ${GTEST_LIB_DIR}/libgmock.a
    ${GTEST_LIB_DIR}/libgtest_main.a
    ${GTEST_LIB_DIR}/libgmock_main.a
)

# dependencyInjection_test
add_executable(dependencyInjection_test unitTest/dependencyInjection_test.cpp ${DEP_SOURCES})
target_include_directories(dependencyInjection_test  PRIVATE "${GTEST_HEADER_DIR}")
target_link_libraries(dependencyInjection_test PRIVATE "${GTEST_LIB_DEP}")
set_target_properties(dependencyInjection_test PROPERTIES
    OUTPUT_NAME dependencyInjection_test
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
add_test(NAME dependencyInjection_test COMMAND ${CMAKE_BINARY_DIR}/bin/dependencyInjection_test)

# nonVirualFuncMock_test
add_executable(nonVirualFuncMock_test unitTest/nonVirualFuncMock.cpp ${DEP_SOURCES})
target_include_directories(nonVirualFuncMock_test  PRIVATE "${GTEST_HEADER_DIR}")
target_link_libraries(nonVirualFuncMock_test PRIVATE "${GTEST_LIB_DEP}")
set_target_properties(nonVirualFuncMock_test PROPERTIES
    OUTPUT_NAME nonVirualFuncMock_test
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
add_test(NAME nonVirualFuncMock_test COMMAND ${CMAKE_BINARY_DIR}/bin/nonVirualFuncMock_test)