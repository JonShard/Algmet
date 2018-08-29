#include <cstdio>                                   // Printf

class Node 
{
public:
    int m_key;
    class Node* m_next;

    Node(int key);
};


class LinkList
{
private:
    Node* m_firstNode;
    int m_nodeCount;

public:
    LinkList();
    Node* push(int key);        // Adds node with given key to list, and returns pointer to it.
    Node* pop();                // Removes the frontmost node from list, and returns pointer to it. Note: Popping does not delete node object from memory.
    int length();               // Returns the amount of nodes in list.
    void display();             // Prints length, then all node keys.
};