cmake_minimum_required(VERSION 4.0)
set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "")


# Project Metadata
project(CppProjectTemplate
    VERSION 0.1.0
    DESCRIPTION "A professional C++ template with vcpkg and GTest"
    LANGUAGES CXX
)

# 1. Use the C++20 standard configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Locate dependencies from vcpkg
find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(Doxygen)

# 3. Create the Core Logic Library
# add engine here so both app and tests can use it
add_library(project_logic STATIC 
    src/greeter.cpp
    # Add future logic files here
)
# define which headers the library needs
target_include_directories(project_logic PUBLIC include)
# link internal dependencies (PRIVATE keeps them from leaking)
target_link_libraries(project_logic PRIVATE fmt::fmt)

# 4. Define the executable target
add_executable(my_app src/main.cpp)
target_link_libraries(my_app PRIVATE project_logic)

# 3. Include directories (the "src-layout" support)
target_include_directories(my_app PUBLIC include)

# 5. Enable Testing Suite
if (BUILD_TESTING)
    enable_testing()

    add_executable(run_tests tests/test_greeter.cpp)
    target_link_libraries(run_tests
        PRIVATE
            project_logic
            GTest::gtest_main
    )
    add_test(NAME GreeterTests COMMAND run_tests)
endif()

# 6. Enable Doxygen
if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX NO)

    # Point to your Doxyfile or let CMake generate one
    doxygen_add_docs(docs
        src/
        include/
        README.md
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
    )
endif()
