#include "../include/BinaryTree.hpp"
#include "../include/Utilities.hpp"

BinaryTree::BinaryTree()
{
    m_root = nullptr;
    m_height = 0;
    m_length = 0;
}


void BinaryTree::recursiveKeyCheckingPush(BinaryTreeNode* root, int key)
{
    if (key < root->m_key)
    {
        if (!root->m_left)
        {
            root->m_left = new BinaryTreeNode(key);
        }
        else 
        {
            recursiveKeyCheckingPush(root->m_left, key);
        }
    } 
    else
    {
        if (!root->m_right)
        {
            root->m_right = new BinaryTreeNode(key);
        }
        else 
        {
           recursiveKeyCheckingPush(root->m_right, key);
        }
    }
}

void BinaryTree::recursivePush(BinaryTreeNode* root, int key, int level, int column)
{
    
    if (root->m_left == nullptr && m_height - level == 1)         // If left child empty and at deepest level yet, make left child, done.
    {
        root->m_left = new BinaryTreeNode(key);
        m_length++;
        return;
    }
    if (root->m_right == nullptr && m_height - level == 1)        // If right child empty and at deepest level yet, make right child, done.
    {
        root->m_right = new BinaryTreeNode(key);
        if (column == std::pow(2, m_height-1) -1)       // If in rightmost node at deepest level. Add another layer.
        {
            m_height++; 
        }
        m_length++;
        return;
    }

    int length = m_length;
    if (root->m_left)
    {
        recursivePush(root->m_left, key, level+1, (column-1 > 0) ? column-1 : 0);
    }
    if(root->m_right && length == m_length) // If there is a right child and recursive on left side didn't push the new node.
    {
        recursivePush(root->m_right, key, level+1, column+1);
    }
}

void BinaryTree::push(int key)
{   
    if (!m_root)
    {
        m_root = new BinaryTreeNode(key);
        m_height++;
        m_length++;
        return;
    }

    recursivePush(m_root, key, 0, 0);

}


int BinaryTree::pop()
{

    return 0;
}


int BinaryTree::length()
{
    return m_length;
}


void displayTree(BinaryTreeNode* root, BinaryTree::Order order)
{
    if (order == BinaryTree::PreOrder) printf("%c (%d)", root->m_key, root->m_key);
    
    if (root->m_left) displayTree(root->m_left, order);
    if (order == BinaryTree::InOrder) printf("%c (%d)", root->m_key, root->m_key);
    
    if (root->m_right) displayTree(root->m_right, order);
    if (order == BinaryTree::PostOrder) printf("%c (%d)", root->m_key, root->m_key);
}

void BinaryTree::display()
{
    if (m_root)
    {
        char read = ' ';
        do 
        {
            printf("\n\nOrder to display the tree:\n1 - preorder\n2 - inorder\n3 - postorder\nq - back\n\n>");
            read = getchar();
            util::clearInputBuffer();
            switch (read)
            {
                case '1':
                   displayTree(m_root, PreOrder);
                break;

                case '2':
                    displayTree(m_root, InOrder);
                break;

                case '3': 
                    displayTree(m_root, PostOrder);
                break;
            }
        } while (read != 'q');
    }
    else
    {
        printf("Can not display an empty tree.\n");
    }
}