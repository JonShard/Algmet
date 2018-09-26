#include "../include/LinkList.hpp"

LinkList::LinkList()
{
    printf("Creating new LinkList.\n");

    m_firstNode = nullptr;
    m_nodeCount = 0;
}


Node* LinkList::push(int key)
{
    Node* head = m_firstNode;                       // Create a head that will move through the list.
    printf("Adding new node to LinkList.\n");

    if (head != nullptr)                            // If not fist node.
    {
        while (head->m_next != nullptr)             // While not at end, keep going.
        {
            head = head->m_next; 
        }
    }
    else                                            // First node. Secial case.
    {
        m_firstNode = new Node(key);
        m_nodeCount++;
        return m_firstNode;
    }

    m_nodeCount++;
    printf("Done now %d nodes in LinkList.\n", m_nodeCount);
    head->m_next = new Node(key);
    
    return head->m_next;
}

int LinkList::pop()
{
    Node* head = m_firstNode;                       // Create a head that will move through the list.
    Node* target = nullptr;
    int targetKey = 0;

    if (head != nullptr)                            // If not fist node.
    {
        while (head->m_next->m_next != nullptr)             // While not at end, keep going.
        {
            head = head->m_next;
        }
        target = head->m_next;
        head->m_next = nullptr;

        m_nodeCount--;
        targetKey = target->m_key;
        delete target;
        printf("popped node with key %d off the list.", target->m_key);
        return targetKey;
    }

    printf("Can not pop from an empty list.");
    return targetKey;
}


int LinkList::length()
{   return m_nodeCount;     }


void LinkList::display()
{
    Node* head = m_firstNode;                       // Create a head that will move through the list.
    if (head != nullptr)                            // If not fist node.
    {
        printf("\nLength: %d [ %d " , m_nodeCount, head->m_key);
        while (head->m_next != nullptr)
        {
            head = head->m_next;
            printf(" %d " , head->m_key);
        }
        printf("]\n");
    }
    else
    {
        printf("List empty, nothing to display.\n");
    }
}


bool LinkList::moveToFront(Node* t)
{
    Node* head = m_firstNode;                       // Create a head that will move through the list.
    if (head != nullptr)                            // If not fist node.
    {
        while (head->m_next != nullptr)
        {
            if (head->m_next == t)
            {
                if (head->m_next->m_next == nullptr)
                {
                    printf("Node t is already at front.\n");
                    return false;
                }
                head->m_next = head->m_next->m_next;
            }
            head = head->m_next;
        }
        head->m_next = t;
        t->m_next = nullptr;
        printf("Moved node t with key %d to front.\n", t->m_key);
        return true;
    }

    printf("List empty, can not move t to front.\n");
    return false;
    

}