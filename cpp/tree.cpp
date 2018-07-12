// To run the program, try the command below:
// g++ tree.cpp -lgtest_main -lgtest

// Some tree functionality.

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

struct TreeNode {
    int data;
    TreeNode *left, *right;
};

TreeNode* newTreeNode(int data) {
    TreeNode *treeNode = new TreeNode;
    treeNode->data = 1;
    treeNode->left = treeNode->right = NULL;
    return treeNode;
}

TreeNode* initialiseBalancedTree() {
    TreeNode *root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    return root;
}

TreeNode* initialiseUnBalancedTree() {
    TreeNode *root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    root->left->left->left = newTreeNode(6);
    root->left->left->right = newTreeNode(7);
    return root;
}

int minDepth (TreeNode* root) {
    // Corner case. Should never be hit unless the code is
    // called on root = NULL
    if (root == NULL)
        return 0;

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

int maxDepth (TreeNode* root) {
    // Corner case. Should never be hit unless the code is
    // called on root = NULL
    if (root == NULL)
        return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    return (maxDepth(root) - minDepth(root)) <= 1;
}

TEST(LinkedList, BalancedTree) {
    TreeNode *rootTreeNode = initialiseBalancedTree();
    EXPECT_EQ(2, minDepth(rootTreeNode));
    EXPECT_EQ(3, maxDepth(rootTreeNode));
    EXPECT_TRUE(isBalanced(rootTreeNode));
}

TEST(LinkedList, UnBalancedTree) {
    TreeNode *rootTreeNode = initialiseUnBalancedTree();
    EXPECT_EQ(2, minDepth(rootTreeNode));
    EXPECT_EQ(4, maxDepth(rootTreeNode));
    EXPECT_FALSE(isBalanced(rootTreeNode));
}

