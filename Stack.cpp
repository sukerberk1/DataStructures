#include "Stack.h"
#include "Node.cpp"
#include <iostream>

template<typename T>
Stack<T>::Stack() : head(nullptr), tail(nullptr)
{
}

template <typename T>
void Stack<T>::Add(T value)
{
	LinkedListNode<T>* n = new LinkedListNode<T>(value);
	if (tail == nullptr)
	{
		head = n;
		tail = n;
		return;
	}
	n->next = head;
	head = n;
}

template <typename T>
T Stack<T>::Pop()
{
	if (head == nullptr) throw;
	LinkedListNode<T>* n = head;
	head = head->next;
	n->next = nullptr;
	return n->value;
}

template <typename T>
void Stack<T>::Display()
{
	LinkedListNode<T>* n = head;
	while (n != nullptr)
	{
		std::cout << n->value << std::endl;
		n = n->next;
	}
}
