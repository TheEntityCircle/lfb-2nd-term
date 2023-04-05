cmake_minimum_required(VERSION 2.8)	

project(space) # название проекта

set(SOURCE_EXE main.cpp) # список исходников для исполняемого файла

set(SOURCE_LIB goodbye.cpp anatoly.cpp cherdenko.cpp) # список исходников для библиотеки

add_library(gac SHARED ${SOURCE_LIB}) # создание статической библиотеки с именем gac

add_executable(main ${SOURCE_EXE}) # создание исполняемого файла с именем main

target_link_libraries(main gac)	# линковка программы с библиотекой
