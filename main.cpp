#include <iostream>
#include "TreeNode.h"
#include "Treenode.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"


int main()
{
	BinaryTree<short> tree = BinaryTree<short>(5);
	auto addedNode1 = tree.AddNode(10, tree.GetRoot());
	auto addedNode2 = tree.AddNode(11, tree.GetRoot());
	tree.AddNode(20, addedNode1);
	tree.AddNode(21, addedNode2);
	
	//tree.DisplayAsCatalogue();

	tree.InOrderTraversalDisplay();
	tree.PostOrderTraversalDisplay();
	tree.PreOrderTraversalDisplay();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
