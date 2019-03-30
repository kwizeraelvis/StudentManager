cmake_minimum_required(VERSION 2.8.9)

project(hello)

#Including Headers Defination Folder
include_directories(include)


#include Source Files
file(GLOB SOURCES "src/*.c")

add_executable(hello main.c ${SOURCES})
