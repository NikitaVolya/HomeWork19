#pragma once

#include "SingleLinkedListe.h"
#define MAX_STACK_SIZE 200

template <typename T>
class Stack : protected SingleLinkedList<T>
{
public:
	Stack() : SingleLinkedList<T>() {}

	T& first() { return SingleLinkedList<T>::first(); }
	const T& first() const { return SingleLinkedList<T>::first(); }

	size_t getSize() const { return this->size; }

	void add(const T& value) { if (this->size >= MAX_STACK_SIZE) throw std::overflow_error("Max size of stack"); SingleLinkedList<T>::add(value); }
	void pop() { SingleLinkedList<T>::pop(); }
};