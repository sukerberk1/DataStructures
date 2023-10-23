#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class LinkedListNode
{
public:
	T value;
	LinkedListNode<T>* next;

	LinkedListNode(T value);
	LinkedListNode(T value, LinkedListNode<T>* next);
};

#endif