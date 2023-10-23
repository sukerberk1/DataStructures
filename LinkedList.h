#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Node.cpp"

template <typename T>
class LinkedList
{
public:
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;

	LinkedList();
	LinkedList(T initialValue);
	LinkedList(LinkedListNode<T>* initialNode);

	void Push(T value);
	void Push(LinkedListNode<T>* node);
	char Get(int index);
	LinkedListNode<T>* GetNode(int index);

	void Insert(int index, LinkedListNode<T>* node);
	void Insert(int index, T value);

	void Remove(int index);
	void Remove(LinkedListNode<T>* node);
	
	void Display();
};


#endif // !LINKEDLIST_H
