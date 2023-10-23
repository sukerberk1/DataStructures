#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>
struct Stack
{
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;

	Stack();

	void Add(T value);
	T Pop();
	void Display();
};


#endif