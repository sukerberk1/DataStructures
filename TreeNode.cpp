#include <iostream>
#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(T val) : value(val), children(nullptr), childrenCount(0)
{ }


template <typename T>
void TreeNode<T>::AddChild(TreeNode<T>* node)
{
    TreeNode<T>** newChildren = new TreeNode<T>*[childrenCount + 1];
    if (children != nullptr)
    {
        for (size_t i = 0; i < childrenCount; i++)
        {
            newChildren[i] = children[i];
        }
        delete[] children; // Deallocate the old children array
    }
    newChildren[childrenCount] = node;
    childrenCount++;
    children = newChildren; // Assign the new array to the children pointer
}


template <typename T>
void TreeNode<T>::AddChild(T value)
{
	TreeNode<T>* node = new TreeNode<T>(value);
	this->AddChild(node);
}

template <typename T>
void TreeNode<T>::Display()
{
    std::cout << this->value << std::endl;
}


template <typename T>
void TreeNode<T>::DisplayChildren()
{
    for (auto i = 0; i < childrenCount; i++)
    {
        children[i]->Display();
    }
}