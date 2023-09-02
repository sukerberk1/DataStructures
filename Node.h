#pragma once
#ifndef NODE_H
#define NODE_H


class Node
{
public:
	char value;
	Node* next;

	Node(char value);
	Node(char value, Node* next);
};


#endif