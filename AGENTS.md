# CppLearning Project Guide for AI Agents

## Project Overview
This is a C++ learning repository structured into modules covering language concepts from basics to advanced topics. Each module contains subdirectories for specific topics, with individual task files demonstrating concepts.

**Key Structure:**
- Modules 1-9: Progressive learning from variables/arrays to multithreading
- STL: Standard Template Library examples
- OOP: Object-oriented programming concepts
- MeetingTask: Miscellaneous tasks

## Build System
Uses CMake with Ninja generator. Build directory: `cmake-build-debug/`.

**Build Commands:**
```bash
cd cmake-build-debug
cmake ..
ninja
```

Each task compiles to a separate executable named `Module{X}_{Topic}_Task{Y}` (e.g., `Module1_Arrays_Task1`).

## Code Organization
- Root `CMakeLists.txt` adds all module subdirectories
- Each module has its own `CMakeLists.txt` adding topic subdirectories
- Topic directories contain `CMakeLists.txt` defining executables for each `Task*.cpp`

**Example:** `Module1/Arrays/CMakeLists.txt` defines 5 executables from Task1.cpp to Task5.cpp.

## Naming Conventions
- Executables: `Module{number}_{TopicName}_Task{number}` (e.g., `Module9_MultiThreading_Synchronisation_Task1`)
- Files: `Task{number}.cpp` within topic directories
- Topics use underscores for multi-word names (e.g., `File_Managment`, `prinf_scanf_formatspecifier`)

## Common Patterns
- Includes: `<iostream>` and `<bits/stdc++.h>` (non-standard convenience header)
- Namespace: `using namespace std;`
- Memory: Dynamic allocation with `new[]`/`delete[]` for arrays
- Multithreading: `std::thread`, `std::vector<thread>`, join in loop
- Functions: Declared before `main`, defined after

**Example Thread Usage:**
```cpp
vector<thread> vec;
for (int i = 0; i < 10; i++) {
    vec.emplace_back(printMessage, "Msg from thread " + to_string(i+1));
}
for (auto& i : vec) i.join();
```

## Dependencies
- C++20 standard
- Standard library only (no external dependencies)
- Compiler: MinGW g++ (via CLion)

## Workflows
- Add new tasks: Create `Task{N}.cpp` in topic directory, update `CMakeLists.txt` with `add_executable`
- Run specific task: `./Module{X}_{Topic}_Task{Y}` from build directory
- Debug: Use CLion or gdb on executables</content>
<parameter name="filePath">C:\CPP_DEV\AGENTS.md
