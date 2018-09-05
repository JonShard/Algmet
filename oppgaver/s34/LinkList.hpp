#pragma once
#include <cstdio>                                   // Printf
#include "Node.h"

class LinkList
{
private:
    Node* m_firstNode;
    int m_nodeCount;

public:
    LinkList();
    Node* push(int key);                // Adds node with given key to list.
    int pop();                          // Removes the frontmost node from list, and returns a pointer to it.
    int length();                       // Returns the amount of nodes in list.
    void display();                     // Prints length, then all node keys.

    bool moveToFront(Node* t);          // Moves the node pointed to by t to the frond of the list. Returns false if fails.
    bool swap(Node* t, Node* u);         // Swaps position of two nodes, if either of them doesn't exist, false is returned.
};