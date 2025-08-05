# 🐀 C++ Syntax Revision

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white) [![C++](https://img.shields.io/badge/C++-17-blueviolet)](https://isocpp.org/)

Little syntax revision notes for C++17 and onwards syntax (auto, memory safe pointers, all that jazz).

# Setting up a project

Base setup requires a `main.cpp` as the core of the program, and a `CMakeLists.txt` that points to it, as well as allows for linking any other libraries.

Aftare that you need to:

1. Make a build directory
2. Navigate into it and run `cmake ..` to prepare build setup
3. Run `cmake --build .` to actually build the program
4. Call the executable `debug/cpp_syntax_rev`

# CMakeLists.txt setup

It is imperative to have these basics to allow for all core `std::` features needed in C++17:

```txt
# The minimum version of CMake required to build this project.
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp_syntax_rev)

# Ensure up to date C++ version features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable target named "cpp_syntax_rev" from the source file "main.cpp".
add_executable(cpp_syntax_rev main.cpp)
```