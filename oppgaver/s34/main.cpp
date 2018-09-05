#include <cstdio>                                   // Printf
#include <stdlib.h>                                 // Atoi
#include <iostream>                                 // Reading parameter if not given.
#include <string>                                   // Reading parameter if not given.

#include "LinkList.h"



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
    LinkList linkList;

    Node** nodes = new Node*[input];

    for(auto i = 0; i < input; i++)
        nodes[i] = linkList.push(i);

    Node* notInList = new Node(999);

    linkList.display();
    linkList.moveToFront(notInList);

    linkList.display();

    return 0;
}