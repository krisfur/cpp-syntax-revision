# The minimum version of CMake required to build this project.
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp_syntax_rev)

# Ensure up to date C++ version features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable target named "cpp_syntax_rev" from the source file "main.cpp".
# You also need to include "functions.cpp" to compile the things inside it
add_executable(cpp_syntax_rev main.cpp functions.cpp)