load("@rules_cc//cc:cc_binary.bzl", "cc_binary")
load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "config",
    hdrs = ["config/FreeRTOSConfig.h"],
    strip_include_prefix = "config/",
    include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [
        "main.c",
        "hooks.c",
    ],
    deps = [
        "//third_party:freertos",
    ],
    copts = [
        "-DprojCOVERAGE_TEST=0",
        "-DprojENABLE_TRACING=0",
    ],
)
