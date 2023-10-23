#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <typename T>
struct Queue
{
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;
	int size;

	Queue();

	T Pop();
	LinkedListNode<T> PopNode();
	void Enqueue(T value);
	void Enqueue(LinkedListNode<T>* node);
	void Display();
};



#endif // !QUEUE_H

