cmake_minimum_required(VERSION 3.11-3.18)

project(gitrogsim)

add_library(MTGdeck STATIC
    deck.cpp    
)

target_include_directories(MTGdeck PRIVATE ../inc)

set_target_properties(MTGdeck PROPERTIES PUBLIC_HEADER ../inc/deck.hpp)

target_compile_features(MTGdeck PUBLIC cxx_std_20)

add_library(MTGdeckEx SHARED
    deck.cpp    
)

target_include_directories(MTGdeckEx PRIVATE ../inc)

set_target_properties(MTGdeckEx PROPERTIES PUBLIC_HEADER ../inc/deck.hpp)

target_compile_features(MTGdeckEx PUBLIC cxx_std_20)