#include "Adress.h"

Adress::Adress()
{
}


Adress::~Adress()
{
}

void Adress::setOctets(int octets_values[number_of_octets])
{
	for (int i = 0; i < number_of_octets; i++)
	{
		this->octets[i] = Octet(octets_values[i]);
	}
}

void Adress::setOctet(int octet_index, int octet_value)
{
	this->octets[octet_index] = Octet(octet_value);
}

std::string Adress::toDecimalString()
{
	std::string adress_in_string = "";
	for (int i = 0; i < number_of_octets; i++)
	{
		if (i > 0)
			adress_in_string += ".";
		adress_in_string += this->octets[i].toDecimalString();
	}
	return adress_in_string;
}

void Adress::toArray(int tab[32])
{
	int binary[32];
	size_t index = 0;
	for (int i = 0; i < number_of_octets; i++) {
		std::string binary_octet = this->octets[i].toBinaryString();
		for (int j = 0; j < binary_octet.size(); j++) {
			binary[index++] = binary_octet.at(i) - '0';
		}
	}

	for (int i = 0; i < 32; i++) {
		tab[i] = binary[i];
	}
}