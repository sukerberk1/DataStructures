#include "Node.h"
#include "Node.h"


Node::Node(char value)
{
	this->value = value;
	this->next = nullptr;
}

Node::Node(char value, Node* next)
{
	this->value = value;
	this->next = next;
}
