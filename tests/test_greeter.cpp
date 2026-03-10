#include <gtest/gtest.h>
#include "greeter.hpp"

// Test case for initialization
TEST(GreeterTest, Initialization) {
    // We verify the object can be created without crashing
    Greeter g("Tester");
    SUCCEED(); 
}

// Professional Tip: To test "say_hello", you would normally 
// refactor the class to return a std::string so you can assert:
// EXPECT_EQ(g.get_greeting(), "Hello, Tester!");
