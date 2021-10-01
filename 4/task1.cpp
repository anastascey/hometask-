#include<iostream>
#include<string>
#include<vector>

enum class Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

void number_of_days(Month numb)
{
	switch (numb)
	{
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::July:
	case Month::August:
	case Month::October:
	case Month::December:
		std::cout << "31";
		break;

	case Month::April:
	case Month::June:
	case Month::September:
	case Month::November:
		std::cout << "30";
		break;
	case Month::February:
		std::cout << "28 or 29";
		break;
	default:
		std::cout << "Month doesn't exist";
		break;
	}
}

int main()
{
	int numb;
	std::cin >> numb;
	number_of_days(static_cast<Month> (numb));
	return 0;
}