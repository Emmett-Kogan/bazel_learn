load("@rules_cc//cc:cc_library.bzl", "cc_library")
# load("//:rules.bzl", "heap1", "heap2", "heap3", "heap4", "heap5")

config_setting(
    name = "heap1",
    values = {"define": "heap=1"},
)

config_setting(
    name = "heap2",
    values = {"define": "heap=2"},
)

config_setting(
    name = "heap3",
    values = {"define": "heap=3"},
)

config_setting(
    name = "heap4",
    values = {"define": "heap=4"},
)

config_setting(
    name = "heap5",
    values = {"define": "heap=5"},
)

cc_library(
    name = "freertos_hdrs",
    hdrs = glob(["FreeRTOS/include/*.h"]),
    strip_include_prefix = "FreeRTOS/include/",
    include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "freertos_port_hdrs",
    hdrs = select({
        "//conditions:default": [
            "FreeRTOS/portable/ThirdParty/GCC/Posix/portmacro.h",
            "FreeRTOS/portable/ThirdParty/GCC/Posix/utils/wait_for_event.h",
        ],
    }),
    strip_include_prefix = select({
        "//conditions:default": "FreeRTOS/portable/ThirdParty/GCC/Posix/",
    }),
    include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "freertos",
    srcs = glob([
        "FreeRTOS/*.c",
    ]) + select({
        ":heap1": ["FreeRTOS/portable/MemMang/heap_1.c"],
        ":heap2": ["FreeRTOS/portable/MemMang/heap_2.c"],
        ":heap3": ["FreeRTOS/portable/MemMang/heap_3.c"],
        ":heap4": ["FreeRTOS/portable/MemMang/heap_4.c"],
        ":heap5": ["FreeRTOS/portable/MemMang/heap_5.c"],
        "//conditions:default": [],
    }) + select({
        "//conditions:default": glob([
            "FreeRTOS/portable/ThirdParty/GCC/Posix/*.c",
            "FreeRTOS/portable/ThirdParty/GCC/Posix/utils/*.c",
        ]),
    }),
    deps = [
        ":freertos_hdrs",
        ":freertos_port_hdrs",
    ] + select({
        "//conditions:default": ["//rtos_app:config"],
    }),
    copts = [
        "-DprojCOVERAGE_TEST=0",
        "-DprojENABLE_TRACING=0",
    ],
    visibility = ["//visibility:public"],
)

# filegroup(
#     name = "freertos_srcs",
#     srcs = glob([
#         "FreeRTOS/*.c",
#     ]),
# )

# cc_library(
#     name = "freertos",
#     srcs = [":freertos_srcs"],
#     hdrs = [":freertos_hdrs"],
#     includes = [
#         "FreeRTOS/include/",
#     ],
#     deps = select({
#         "//conditions:default": ["//rtos_app/config:config"],
#     }),
#     include_prefix = "",
#     visibility = ["//visibility:public"],
# )