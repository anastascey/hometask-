#pragma once

#include<iostream>
#include<string>
#include<vector>

class Headphones
{
public:

	Headphones() :name("Noname"), impedance(5.0), minimum_frequency(30.0), maximum_frequency(22000.0)
	{}

	Headphones(const std::string& n, double im, double mif, double maf) :name(n), impedance(im), minimum_frequency(mif), maximum_frequency(maf)
	{}

	~Headphones()
	{}

	void print();

	const std::string& get_name() const;

	std::vector <double> get_specifications();

private:
	std::string name;
	double impedance;
	double minimum_frequency;
	double maximum_frequency;

};