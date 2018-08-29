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

    for(auto i = 0; i < input; i++)
    {
        linkList.push(i);
    }

    linkList.display();
    linkList.pop();
    linkList.display();
    
    return 0;
}