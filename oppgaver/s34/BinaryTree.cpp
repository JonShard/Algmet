#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
    m_root = nullptr;
}


void recursivePush(BinaryTreeNode* root, int key)
{
    if (key < root->m_key)
    {
        if (!root->m_left)
        {
            root->m_left = new BinaryTreeNode(key);
        }
        else 
        {
            recursivePush(root->m_left, key);
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
            recursivePush(root->m_right, key);
        }
    }
}

void BinaryTree::push(int key)
{
    
    if (m_root == nullptr)
    {
        m_root = new BinaryTreeNode(key);
    }

    recursivePush(m_root, key);

}


int BinaryTree::pop()
{

    return 0;
}


int BinaryTree::length()
{

    return 0;
}


void BinaryTree::display()
{

}