#include "Queue.h"
#include "Node.cpp"
#include <iostream>

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) { }

template <typename T>
void Queue<T>::Enqueue(T value)
{
	LinkedListNode<T>* n = new LinkedListNode<T>(value);
	this->Enqueue(n);
}

template <typename T>
void Queue<T>::Enqueue(LinkedListNode<T>* node)
{
	if (head == nullptr)
	{
		head = node;
		tail = node;
		return;
	}
	tail->next = node;
	tail = node;
	size++;
}

template <typename T>
T Queue<T>::Pop()
{
	return PopNode().value;
}

template <typename T>
LinkedListNode<T> Queue<T>::PopNode()
{
	LinkedListNode<T>* n = head;
	head = head->next;
	size--;
	n->next = nullptr;
	return *n;
}

template <typename T>
void Queue<T>::Display()
{
	auto n = head;
	for (int i = 0; i <= this->size; i++)
	{
		std::cout << i + 1 << " " << n->value << std::endl;
		n = n->next;
	}
}