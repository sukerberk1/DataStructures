#pragma once
#ifndef TREE_NODE

template <typename T>
class TreeNode
{
public:
	T value;
	TreeNode<T>** children;
	int childrenCount;

	TreeNode(T value);

	void AddChild(TreeNode<T>* node);
	void AddChild(T value);

	void Display();
	void DisplayChildren();
};

#endif // !TREE_NODE
