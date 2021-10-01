#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


std::vector < int > merge(std::vector < int >  &left, std::vector < int >  &right)
{
	std::vector < int > array;

	int left_count = 0;
	int right_count = 0;

	while (left_count < std::size(left) && right_count < std::size(right))
	{
		if (left[left_count] <= right[right_count])
		{
			array.push_back(left[left_count]);

			++left_count;
		}

		else
		{
			array.push_back(right[right_count]);

			++right_count;
		}
	}

	while (left_count < std::size(left))
	{
		array.push_back(left[left_count]);

		++left_count;
	}

	while (right_count < std::size(right))
	{
		array.push_back(right[right_count]);

		++right_count;
	}

	return array;
}

std::vector < int > merge_sort(std::vector < int > &array)
{
	if (std::size(array) <= 1)
	{
		return array;
	}	

	std::vector < int > left;

	std::vector < int > right;

	for (auto i = 0; i < std::size(array); ++i)
	{
		if (i < std::size(array) / 2)
		{
			left.push_back(array[i]);
		}
		else
		{
			right.push_back(array[i]);
		}
	}
	
	left = merge_sort(left);

	right = merge_sort(right);

	return merge(left,right);
}

int main()
{

	std::vector < int > array = {888,989,27};

	

	array = merge_sort(array);

	for (auto i = 0; i < std::size(array); ++i)
	{
		std::cout << array[i] << ' ';
	}

	return 0;
}