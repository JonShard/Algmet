#pragma once

#include <cstdio>


class Node 
{
public:
    int m_key;
    class Node* m_next;

    Node(int key);
};

