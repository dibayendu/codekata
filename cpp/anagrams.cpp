// To run the program, try the command below:
// g++ anagrams.cpp -lgtest_main -lgtest

// checks whether strings are anagrams of each other.

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

bool anagrams(std::string string1, std::string string2) {
    int string1_size = string1.size();
    int string2_size = string2.size();

    if (string1_size<1 || string2_size<1) return false;

    if (string1_size == string2_size) {
        for (int i=string1_size-1; i>=0; i--) {
            if (string1[i] != string2[string1_size-1-i]) return false;
        }
    } else {
        return false;
    }

    return true;
}

TEST(anagrams, WhenEmpty) {
  EXPECT_FALSE(anagrams("", ""));
  EXPECT_FALSE(anagrams("true", ""));
  EXPECT_FALSE(anagrams("", "false"));
}

TEST(anagrams, NonSameSize) {
  EXPECT_FALSE(anagrams("apple", "banana"));
}

TEST(anagrams, SingleCharacter) {
  EXPECT_TRUE(anagrams("a", "a"));
  EXPECT_FALSE(anagrams("a", "b"));
}

TEST(anagrams, Anagrams) {
  EXPECT_TRUE(anagrams("apple", "elppa"));
  EXPECT_TRUE(anagrams("ana", "ana"));
}

TEST(anagrams, NotAnagrams) {
  EXPECT_FALSE(anagrams("apple", "elpap"));
  EXPECT_FALSE(anagrams("anna", "naa"));
  EXPECT_FALSE(anagrams("anna", "an"));
}

