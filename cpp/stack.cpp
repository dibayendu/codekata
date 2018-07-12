// To run the program, try the command below:
// g++ stack.cpp -lgtest_main -lgtest

// Some stack functionality.

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

struct Stack {
    int data;
    Stack* next;
    Stack* minimum;
};

void appendStack(Stack *head, int data) {
    Stack *newStack = new Stack;
    newStack->data = data;
    newStack->next = NULL;
    newStack->minimum = newStack;

    Stack *current = head;
    while (current->next) {
        if (newStack->data < current->minimum->data) {
            current->minimum = newStack;
        }
        current = current->next;
    }
    if (newStack->data < current->minimum->data) {
        current->minimum = newStack;
    }
    current->next = newStack;
}

std::string printMinimum(Stack *node) {
    std::string statement = "";
    while (node) {
        statement += std::to_string(node->minimum->data);
        node = node->next;
    }
    return statement;
}


Stack* ascendingStack() {
    Stack *stack = new Stack;
    stack->data = 1;
    stack->next = NULL;
    stack->minimum = stack;

    appendStack (stack, 2);
    appendStack (stack, 3);
    appendStack (stack, 4);
    appendStack (stack, 5);
    return stack;
}

Stack* descendingStack() {
    Stack *stack = new Stack;
    stack->data = 5;
    stack->next = NULL;
    stack->minimum = stack;

    appendStack (stack, 4);
    appendStack (stack, 3);
    appendStack (stack, 2);
    appendStack (stack, 1);
    return stack;
}

TEST(LinkedList, PrintMinimum) {
    Stack *ascendingOrder = ascendingStack();
    EXPECT_EQ("12345", printMinimum(ascendingOrder));
    Stack *descendingOrder = descendingStack();
    EXPECT_EQ("11111", printMinimum(descendingOrder));
}

