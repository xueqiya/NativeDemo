cmake_minimum_required(VERSION 3.10.2)

project("nativedemo")

add_library(
        native-lib
        SHARED
        native-lib.cpp)

find_library(
        log-lib
        log)

target_link_libraries( # Specifies the target library.
        native-lib

        ${log-lib})