#include "Utilities.hpp"

namespace util
{

void clearInputBuffer()
{
    char c = ' ';
    do 
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

}