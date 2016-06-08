#pragma once
#include "Octet.h"
class Adress
{
private:
	static const int number_of_octets = 4;
	Octet octets[number_of_octets];

public:
	Adress();
	~Adress();

	void setOctets(int octets_values[number_of_octets]);
	void setOctet(int octet_index, int octet_value);
	int getLastOctet();
	std::string toDecimalString();
	void toArray(int tab[]);
	void setOctetsFromBinaryArray(int adress[]);
};

