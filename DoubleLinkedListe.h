#pragma once

#pragma once

#include "LinkedList.h"
#define Node DoubleLinkedNode<T>

template <typename T>
struct DoubleLinkedNode
{
	T value;
	Node* next;
	Node* last;
};

template <typename T>
class DoubleLinkedList : public LinkedList<T, Node>
{
public:
	DoubleLinkedList() : LinkedList<T, Node>() {};

	void add(const T& value) override;
	void pop() override;
};

template<typename T>
inline void DoubleLinkedList<T>::add(const T& value)
{
	Node* newNode = new Node{ value, this->head, nullptr };
	this->head = newNode;
	this->size++;
}

template<typename T>
inline void DoubleLinkedList<T>::pop()
{
	if (this->isClear())
		throw std::out_of_range("out of range");

	Node* tmp = this->head;
	this->head = this->head->next;
	delete tmp;
	this->size--;
}

