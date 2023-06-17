cmake_minimum_required(VERSION 3.10)
project(FileMonitor C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(file_monitor src/main.c src/create_bkp.c)

