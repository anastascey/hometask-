#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

double calculate(double x, double y, std::function < double(double, double) > f)
{
	return f(x, y);
}
int main()
{
	int x;
	int y;

	std::vector < std::function < double(double, double) >> lambdas = { [](double x, double y) { return x + y; }, [](double x, double y) { return x - y; }, 
		[](double x, double y) { return x / y; }, [](double x, double y) { return x * y; } };

	std::cin >> x;
	std::cin >> y;

	for (auto i = 0; i < std::size(lambdas); ++i)
		std::cout << calculate(x, y, lambdas[i]) << '\n';
	return 0;
}