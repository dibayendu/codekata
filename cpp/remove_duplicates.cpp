// To run the program, try the command below:
// g++ remove_duplicates.cpp -lgtest_main -lgtest

// removes the duplicate characters in a string

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

void removeDuplicates(std::string& statement) {
    int size = statement.size();
    if (size < 2) return;

    for (int i=0; i<size-1; i++) {
        int j = i+1;
        while (j<size) {
            if (statement[i] == statement[j]) {
                statement.erase(j,1);
                size = statement.size(); // size changes
            } else {
                j++;
            }
        }
    }
}

TEST(removeDuplicates, ContainOnlyOneCharacter) {
    std::string statement = "a";
    std::string without_duplicates_statement = "a";
    removeDuplicates(statement);
    EXPECT_EQ(without_duplicates_statement, statement);
}

 TEST(removeDuplicates, ContainDuplicates) {
    std::string statement = "aaa";
    std::string without_duplicates_statement = "a";
    removeDuplicates(statement);
    EXPECT_EQ(without_duplicates_statement, statement);
}

TEST(removeDuplicates, DoesNotContainDuplicates) {
    std::string statement = "abcd";
    std::string without_duplicates_statement = "abcd";
    removeDuplicates(statement);
    EXPECT_EQ(without_duplicates_statement, statement);
}

