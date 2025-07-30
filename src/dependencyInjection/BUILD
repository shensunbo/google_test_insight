cc_library(
    name = "dependencyInjection",
    hdrs = [
        "BaseDep.h",
        "BeTested.h",
        "MockDep.h",
        "RealDep.h",
    ],
    srcs = [
        "RealDep.cpp"
    ],
    includes = ["."],
    deps = [
        "//src/Matcher:Matcher"
    ],
    visibility = [
        "//visibility:public"
    ],
)