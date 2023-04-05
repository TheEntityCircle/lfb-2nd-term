cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g") # стандарты можно и просто флагом, не только отдельной командой

project(gmshdemo)
add_executable(example_for_4.12.0 example_for_4.12.0.cpp)

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "???"
    INTERFACE_INCLUDE_DIRECTORIES "???"
)
set(GMSH_LIBRARY gmsh)

target_link_libraries(example_for_4.12.0 ${GMSH_LIBRARY})
