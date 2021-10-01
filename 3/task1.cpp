#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int fib_calc(int n, std::vector < int > & cache)
{
	if (cache[n] == 0)
	{
		cache[n] = fib_calc(n - 1, cache) + fib_calc(n - 2, cache);
	}

	return cache[n];
}

int fib(int n)
{
	std::vector < int > cache(n + 1, 0);
	
	cache[0] = 1;
	cache[1] = 1;
	
	return fib_calc(n, cache);
}


int main()
{
	int n;

	std::cin >> n;
	
	std::cout << fib(n) << '\n';

	return 0;
}