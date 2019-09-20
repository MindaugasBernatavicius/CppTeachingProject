cmake_minimum_required(VERSION 3.14)
project(cpp_project)

#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
# Seems like CMAKE does not pass -trigraphs option, always shows :: warning: trigraph ??( ignored, use -trigraphs to enable [-Wtrigraphs]
# ... even though compiling  by hand: g++ --std=c++11 -trigraphs factorial.cpp -o fac.exe ... workfs fine
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11 -trigraphs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_CXX_STANDARD 11)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

#add_executable(cpp_project 1_simple_cli_apps/sleep_example_chrono.cpp)
add_executable(cpp_project 2_algorithms/bubble_sort.cpp)