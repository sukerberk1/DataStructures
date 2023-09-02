#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(Node* initialNode) : head(initialNode), tail(initialNode) {}

LinkedList::LinkedList(char initialValue)
{
	Node* n = new Node(initialValue);
	this->head = n;
	this->tail = n;
}


/* Creates a node based on a value and adds it as the end of the sequence */
void LinkedList::Push(char value)
{
	Node* n = new Node(value);
	this->Push(n);
}

/* Adds a node to the end of the sequence*/
void LinkedList::Push(Node* node)
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
char LinkedList::Get(int index)
{
	return this->GetNode(index)->value;
}

/* May return null pointer if index is out of bonds */
Node* LinkedList::GetNode(int index)
{
	Node* current = this->head;
	while (index > 0 && current != nullptr)
	{
		current = current->next;
		index--;
	}
	return current;
}

/* Displays every item in the Linked List - one item per line*/
void LinkedList::Display()
{
	Node* n = this->head;
	while (n != nullptr)
	{
		std::cout << n->value << std::endl;
		n = n->next;
	}
}