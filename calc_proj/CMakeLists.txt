cmake_minimum_required(VERSION 3.10)
project(calculator C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(calculator src/calc.c)

add_executable(main src/main.c)
target_link_libraries(main calculator)

#add_executable(test_calculator tests/test_calc.c)
#target_link_libraries(test_calculator calculator)

