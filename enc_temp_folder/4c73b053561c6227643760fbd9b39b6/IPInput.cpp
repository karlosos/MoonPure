#include "IPInput.h"



IPInput::IPInput()
	: Input("Podaj adres IP i maske: ")
{
	if (this->input_line.find('\\'))
		getIPAndMaskFromCidr();
	else
		getIPAndMaskFromTwoAdresses();
		
}


IPInput::~IPInput()
{
}

void IPInput::getIPAndMaskFromCidr()
{
	std::string input = this->input_line;
	std::string ip = input.substr(0, input.find('//'));
	std::string cidr = input.substr(input.find('//')+1, std::string::npos);

	this->ip = getIPFromString(ip);
	this->mask = getMaskFromCidr(cidr);

}

Adress IPInput::getIPFromString(std::string input_ip_in_string)
{
	std::string ip_string = input_ip_in_string;
	Adress ip;
	int octet_values[4];
	std::string octets_string[4];

	for (int i = 0; i < 4; i++)
	{
		octets_string[i] = ip_string.substr(0, ip_string.find('.'));
		ip_string = ip_string.substr(ip_string.find('.')+1, std::string::npos);
	}

	ip.setOctets(octet_values);

	return ip;
}

Adress IPInput::getMaskFromCidr(std::string input_cidr_in_string)
{
	Adress mask;
	int octet_values[4];

	int cidr = std::stoi(input_cidr_in_string);
	int full_octets = cidr / 8;
	
	for (int i = 0; i < full_octets; i++)
	{
		octet_values[i] = 255;
	}

	if (full_octets < 4)
	{
		int rest = 0;
		if (cidr < 8)
			rest = cidr;
		else
			rest = cidr % 8;

		std::string next_octet = std::string(rest, '1') + std::string(8 - rest, '0');
		octet_values[full_octets] = std::stoi(next_octet, nullptr, 2);
		for (int i = full_octets + 1; i < 4; i++)
		{
			octet_values[i] = 0;
		}
	}

	mask.setOctets(octet_values);

	return mask;
}

void IPInput::getIPAndMaskFromTwoAdresses()
{

}