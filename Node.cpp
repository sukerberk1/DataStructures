#include "Node.h"
#include "Node.h"

template <typename T>
LinkedListNode<T>::LinkedListNode(T value)
{
	this->value = value;
	this->next = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next)
{
	this->value = value;
	this->next = next;
}
