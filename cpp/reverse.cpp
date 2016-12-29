// To run the program, try the command below:
// g++ reverse.cpp -lgtest_main -lgtest

// reverses a string

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

void reverse(char *statement) {
    if (statement == NULL) return;

    char tmp;
    char *end = statement;
    while (*end) {
        ++end;
    }
    --end; // the last character of statement is NULL character

    while (statement<end) {
        tmp  = *statement;
        *statement = *end;
        *end = tmp;
        statement++;
        end--;
    }
}

// Tests positive input.
TEST(reverse, Simple) {
    char char_array[4] = {'a','b','c','d'};
    char reverse_char_array[4] = {'d','c','b','a'};
    reverse(char_array);
   EXPECT_EQ(*reverse_char_array, *char_array);
}

