#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector < std::function < bool(int, int) > > lambdas = { [](int x, int y) {return y > x; } ,[](int x, int y) {return x > y; } };

	std::vector < int > array = { 102,34,21,90 };

	std::sort(array.begin(), array.end(), lambdas[0]);

	for (auto i = 0; i < std::size(array); ++i)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';

	std::sort(array.begin(), array.end(), lambdas[1]);

	for (auto i = 0; i < std::size(array); ++i)
	{
		std::cout << array[i] << ' ';
	}

	return 0;
}
