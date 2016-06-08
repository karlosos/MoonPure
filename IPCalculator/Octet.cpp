#include "Octet.h"



Octet::Octet(int octet_value)
{
	this->octet_value = octet_value;
}


Octet::~Octet()
{
}

std::string Octet::toBinaryString()
{
	std::string binary = DecToBin(this->octet_value);
	int to_fill = 8 - binary.length();

	if (to_fill > 0)
		binary = std::string(to_fill, '0') + binary;

	return binary;
}

std::string Octet::toDecimalString()
{
	return std::to_string(this->octet_value);
}

int Octet::getValue()
{
	return 0;
}

std::string Octet::DecToBin(int decimal)
{
	int number = decimal;
	std::string binary = "";

	if (number == 0)
		return "0";

	while (number)
	{
		if (number % 2 == 0)
			binary = "0" + binary;
		else
			binary = "1" + binary;
		number /= 2;
	}

	return binary;
}