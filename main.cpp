#include <iostream>
#include "TreeNode.cpp"


int main()
{
    TreeNode<int>* n = new TreeNode<int>(10);
    TreeNode<int>* c1 = new TreeNode<int>(20);
    TreeNode<int>* c2 = new TreeNode<int>(30);
    TreeNode<int>* c3 = new TreeNode<int>(40);
    n->AddChild(c1);
    n->AddChild(c2);
    n->AddChild(c3);
    n->Display();
    n->DisplayChildren();
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
