#include <iostream>
#include <string>
#include <vector> 

int main()
{
	int  enter, size;
	std::vector < int > array;

	std::cout << "Enter the size of the array" << '\n';

	std::cin >> size;

	std::cout << "Enter the array" << '\n';

	for (auto i = 0; i < size; ++i)
	{
		std::cin >> enter;
		array.push_back(enter);
	}
	
	for (auto i = 0; i < size-1; ++i)
	{
		for (auto j = i + 1; j > 0; --j)
		{
			if (array[j] < array[j - 1])
			{
				std::swap(array[j], array[j - 1]);
			}
		}
	}

	for (auto i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}

	return 0;
}