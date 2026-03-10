#include "greeter.hpp"
#include <iostream>
#include <fmt/core.h> // Using fmt library from vcpkg

Greeter::Greeter(std::string name) : name_(std::move(name)) {}

void Greeter::say_hello() const {
    // Using a modern library to prove vcpkg integration
    fmt::print("Hello, {}! Welcome to the professional C++ template.\n", name_);
}
