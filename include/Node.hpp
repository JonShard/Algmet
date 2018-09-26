#pragma once

#include <cstdio>


class Node 
{
public:
    int m_key;
    class Node* m_next;

    Node(int key);
};

class BinaryTreeNode : public Node
{
public: 
    class BinaryTreeNode* m_right;
    class BinaryTreeNode* m_left;

    BinaryTreeNode(int key);
};