#pragma once

#include <cstdio>
#include <cmath>
#include "../include/Node.hpp"


class BinaryTree
{
private:
    BinaryTreeNode* m_root;
    int m_height;
    int m_length; 

    void recursiveKeyCheckingPush(BinaryTreeNode* root, int key);
    void recursivePush(BinaryTreeNode* root, int key, int level, int column);
    
public:
    enum Order { PreOrder, InOrder, PostOrder};
    BinaryTree();
    void push(int key);         // Adds a node with int key to the tree.
    int pop();                  // Removes the right-most node on the bottom level of the tree. Returns the removed node's key.
    int length();               // Returns amount of nodes in tree, includeing root, which is also populated with a key.
    void display();             // Prints length of tree, depth, and all the node keys.

};