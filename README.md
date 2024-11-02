# Test Projects

This repository contains multiple projects that demonstrate fundamental software development concepts such as project directory structuring, build environment setup using Makefiles and CMake, dynamic and static library linking, bit manipulation, and filesystem monitoring. Each project serves as a proof of concept for various techniques and can be built with either Make or CMake.

---

## Project Overview

### 1. **Test_Projects**
   - Demonstrates the creation of a structured project environment.
   - Explores building both static and dynamic libraries and linking them to programs.
   - Serves as a foundation for creating modular codebases that can be scaled.

### 2. **BitOpr (Bit Operations)**
   - Focuses on bit manipulation APIs, aimed at supporting a variety of bit-level operations.
   - Provides functions for setting, getting, finding, toggling, reversing, and shifting bits.
   - Designed as an open library for use in other software projects requiring efficient bit-level operations.
   - Example functions include:
     - **Set/Get**: Set or get a bit at a specified position.
     - **Toggle**: Toggle specific bits.
     - **Reverse**: Reverse bits in a given sequence.
     - **Shift**: Shift bits left or right.

### 3. **Calc Proj (Calculator Project)**
   - Demonstrates basic library creation by building a simple calculator.
   - Includes both static and dynamic library builds, exposing essential calculator functions for third-party usage.
   - Provides functions for basic arithmetic operations such as addition, subtraction, multiplication, and division.

### 4. **Calc Proj1 (Calculator Project with CMake)**
   - A CMake-based version of the calculator project.
   - Shows how to set up CMake for library creation and linking.
   - Enables the project to be built across multiple platforms with CMake’s portability.

### 5. **dirMon Project (Directory Monitoring)**
   - A more advanced project focusing on monitoring changes in a specific directory path.
   - Detects changes such as file modifications and additions in real-time.
   - Provides automated backup functionality when changes are detected and resumes monitoring for future changes.
   - Useful for applications needing automated tracking and backup for filesystem modifications.

---

## Building the Projects

Each project can be built using either **Make** or **CMake**.

### Using Make
```bash
# Navigate to the project directory.
make         # to build the project
make clean   # to clean the build artifacts

### Using CMake
mkdir build && cd build  # create a build directory
cmake ..                 # configure the project
make                     # build the project


