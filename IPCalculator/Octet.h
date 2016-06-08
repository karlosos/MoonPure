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
	int Octet::BinToDec(std::string binary);
	std::string DecToBin(int decimal);
private:
	int octet_value;
};

