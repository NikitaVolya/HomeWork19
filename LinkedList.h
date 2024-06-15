#pragma once

#include <iostream>

template <typename T, class N>
class LinkedList
{
protected:
	N* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {};
	~LinkedList();

	bool isClear() { return !head; }
	size_t lenght() const { return size; }

	T& first() { if (isClear()) throw std::out_of_range("list is clear"); return head->value; }
	const T& first() const { if (isClear()) throw std::out_of_range("list is clear"); return head->value; }

	T& end();
	const T& end() const;

	T& at(int index);
	const T& at(int index) const;

	T& operator[](int index) { return at(index); }
	const T& operator[](int index) const { return at(index); }

	virtual void add(const T& value) = 0;
	virtual void pop() = 0;

	std::ostream& print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const LinkedList<T, N>& lst) { return lst.print(out); }
};

template<typename T, class N>
inline LinkedList<T, N>::~LinkedList()
{
	N* ptr = head;
	while (ptr)
	{
		N* tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
}

template<typename T, class N>
inline T& LinkedList<T, N>::end()
{
	if (isClear())
		throw std::out_of_range("list is clear");

	N* tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return tmp->value;
}

template<typename T, class N>
inline const T& LinkedList<T, N>::end() const
{
	if (isClear())
		throw std::out_of_range("list is clear");

	N* tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return tmp->value;
}

template<typename T, class N>
inline T& LinkedList<T, N>::at(int index)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("index is out of range");

	N* tmp = head;
	while (index)
	{
		tmp = tmp->next;
		index--;
	}
	return tmp->value;
}

template<typename T, class N>
inline const T& LinkedList<T, N>::at(int index) const
{
	if (index < 0 || index >= size)
		throw std::out_of_range("index is out of range");

	N* tmp = head;
	while (index)
	{
		tmp = tmp->next;
		index--;
	}
	return tmp->value;
}

template<typename T, class N>
inline std::ostream& LinkedList<T, N>::print(std::ostream& out) const
{
	N* tmp = head;
	out << "[ ";
	while (tmp)
	{
		out << tmp->value;
		tmp = tmp->next;
		if (tmp)
			out << ", ";
	}
	return out << " ]";
}