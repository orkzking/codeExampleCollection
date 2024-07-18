cmake_minimum_required(VERSION 3.11-3.18)

# add_library(cppcmaketemplate SHARED card.cc data.cc list.cc scry-private.cc scry-public.cc web.cc)
add_executable(cppcmaketemplate main.cpp League.cpp)

target_include_directories(cppcmaketemplate PUBLIC ../inc)

target_compile_features(cppcmaketemplate PUBLIC cxx_std_20)