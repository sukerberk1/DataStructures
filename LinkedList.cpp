#include "LinkedList.h"
#include "Node.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(Node<T>* initialNode) : head(initialNode), tail(initialNode) {}

template <typename T>
LinkedList<T>::LinkedList(T initialValue)
{
	Node<T>* n = new Node<T>(initialValue);
	this->head = n;
	this->tail = n;
}


/* Creates a node based on a value and adds it as the end of the sequence */
template <typename T>
void LinkedList<T>::Push(T value)
{
	Node<T>* n = new Node<T>(value);
	this->Push(n);
}

/* Adds a node to the end of the sequence*/
template <typename T>
void LinkedList<T>::Push(Node<T>* node)
{
	if (this->head == nullptr)
	{
		this->head = node;
		this->tail = node;
		return;
	}
	this->tail->next = node;
	this->tail = node;
}

/* May return null pointer if index is out of bonds */
template <typename T>
char LinkedList<T>::Get(int index)
{
	return this->GetNode(index)->value;
}

/* May return null pointer if index is out of bonds */
template <typename T>
Node<T>* LinkedList<T>::GetNode(int index)
{
	Node<T>* current = this->head;
	while (index > 0 && current != nullptr)
	{
		current = current->next;
		index--;
	}
	return current;
}

/* Displays every item in the Linked List - one item per line*/
template <typename T>
void LinkedList<T>::Display()
{
	Node<T>* n = this->head;
	while (n != nullptr)
	{
		std::cout << n->value << std::endl;
		n = n->next;
	}
}

/* Inserts a node in the given index. If index is larger than the array, append it to the end. If index is less than 0, append it to the beginning */
template <typename T>
void LinkedList<T>::Insert(int index, Node<T>* node)
{
	Node<T>* n = this->head;
	if (index <= 0)
	{
		node->next = n;
		this->head = node;
		return;
	}
	int i = 0;
	while (i < index-1)
	{
		if (n->next == nullptr)
		{
			this->Push(node);
			return;
		}
		n = n->next;
		i++;
	}
	Node<T>* nodeAfter = n->next;
	n->next = node;
	node->next = nodeAfter;
}

/* Inserts a node in the given index. If index is larger than the array, append it to the end. If index is less than 0, append it to the beginning */
template <typename T>
void LinkedList<T>::Insert(int index, T value)
{
	Node<T>* n = new Node<T>(value);
	this->Insert(index, n);
}
/* Deletes a node based on certain index */
template <typename T>
void LinkedList<T>::Remove(int index)
{
	Node<T>* n = this->head;
	if (index == 0)
	{
		this->head = this->head->next;
		return;
	}
	int i = 0;
	while (i < index-1)
	{
		n = n->next;
		if (n == nullptr) return;
		i++;
	}
	if (n->next == nullptr) return;
	n->next = n->next->next;
	if (n->next == nullptr) this->tail = n;
}

/* Deletes node from list based on its reference */
template <typename T>
void LinkedList<T>::Remove(Node<T>* node)
{
	Node<T>* n = this->head;
	while (true)
	{
		if (n->next == node)
		{
			n->next == n->next->next;
		}
		else if (n->next == nullptr) return;
		n = n->next;
	}
}