cmake_minimum_required(VERSION 3.11-3.18)

project(
    gitrogsim
    VERSION 1.0
    DESCRIPTION "tool to simulate gitrog dredge combos"
)

find_package(OpenMP)

add_subdirectory(src)
add_subdirectory(examples)