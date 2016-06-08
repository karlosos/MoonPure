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
