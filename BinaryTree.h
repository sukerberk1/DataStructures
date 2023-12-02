#ifndef BINARY_TREE
#define BINARY_TREE
#include "TreeNode.h"

template <typename T>
class BinaryTree
{
	TreeNode<T>* root;
	int maxChildrenCount = 2;

	void CatalogueRecursive(TreeNode<T>* node, short depth);

	void PreOrderTraversalDisplay(TreeNode<T>* node);
	void InOrderTraversalDisplay(TreeNode<T>* node);
	void PostOrderTraversalDisplay(TreeNode<T>* node);
public:
	BinaryTree(T rootValue);
	TreeNode<T>* GetRoot();
	TreeNode<T>* AddNode(T leafValue, TreeNode<T>* nodeToAppendTo);

	void DisplayAsCatalogue();

	void PreOrderTraversalDisplay();
	void InOrderTraversalDisplay();
	void PostOrderTraversalDisplay();
};

#endif // !BINARY_TREE