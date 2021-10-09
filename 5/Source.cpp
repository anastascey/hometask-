#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#include "headphones.hpp"

int main()
{
	Headphones hp("HD599", 50, 12, 38500);

	std::vector <double> specifications = hp.get_specifications();

	hp.print();

	std::cout << hp.get_name() << '\n';

	std::for_each(std::begin(specifications), std::end(specifications), [](double x) {std::cout << x << '\n'; });

	return 0;
}