
#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> test;
	test.add(2);
	test.add(3);
	test.add(4);
	while (true)
	{
		try
		{
			std::cout << test.getValue() << std::endl;
			test.pop();
		}
		catch (std::out_of_range)
		{
			break;
		}
	}

	return 0;
}