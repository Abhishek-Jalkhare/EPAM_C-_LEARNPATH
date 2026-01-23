
cmake_minimum_required(VERSION 4.1)
project(CppLearning)

set(CMAKE_CXX_STANDARD 20)

add_executable(main basics/main.cpp)
add_executable(arrays Module1/pointers,Arrays,basics/arrays.cpp
        Module1/File_Managment/Task3/task3.cpp
        Module1/pointers,Arrays,basics/structures.c
        Module1/File_Managment/Task_5/file_management_task_5.cpp
        Module1/preproccesor_directives/main.cpp
        Module1/preproccesor_directives/test.cpp)
add_executable(arrays_with_functions Module1/pointers,Arrays,basics/arrays_with_functions.cpp)
add_executable(functions Module1/pointers,Arrays,basics/functions.cpp)
add_executable(grade_checker Module1/pointers,Arrays,basics/grade_checker.cpp)
add_executable(matrix Module1/pointers,Arrays,basics/matrix.cpp)
add_executable(pointer_task_3 Module1/pointers,Arrays,basics/pointer_task_3.cpp)
add_executable(pointers Module1/pointers,Arrays,basics/pointers.cpp)
add_executable(pointer_task2 Module1/pointers,Arrays,basics/pointer_task2.c)
add_executable(reccursive_directory_traversal Module1/pointers,Arrays,basics/reccursive_directory_traversal.cpp)
add_executable(reverse Module1/pointers,Arrays,basics/reverse.cpp)
add_executable(search Module1/pointers,Arrays,basics/search.cpp)
add_executable(sorting Module1/pointers,Arrays,basics/sorting.cpp)
add_executable(stair_case Module1/pointers,Arrays,basics/stair_case.cpp)
add_executable(taylor Module1/pointers,Arrays,basics/taylor.cpp)
add_executable(twod_arrays Module1/pointers,Arrays,basics/twod_arrays.cpp)
