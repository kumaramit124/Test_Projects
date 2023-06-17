cmake_minimum_required(VERSION 3.10)
project(myproject)

# Add the math library
add_library(math_functions STATIC math_functions.c)
target_include_directories(math_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the string library
add_library(string_functions SHARED string_functions.c)
target_include_directories(string_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable and link with the libraries
add_executable(myprogram main.c)
target_link_libraries(myprogram math_functions string_functions)

