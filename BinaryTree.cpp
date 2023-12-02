#include "BinaryTree.h"
#include <iostream>

template <typename T>
BinaryTree<T>::BinaryTree(T rootValue)
{
	root = new TreeNode<T>(rootValue);
}

template <typename T>
TreeNode<T>* BinaryTree<T>::AddNode(T nodeValue, TreeNode<T>* NodeToAppendTo)
{
	if (NodeToAppendTo->childrenCount >= maxChildrenCount)
	{
		return nullptr;
	}
	TreeNode<T>* node = new TreeNode<T>(nodeValue);
	NodeToAppendTo->AddChild(node);
	return node;
}

template <typename T>
TreeNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}

template <typename T>
void BinaryTree<T>::CatalogueRecursive(TreeNode<T>* node, short depth)
{
	for (int i = 0; i < depth; i++)
	{
		std::cout << '-';
	}
	std::cout << node->value << std::endl;
	for (int i = 0; i < node->childrenCount; i++)
	{
		CatalogueRecursive(node->children[i], depth+1);
	}
}

template <typename T>
void BinaryTree<T>::DisplayAsCatalogue()
{
	CatalogueRecursive(this->root, 0);
}

template <typename T>
void BinaryTree<T>::InOrderTraversalDisplay()
{
	std::cout << "In-order traversal:" << std::endl;
	InOrderTraversalDisplay(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::InOrderTraversalDisplay(TreeNode<T>* node)
{
	if (node->childrenCount > 0)
	InOrderTraversalDisplay(node->children[0]);
	std::cout << node->value << ' ';
	if (node->childrenCount > 1)
	InOrderTraversalDisplay(node->children[1]);
}

template <typename T>
void BinaryTree<T>::PreOrderTraversalDisplay()
{
	std::cout << "Pre-order traversal:" << std::endl;
	PreOrderTraversalDisplay(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::PreOrderTraversalDisplay(TreeNode<T>* node)
{
	std::cout << node->value << ' ';
	if(node->childrenCount > 0)
	PreOrderTraversalDisplay(node->children[0]);
	if(node->childrenCount > 1)
	PreOrderTraversalDisplay(node->children[1]);
}

template <typename T>
void BinaryTree<T>::PostOrderTraversalDisplay()
{
	std::cout << "Post-order traversal:" << std::endl;
	PostOrderTraversalDisplay(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::PostOrderTraversalDisplay(TreeNode<T>* node)
{
	if(node->childrenCount > 0)
	PostOrderTraversalDisplay(node->children[0]);
	if(node->childrenCount > 1)
	PostOrderTraversalDisplay(node->children[1]);
	std::cout << node->value << ' ';
}