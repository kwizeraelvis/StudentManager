cmake_minimum_required(VERSION 2.8.9)
project(StudentManager)


include(FindPkgConfig)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(JSONC REQUIRED json-c)

include_directories(${GLIB_INCLUDE_DIRS})
include_directories(${GTK_INCLUDE_DIRS})
include_directories(${JSONC_INCLUDE_DIRS})
include_directories(include)

link_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
link_directories(${JSONC_LIBRARY_DIRS})

file(GLOB SOURCES "src/*.c")


add_definitions(${GTK_CFLAGS_OTHER})

add_executable(StudentManager main.c ${SOURCES})

target_link_libraries(StudentManager ${GTK_LIBRARIES} ${GLIB_LIBRARIES} ${JSONC_LIBRARIES})
