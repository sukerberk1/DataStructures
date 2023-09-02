#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
public:
	Node* head;
	Node* tail;

	LinkedList();
	LinkedList(char initialValue);
	LinkedList(Node* initialNode);

	void Push(char value);
	void Push(Node* node);
	char Get(int index);
	Node* GetNode(int index);

	void Insert(int index, Node* node);

	void Remove(int index);
	void Remove(Node* node);
	
	void Display();
};


#endif // !LINKEDLIST_H
