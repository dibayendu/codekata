// To run the program, try the command below:
// g++ unique_characters.cpp -lgtest_main -lgtest

// checks whether string has all unique characters

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

bool hasUniqueCharacters(const char* string) {
    if (string == NULL) return false;

    int size = strlen(string);
    for (int i=1; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (string[i] == string[j]) return false;
        }
    }

    return true;
}

bool hasUniqueCharacters2(const char* string) {
    if (string == NULL) return false;

    bool char_set[256];
    for (int i=0; i<256; i++) {
        char_set[i] = false;
    }

    int size = strlen(string);
    for (int i=0; i<size; i++) {
        int value = string[i];
        if (char_set[value] == true) return false;
        char_set[value] = true;
    }

    return true;
}

bool hasUniqueCharacters3(const char* string) {
    if (string == NULL) return false;

    int checker = 0;
    int size = strlen(string);
    for (int i=0; i<size; ++i) {
        int value = string[i] - 'a';
        if ((checker & (1 << value)) > 0) return false;
        checker |= (1 << value);
    }

    return true;
}

// Tests non unique characters string input.
TEST(hasUniqueCharacters, NonUniqueCharacters) {
  EXPECT_FALSE(hasUniqueCharacters("apple"));
  EXPECT_FALSE(hasUniqueCharacters("abcdd"));
  EXPECT_FALSE(hasUniqueCharacters("aabcd"));
  EXPECT_FALSE(hasUniqueCharacters("aabcddd"));
  EXPECT_FALSE(hasUniqueCharacters("aabbbcccddd"));
}

// Tests unique characters string input.
TEST(hasUniqueCharacters, UniqueCharacters) {
  EXPECT_TRUE(hasUniqueCharacters("mango"));
  EXPECT_TRUE(hasUniqueCharacters("abcd"));
}

// Tests non unique characters string input.
TEST(hasUniqueCharacters2, NonUniqueCharacters) {
  EXPECT_FALSE(hasUniqueCharacters2("apple"));
  EXPECT_FALSE(hasUniqueCharacters2("abcdd"));
  EXPECT_FALSE(hasUniqueCharacters2("aabcd"));
  EXPECT_FALSE(hasUniqueCharacters2("aabcddd"));
  EXPECT_FALSE(hasUniqueCharacters2("aabbbcccddd"));
}

// Tests unique characters string input.
TEST(hasUniqueCharacters2, UniqueCharacters) {
  EXPECT_TRUE(hasUniqueCharacters2("mango"));
  EXPECT_TRUE(hasUniqueCharacters2("abcd"));
}

// Tests non unique characters string input.
TEST(hasUniqueCharacters3, NonUniqueCharacters) {
  EXPECT_FALSE(hasUniqueCharacters3("apple"));
  EXPECT_FALSE(hasUniqueCharacters3("abcdd"));
  EXPECT_FALSE(hasUniqueCharacters3("aabcd"));
  EXPECT_FALSE(hasUniqueCharacters3("aabcddd"));
  EXPECT_FALSE(hasUniqueCharacters3("aabbbcccddd"));
}

// Tests unique characters string input.
TEST(hasUniqueCharacters3, UniqueCharacters) {
  EXPECT_TRUE(hasUniqueCharacters3("mango"));
  EXPECT_TRUE(hasUniqueCharacters3("abcd"));
}

