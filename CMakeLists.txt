cmake_minimum_required(VERSION 3.20)
project(MyCppProject VERSION 0.1.0 LANGUAGES CXX)

# Use the C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Locate dependencies from vcpkg
find_package(fmt CONFIG REQUIRED)
find_package(gtest CONFIG REQUIRED)

# 2. Define the executable target
add_executable(my_app src/main.cpp src/logic.cpp)

# 3. Include directories (the "src-layout" support)
target_include_directories(my_app PRIVATE include)

# 4. Link libraries
target_link_libraries(my_app PRIVATE fmt::fmt)

# 5. Enable Testing
enable_testing()
add_executable(run_tests tests/test_logic.cpp)
target_link_libraries(run_tests PRIVATE GTest::gtest_main)
add_test(NAME MyTests COMMAND run_tests)

# 6. Enable Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # Point to your Doxyfile or let CMake generate one
    doxygen_add_docs(docs src/ README.md)
endif()
