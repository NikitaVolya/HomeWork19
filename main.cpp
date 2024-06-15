
#include <iostream>
#include "SingleLinkedListe.h"

int main()
{
	SingleLinkedList<int> test {1, 5, 4, 9};
	while (true)
	{
		try
		{
			std::cout << test.first() << " ";
			test.pop();
		}
		catch (std::out_of_range)
		{
			break;
		}
	}

	return 0;
}