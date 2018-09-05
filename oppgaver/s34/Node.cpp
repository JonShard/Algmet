#include "Node.h"

Node::Node(int key)
{
    printf("Creating new Node with key %d\n", key);
    m_key = key;
    m_next = nullptr;
}
