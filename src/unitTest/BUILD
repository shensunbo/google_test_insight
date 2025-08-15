cc_test(
    name = "nonVirualFuncMock_test",
    srcs = ["nonVirualFuncMock.cpp"],
    deps = [
        "//src/nonVirualFuncMock:PacketStream",
        "//:gtest"
    ]
)

cc_test(
    name = "common_test",
    srcs = ["common_test.cpp"],
    deps = [
        "//src/common:common",
        "//:gtest"
    ]
)

cc_test(
    name = "DelegatingCalls2RealObject_test",
    srcs = ["DelegatingCalls2RealObject_test.cpp"],
    deps = [
        "//src/DelegatingCalls2RealObject:DelegatingCalls2RealObject",
        "//:gtest"
    ]
)

cc_test(
    name = "dependencyInjection_test",
    srcs = ["dependencyInjection_test.cpp"],
    deps = [
        "//src/dependencyInjection:dependencyInjection",
        "//:gtest"
    ]
)

cc_test(
    name = "matcher_test",
    srcs = ["matcher_test.cpp"],
    deps = [
        "//src/Matcher:Matcher",
        "//:gtest"
    ]
)

cc_test(
    name = "param_test",
    size = "small",
    srcs = ["param_test.cpp"],
    deps = [
        "//src/dependencyInjection:dependencyInjection",
        "//:gtest"
    ]
)

cc_test(
    name = "expect_that_test",
    size = "small",
    srcs = ["expect_that_test.cpp"],
    deps = [
        "//:gtest"
    ]
)