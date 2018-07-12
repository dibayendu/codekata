// To run the program, try the command below:
// g++ recursion.cpp -lgtest_main -lgtest

// some algorithms using recursion

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

int fibonacci (int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n > 1) {
        return fibonacci(n-1) + fibonacci(n-2);
    } else {
        return -1; // error case
    }
}

TEST(fibonacci, FibonacciSeries) {
    EXPECT_EQ(-1, fibonacci(-1));
    EXPECT_EQ(-1, fibonacci(-45));
    EXPECT_EQ(0, fibonacci(0));
    EXPECT_EQ(1, fibonacci(1));
    EXPECT_EQ(1, fibonacci(2));
    EXPECT_EQ(2, fibonacci(3));
    EXPECT_EQ(3, fibonacci(4));
    EXPECT_EQ(5, fibonacci(5));
    EXPECT_EQ(8, fibonacci(6));
    EXPECT_EQ(144, fibonacci(12));
}

