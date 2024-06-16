#pragma once

#include "DoubleLinkedListe.h"

template <typename T>
class Queue : protected DoubleLinkedList<T>
{
private:
	Node* back;
public:
	Queue() : DoubleLinkedList<T>{} {};

	T& getValue() { if (!back) throw std::out_of_range("Queue is clear"); return back->value; }
	const T& getValue() const { if (!back) throw std::out_of_range("Queue is clear"); return back->value; }

	size_t getSize() const { return this->size; }

	void add(const T& value) override;
	void pop() override;
};

template<typename T>
inline void Queue<T>::add(const T& value)
{
	DoubleLinkedList<T>::add(value);
	if (this->size == 1)
		back = this->head;
}

template<typename T>
inline void Queue<T>::pop()
{
	if (!back)
		throw std::out_of_range("Queue is clear");

	Node* tmp = back;
	back = back->last;

	delete tmp;
	if (--this->size == 0)
		this->head = nullptr;
}
