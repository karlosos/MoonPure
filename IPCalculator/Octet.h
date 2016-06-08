#pragma once
#include <string>
class Octet
{
public:
	Octet();
	Octet(int octet_value);
	~Octet();

	std::string toBinaryString();
	std::string toDecimalString();
	int getValue();
private:
	int octet_value;
	std::string DecToBin(int decimal);
};

