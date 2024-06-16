
#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> test;
	test.add(5);
	test.add(2);
	while (true)
	{
		try
		{
			std::cout << test.first() << "\n";
			test.pop();
		}
		catch (std::out_of_range)
		{
			break;
		}
	}
	while (true)
	{
		try
		{
			test.add(5);
		}
		catch (std::overflow_error)
		{
			std::cout << "Stack is full Stack size: " << test.getSize();
			break;
		}
	}

	return 0;
}