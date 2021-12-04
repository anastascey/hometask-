#include <iostream>
#include <vector>
#include <type_traits>
#include <functional>
#include <random>
#include <chrono>

template <typename T,std::size_t N, typename Compare>

void merge1(T(&array) [N], int left, int middle, int right, Compare f)
{
	T* container = new T[right - left];

	int right_count = middle;
	int left_count = left;
	int index = 0;

	while (left_count < middle && right_count < right)
	{
		if (f(array[left_count], array[right_count]))
		{
			container[index] = array[left_count];

			++left_count;

			++index;
		}

		else
		{
			container[index] = array[right_count];

			++right_count;

			++index;
		}
	}

	while (left_count < middle)
	{
		container[index] = array[left_count];

		++left_count;

		++index;
	}

	while (right_count < right)
	{
		container[index] = array[right_count];

		++right_count;

		++index;
	}

	for (auto i = left; i < right; ++i)
	{
		array[i] = container[i - left];
	}

	delete[] container;
}

template <typename T, std::size_t N, typename Compare>

void merge_sort1(T(&array)[N], int left, int right, Compare f)
{
	if (right - left > 1)
	{
		auto middle = (left + right) / 2;

		merge_sort1(array, left, middle, f);

		merge_sort1(array, middle, right, f);

		merge1(array, left, middle, right, f);
	}
}

template <typename T, typename Compare>

void merge(T* array, int left, int middle, int right, Compare f = [](T x) {return x < y; })
{
	T *container = new T[right-left];

	int right_count = middle;
	int left_count = left;
	int index = 0;

	while (left_count < middle && right_count < right)
	{
		if (f(array[left_count],array[right_count]))
		{
			container[index] = array[left_count];

			++left_count;

			++index;
		}

		else
		{
			container[index] = array[right_count];

			++right_count;

			++index;
		}
	}

	while (left_count < middle)
	{
		container[index] = array[left_count];

		++left_count;

		++index;
	}

	while (right_count < right)
	{
		container[index] = array[right_count];

		++right_count;

		++index;
	}

	for (auto i = left; i < right; ++i)
	{
		array[i] = container[i - left];
	}

	delete[] container;
}

template <typename T, typename Compare>

void merge_sort(T* array, int left, int right, Compare f)
{
	if (right - left > 1)
	{
		auto middle = (left + right) / 2;

		merge_sort(array, left, middle, f);

		merge_sort(array, middle, right, f);

		merge(array, left, middle, right, f);
	}
}

bool f(double x, double y)
{
	return x > y;
}

int main()
{
	int  size;

	const int s = 10;

	std::cin >> size;

	double* array = new double[size];

	double array1[s] = {};

	for (auto i = 0; i < size; ++i)
	{
		array[i] = double(i);
	}

	for (auto i = 0; i < s; ++i)
	{
		array1[i] = double(i);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(array, array+size, std::default_random_engine(seed));

	std::shuffle(array1, array1 + s, std::default_random_engine(seed));

	std::for_each(array, array + size, [](auto x) {std::cout << x << ' '; });

	std::cout << std::endl;

	std::for_each(array1, array1 + s, [](auto x) {std::cout << x << ' '; });

	std::cout << std::endl;

	merge_sort<double>(array, 0, size, [](double x, double y) {return x < y; });

	std::for_each(array, array + size,[](auto x) {std::cout << x << ' '; });

	std::cout << std::endl;

	merge_sort1<double>(array1, 0, s, [](double x, double y) {return x > y; });

	std::for_each(array1, array1 + s, [](auto x) {std::cout << x << ' '; });

	return 0;
}