# 🐀 C++ Syntax Revision

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white) [![C++](https://img.shields.io/badge/C++-17-blueviolet)](https://isocpp.org/)

Little syntax revision notes for C++17 and onwards syntax (auto, memory safe pointers, all that jazz).

# Prerequisites

- C++ compiler of sorts, on windows visual studio build tools provide a nice one, on mac `g++`, on linux `gcc`, or any other one you like
- `CMake`, which does all the heavy lifting and linking for us

# Setting up a project

Base setup requires a `main.cpp` as the core of the program, and a `CMakeLists.txt` that points to it, as well as allows for linking any other libraries.

Aftare that you need to:

1. Make a build directory
2. Navigate into it and run `cmake ..` to prepare build setup
3. Run `cmake --build .` to actually build the program
4. Call the executable `debug/cpp_syntax_rev`

# CMakeLists.txt setup

It is imperative to have these basics to allow for all core `std::` features needed in C++17:

```cmake
# The minimum version of CMake required to build this project.
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp_syntax_rev)

# Ensure up to date C++ version features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable target named "cpp_syntax_rev" from the source file "main.cpp".
add_executable(cpp_syntax_rev main.cpp functions.cpp)
```

> ⚠️ Remember to include all your .cpp files in add_executables

# Additional C++ code files

To put more code in other files you need to use `.hpp` header files, and `.cpp` code files. You `#include "file.hpp"` in both `main.cpp` and the definition `.cpp` file.

## `.hpp`

For regular functions just put definitions followed by semicolons. For `templates` include the full definition.

```cpp
#ifndef PROGRAMNAME_FILENAME_H
#define  PROGRAMNAME_FILENAME_H
int addition (int a, int b); //ended with a semicolon ; yuo only declare that the function exist

// --- Template function DEFINITION ---
// The entire template, including the body, goes in the header file.
template <typename T>
T addT(T a, T b) {
    return a + b;
}
#endif //PROGRAMNAME_FILENAME_H
```

## `.cpp`

Here include definitions of functions etc.

```cpp
#include "functions.hpp"
int addition (int a, int b){
		int r;
		r=a+b;
		return r;
	}
```

## Classes

`.hpp`

```cpp
#ifndef MYPROJECT_WIDGET_H
#define MYPROJECT_WIDGET_H

class Widget {
public:
    // Constructor declaration
    Widget(int initialValue); 

    // Member function declaration
    void printValue() const; 

    // Member function declaration
    void setValue(int newValue); 

private:
    // Member variable declaration
    int m_value; 
};

#endif //MYPROJECT_WIDGET_H
```

`.cpp`

```cpp
#include "Widget.hpp" // Include the header to connect the definition
#include <iostream>

// Use Widget:: to define the constructor
Widget::Widget(int initialValue) : m_value(initialValue) {
    // Constructor body (can be empty if using member initializer list)
}

// Use Widget:: to define the printValue member function
void Widget::printValue() const {
    std::cout << "Widget value is: " << m_value << std::endl;
}

// Use Widget:: to define the setValue member function
void Widget::setValue(int newValue) {
    m_value = newValue;
}
```