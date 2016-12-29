// To run the program, try the command below:
// g++ replace_spaces.cpp -lgtest_main -lgtest

// replaces all the spaces with "%20"

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

void replaceSpaces(std::string& statement) {
    int size = statement.size();
    if (size < 1) return;

    int i=0;
    while (i<size) {
        if (statement[i]==' ') {
            statement.erase(i,1);
            statement.insert(i,"%20");
            size = statement.size();
        }
        i++;
    }
}

TEST(replaceSpaces, EmptyString) {
    std::string statement = "";
    std::string replaces_spaces_statement = "";
    replaceSpaces(statement);
    EXPECT_EQ(replaces_spaces_statement, statement);
}

TEST(replaceSpaces, SingleCharacter) {
    std::string statement = " ";
    std::string replaces_spaces_statement = "%20";
    replaceSpaces(statement);
    EXPECT_EQ(replaces_spaces_statement, statement);
}

TEST(replaceSpaces, WithSpaces) {
    std::string statement = "hello, how are you! ";
    std::string replaces_spaces_statement = "hello,%20how%20are%20you!%20";
    replaceSpaces(statement);
    EXPECT_EQ(replaces_spaces_statement, statement);
}

TEST(replaceSpaces, WithOutSpaces) {
    std::string statement = "hello,howareyou!";
    std::string replaces_spaces_statement = "hello,howareyou!";
    replaceSpaces(statement);
    EXPECT_EQ(replaces_spaces_statement, statement);
}

