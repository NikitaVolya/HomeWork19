#pragma once

#include "LinkedList.h"
#define Node SingleLinkedNode<T>

template <typename T>
struct SingleLinkedNode
{
	T value;
	Node* next;
};


template <typename T>
class SingleLinkedList : public LinkedList<T, Node>
{
public:
	SingleLinkedList() : LinkedList<T, Node>() {};
	SingleLinkedList(const std::initializer_list<T>& lst);

	void add(const T& value) override;
	void pop() override;
};

template<typename T>
inline SingleLinkedList<T>::SingleLinkedList(const std::initializer_list<T>& lst) : LinkedList<T, Node> {}
{
	for (int i = (int)lst.size() - 1; i >= 0; i--)
	{
		const T& value = *(lst.begin() + i);
		add(value);
	}
}

template<typename T>
inline void SingleLinkedList<T>::add(const T& value)
{
	Node* newNode = new Node{ value, this->head };
	this->head = newNode;
	this->size++;
}

template<typename T>
inline void SingleLinkedList<T>::pop()
{
	if (this->isClear())
		throw std::out_of_range("out of range");

	Node* tmp = this->head;
	this->head = this->head->next;
	delete tmp;
	this->size--;
}

