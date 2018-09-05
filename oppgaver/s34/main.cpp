#include <cstdio>                                   // Printf
#include <stdlib.h>                                 // Atoi
#include <iostream>                                 // Reading parameter if not given.
#include <string>                                   // Reading parameter if not given.

#include "LinkList.hpp"
#include "BinaryTree.hpp"


void clearInputBuffer()
{
    char c = ' ';
    do 
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void initLinkList(int length)
{
    LinkList linkList;                              // TODO: make destructor.


    Node** nodes = new Node*[length];

    for(auto i = 0; i < length; i++)
        nodes[i] = linkList.push(i);

    Node* notInList = new Node(999);

    linkList.display();
    linkList.moveToFront(notInList);
    linkList.display();
}


void initBinaryTree()
{
    BinaryTree binaryTree;                          // TODO: make destructor.

    char read = ' ';
    do 
    {
        printf("\n\n1 - push\n2 - pop\n3- display\nq - back\n\n>");
        read = getchar();
        clearInputBuffer();
        switch (read)
        {
            case '1':
                binaryTree.push(getchar());     // Save the int value of the char. Dirty use of int m_key in Node.
                clearInputBuffer();
            break;

            case '2':
                binaryTree.pop();
            break;

            case '3': 
                binaryTree.display();
            break;
        }
    } while (read != 'q');
}


int main(int argc, char** args)
{
    int input = 0;
    if (argc < 2)
    {
        printf("\nError. Expected 1 parameter(int).\nUsage: a.out 5\nSpecify parameter(int) now or exit.\n");
        std::string read;
        std::getline(std::cin, read);
        input = std::atoi(read.c_str());
    }
    else
    {
        input = std::atoi(args[1]);                     // Converting input to int.
    }
    printf("Received input %d\n", input);
    
    char read = ' ';
    do 
    {
        printf("\n\n1 - linkList\n2 - binaryTree\nq - quit\n\n>");
        read = getchar();
        clearInputBuffer();
        switch (read)
        {
            case '1':
                initLinkList(input);
            break;

            case '2':
                initBinaryTree();
            break;
        }
    } while (read != 'q');
    
    printf("Application exiting, press enter to continue.\n\n>");
    getchar();
    clearInputBuffer();                                 // Clear input stream from in case its not empty.
    return 0;
}