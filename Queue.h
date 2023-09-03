#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <typename T>
struct Queue
{
	Node<T>* head;
	Node<T>* tail;
	int size;

	Queue();

	T Pop();
	Node<T> PopNode();
	void Enqueue(T value);
	void Enqueue(Node<T>* node);
	void Display();
};



#endif // !QUEUE_H

