#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Node.cpp"

template <typename T>
class LinkedList
{
public:
	Node<T>* head;
	Node<T>* tail;

	LinkedList();
	LinkedList(T initialValue);
	LinkedList(Node<T>* initialNode);

	void Push(T value);
	void Push(Node<T>* node);
	char Get(int index);
	Node<T>* GetNode(int index);

	void Insert(int index, Node<T>* node);
	void Insert(int index, T value);

	void Remove(int index);
	void Remove(Node<T>* node);
	
	void Display();
};


#endif // !LINKEDLIST_H
