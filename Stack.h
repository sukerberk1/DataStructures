#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>
struct Stack
{
	Node<T>* head;
	Node<T>* tail;

	Stack();

	void Add(T value);
	T Pop();
	void Display();
};


#endif