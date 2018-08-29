#include <cstdio>                                   // Printf
#include <stdlib.h>                                 // Atoi

struct Node
{
    int key;
    struct Node* next;
};

int input;
int nodes;
Node* start;    // Points to the first node in the list #0.
Node* z;        // Points to a fake node after the last node in the list #n.

void display()
{
    Node* head = start;     // Points to the currently active node.
    printf("\n[");
    while (head-> next != z)
    {
        printf(" %d ", head-> key);
    }
    printf("]\n\n");
}


void addNode()
{
    printf("Adding new node\n");
    Node* head = start;     // Points to the currently active node.
    while (head-> next != z)
    {
        printf("test\n");
        head = head-> next;
    }

    head-> next = new Node();
    head = head-> next;
    head-> key = ++nodes;
    head-> next = z;

    display();
}


bool isInList(Node* t)
{
    Node* head = start;     // Points to the currently active node.

    while (head != z)
    {
        if (t == head)              // Found t.
        {
            return true;
        }
        head = head-> next;
    }                               // Reached the end, didn't find t, return false.
    return false;
}


void moveToFront(Node* t)
{
    Node* head = start;                     // Points to the currently active node.

    printf("Moving node to front\n");
    if (!isInList(t))
    {
        printf("Error: Can not move node to front since node does not exist in list.\n");
        return;
    }

    while (head-> next != t)        // Search till we find t.
    {
        head = head-> next;
    }
    head-> next = head-> next-> next;// Remove t from list.

    while (head-> next != z)
    {
        head-> next = t;
        t-> next = z;
    }
    display();
}


int main(int argc, char** args)
{
    if (argc < 2)
    {
        printf("\nError. Expected 1 parameter(int).\nUsage: a.out 5\nExiting.\n");
        return 1;
    }
    input = std::atoi(args[1]);                     // Converting input to int.
    printf("Received input %d\n", input);

    start = new Node;                                // Set up list.
    start-> next = z;
    start-> key = -1;
    z = new Node;

    while(nodes < input) addNode();

    display();

    return 0;
}
