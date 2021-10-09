#include "headphones.hpp"

void Headphones::print()
{
	std::cout << name << '\n';
	std::cout << "Impedance: " << impedance << " Om" << '\n';
	std::cout << "Frequency range: " << minimum_frequency << " - " << maximum_frequency << " Hz" << '\n';
}

const std::string & Headphones::get_name() const
{
	return name;
}

std::vector <double>  Headphones::get_specifications()
{
	std::vector <double> specifications = { impedance ,minimum_frequency,maximum_frequency };

	return specifications;
}
