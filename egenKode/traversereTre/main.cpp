#include <cstdio>


class Node
{
private:
    char value;
    Node* left;
    Node* right;
public:
    Node(char _value)
    {
        printf("Creating new node.");
        value = _value;
        left = nullptr;
        right = nullptr;
    }
    bool addChild(char _value)
    {
        if(left == nullptr)
        {
            left = new Node(_value);
        }
        else if (right == nullptr)
        {
            right = new Node(_value);
        }
        else if (left->addChild(_value))
        {
            return true;
        }
        else if (right->addChild(_value));
        else 
        {
            return false;
        }

        printf("Adding child: %c\n", _value);
        return true;
    }
};


Node root(' ');

int main(int argc, char** args)
{
    if (argc < 2)
    {
        printf("\nError. Expected 1 parameter(string).\nUsage: a.out testString\nExiting.\n");
        return 1;
    }

    for(int i = 0; args[1][i] != '\0'; i++)
    {
        root.addChild(args[1][i]);
    }

    return 0;
}
