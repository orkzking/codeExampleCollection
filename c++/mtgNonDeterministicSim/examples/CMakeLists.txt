cmake_minimum_required(VERSION 3.11-3.18)

project(simpleGitrogCombo)

add_executable(simpleGitrogCombo simpleGitrogCombo.cpp)

target_include_directories(simpleGitrogCombo PUBLIC ../inc)

target_link_libraries(simpleGitrogCombo
    PUBLIC MTGdeck)

target_compile_features(simpleGitrogCombo PUBLIC cxx_std_20)

add_executable(simpleGitrogComboPar simpleGitrogCombo.cpp)

target_include_directories(simpleGitrogComboPar PUBLIC ../inc)

target_link_libraries(simpleGitrogComboPar
    PUBLIC MTGdeck)

if(OpenMP_CXX_FOUND)
    target_link_libraries(simpleGitrogComboPar PUBLIC OpenMP::OpenMP_CXX)
endif()

target_compile_features(simpleGitrogComboPar PUBLIC cxx_std_20)

add_executable(simpleRipple simpleRipple.cpp)

target_include_directories(simpleRipple PUBLIC ../inc)

target_link_libraries(simpleRipple
    PUBLIC MTGdeck)

target_compile_features(simpleRipple PUBLIC cxx_std_20)

add_executable(simpleRipplePar simpleRipple.cpp)

target_include_directories(simpleRipplePar PUBLIC ../inc)

target_link_libraries(simpleRipplePar
    PUBLIC MTGdeck)

if(OpenMP_CXX_FOUND)
    target_link_libraries(simpleRipplePar PUBLIC OpenMP::OpenMP_CXX)
endif()

target_compile_features(simpleRipplePar PUBLIC cxx_std_20)