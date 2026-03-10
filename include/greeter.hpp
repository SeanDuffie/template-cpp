#pragma once
#include <string>

class Greeter {
public:
    explicit Greeter(std::string name);
    void say_hello() const;
private:
    std::string name_;
};
