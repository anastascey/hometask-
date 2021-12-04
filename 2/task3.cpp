#include <iostream>
#include <string>
#include <vector>

int main()
{
	int  enter, size, left, right, middle, x;
	std::vector < int > array;

	std::cout << "Enter the size of the array" << '\n';

	std::cin >> size;

	std::cout << "Enter the array" << '\n';

	for (auto i = 0; i < size; ++i)
	{
		std::cin >> enter;
		array.push_back(enter);
	}
	
	std::cout << "Enter the number" << '\n';

	std::cin >> x;

	left = 0;
	right = size;

	while (right - left > 1)
	{
		middle = (right + left) / 2;

		if (array[middle] < x)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}
	}
	if (right < size and array[right] == x)
	{
		std::cout << "Position:" << right + 1 << '\n';
	}
	else
	{
		std::cout << "Not found" << '\n';
	}
	return 0;
}