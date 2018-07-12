// To run the program, try the command below:
// g++ linked_list.cpp -lgtest_main -lgtest

// Some linked list functionality.

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

struct Node {
    int data;
    Node *next;
};

void appendNode(Node *head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    Node *current = head;
    while (current) {
        if (current->next == NULL) {
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void insertSortedNode(Node** head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        Node* previous = NULL;
        while(current && current->data < data) {
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

std::string print(Node *node) {
    std::string statement = "";
    while (node) {
        statement += std::to_string(node->data);
        node = node->next;
    }
    return statement;
}

Node* reverseList (Node* head) {
    if (head == NULL) {
        return head;
    } else {
        Node *current = head;
        Node *tmp = NULL;
        Node *previous = NULL;
        while (current) {
            tmp = current->next;
            current->next = previous;
            previous = current;
            current = tmp;
        }
        return previous;
    }
}

Node* searchNode (Node* head, int data) {
    while (head) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteDuplicates(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    Node* previous = NULL;
    while(current) {
        Node* runner = head;
        while (runner != current) {
            if (runner->data == current->data) {
                previous->next = current->next;
                delete current;
                current = previous;
                break;
            }
            runner = runner->next;
        }
        previous = current;
        current = current->next;
    }
}

bool deleteNode(Node** mainHead, int data) {
    Node* head = *mainHead;
    if (head == NULL) {
        return false;
    } else {
        Node *lastNode = NULL;
        while (head) {
            if (head->data == data) {
                if (lastNode) {
                    lastNode->next = head->next;
                    delete head;
                    head = lastNode;
                } else {
                    Node *next = head->next;
                    delete head;
                    *mainHead = next;
                    head = next;
                }
                return true;
            }
            lastNode = head;
            if (head) {
                head = head->next;
            }
        }
        return false;
    }
}

Node* nthLastElement(Node* head, int n) {
    if(head == NULL || n < 1) {
        return NULL;
    }

    Node* current = head;
    Node* nthLast = NULL;
    int counter = 0;
    while (current) {
        counter++;
        if (counter - n >= 0) {
            if (nthLast) {
                nthLast = nthLast->next;
            } else {
                nthLast = head;
            }
        }
        current = current->next;
    }
    return nthLast;
}

Node* initialList() {
    Node *list = new Node;
    list->data = 1;
    list->next = NULL;

    appendNode (list, 2);
    appendNode (list, 3);
    appendNode (list, 4);
    appendNode (list, 5);
    return list;
}

Node* circularLinkedList() {
    Node *list = new Node;
    list->data = 1;
    list->next = NULL;

    appendNode (list, 2);  appendNode (list, 3);  appendNode (list, 4);
    appendNode (list, 5);  appendNode (list, 6);  appendNode (list, 7);
    appendNode (list, 8);  appendNode (list, 9);  appendNode (list, 10);
    appendNode (list, 11);
    Node* Node4 = searchNode(list, 4);
    Node* Node11 = searchNode(list, 11);
    Node11->next = Node4;
    return list;
}

Node* circularStart (Node* head) {
    if (head == NULL) return NULL;

    Node* runner1 = head;
    Node* runner2 = head;

    while (runner1 && runner2) {
        runner1 = runner1->next;
        runner2 = runner2->next;

        if (runner2) {
            // runner2 is 2 times faster than runner 1
            runner2 = runner2->next;
            if (runner2 == NULL) {
                return NULL;
            }
        } else {
            return NULL;
        }

        // std::cout << runner1->data << "\t,\t" << runner2->data << std::endl;
        if (runner1 == runner2) {
            break;
        }
    }

    /* Move n1 to Head. Keep n2 at Meeting Point. Each are k steps
     * from the Loop Start. If they move at the same pace, they must
     * meet at Loop Start. */
    runner1 = head;
    while (runner1 != runner2) {
        runner1 = runner1->next;
        runner2 = runner2->next;
    }
    return runner1;
}

TEST(LinkedList, Print) {
    Node *list = initialList();
    EXPECT_EQ("12345", print(list));
}

TEST(LinkedList, NthLastElement) {
    Node *list = initialList();
    EXPECT_EQ("12345", print(list));
    Node* nthLast = nthLastElement(list, 1);
    EXPECT_EQ(5, nthLast->data);
    nthLast = nthLastElement(list, 3);
    EXPECT_EQ(3, nthLast->data);
    nthLast = nthLastElement(list, 5);
    EXPECT_EQ(1, nthLast->data);
    nthLast = nthLastElement(list, 7);
    EXPECT_EQ(NULL, nthLast);
}

TEST(LinkedList, Reverse) {
    Node *list = NULL;
    reverseList(list);
    EXPECT_EQ("", print(NULL));
    list = initialList();
    EXPECT_EQ("12345", print(list));
    Node *head = reverseList(list);
    EXPECT_EQ("54321", print(head));
}

TEST(LinkedList, DeleteNode) {
    Node *list = initialList();
    EXPECT_EQ("12345", print(list));
    EXPECT_FALSE(deleteNode(&list, 6));
    EXPECT_TRUE(deleteNode(&list, 3));
    EXPECT_EQ("1245", print(list));
    EXPECT_TRUE(deleteNode(&list, 1));
    EXPECT_EQ("245", print(list));
    EXPECT_TRUE(deleteNode(&list, 5));
    EXPECT_EQ("24", print(list));
    EXPECT_TRUE(deleteNode(&list, 2));
    EXPECT_EQ("4", print(list));
    EXPECT_TRUE(deleteNode(&list, 4));
    EXPECT_EQ("", print(list));
    EXPECT_FALSE(deleteNode(&list, 3));
}

TEST(LinkedList, InsertSortedNode) {
    Node *list = initialList();
    deleteNode(&list, 3);
    EXPECT_EQ("1245", print(list));
    insertSortedNode(&list, 3);
    EXPECT_EQ("12345", print(list));
}

TEST(LinkedList, DeleteDuplicates) {
    Node *list = new Node;
    list->data = 1;
    list->next = NULL;

    appendNode (list, 1);
    appendNode (list, 2);
    appendNode (list, 3);
    EXPECT_EQ("1123", print(list));
    deleteDuplicates(list);
    EXPECT_EQ("123", print(list));

    appendNode (list, 2);
    appendNode (list, 4);
    EXPECT_EQ("12324", print(list));
    deleteDuplicates(list);
    EXPECT_EQ("1234", print(list));
    appendNode (list, 4);
    appendNode (list, 4);
    EXPECT_EQ("123444", print(list));
    deleteDuplicates(list);
    EXPECT_EQ("1234", print(list));
}

TEST(LinkedList, CircularLinkedList) {
    Node *nonCircular = initialList();
    EXPECT_EQ("12345", print(nonCircular));
    EXPECT_EQ(NULL, circularStart(nonCircular));

    Node *circular = circularLinkedList();
    Node* circularHead = circularStart(circular);
    EXPECT_EQ(4, circularHead->data);
}

