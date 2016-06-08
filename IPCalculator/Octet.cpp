#include "Octet.h"


Octet::Octet()
{
	this->octet_value = 0;
}

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
	return this->octet_value;
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

int Octet::BinToDec(std::string binary)
{
	int pos = binary.find('1');
	if (pos < 0)
		pos = 0;

	binary = binary.substr(pos, std::string::npos);
	int x;	
	int power = 1;
	int length = binary.length();
	int system = 2;
	int result = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		if (binary[i] == '1') x = 1;
		if (binary[i] == '0') x = 0;
		result += x * power;

		power *= system;
	}
	return result;
}