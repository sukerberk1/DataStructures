#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(T value);
	Node(T value, Node<T>* next);
};

#endif