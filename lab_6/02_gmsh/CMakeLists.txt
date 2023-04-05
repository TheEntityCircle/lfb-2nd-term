cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g") # стандарты можно и просто флагом, не только отдельной командой

project(gmshdemo)
add_executable(basic_test_of_gmsh basic_test_of_gmsh.cpp)

add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libgmsh.so"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/include"
)
set(GMSH_LIBRARY gmsh)

target_link_libraries(basic_test_of_gmsh ${GMSH_LIBRARY})
