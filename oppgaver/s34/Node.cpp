#include "Node.hpp"

Node::Node(int key)
{
    printf("Creating new Node with key %d\n", key);
    m_key = key;
    m_next = nullptr;
}


BinaryTreeNode::BinaryTreeNode(int key) : Node(key)
{
    m_right = nullptr;
    m_left = nullptr;
}