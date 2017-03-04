#include "NetworkInfo.h"

NetworkInfo::NetworkInfo()
{
}

NetworkInfo::~NetworkInfo()
{
}

void NetworkInfo::calculateNetworkInfoFromAddress(std::string* input_address)
{
	int pos = input_address->find('/');
	if (pos > 0)
		getIPAndMaskFromCidr(*input_address);
	else
		getIPAndMaskFromTwoAdresses(*input_address);

	calculateNetworkAdress();
	calculateBroadcastAdress();
	calculateHosts();
	calculateMinAdress();
	calculateMaxAdress();
}

void NetworkInfo::printAllInfo()
{
	std::cout << "IP: " << this->ip.toDecimalString() << std::endl;
	std::cout << "Mask: " << this->mask.toDecimalString() << std::endl;
	std::cout << "Network: " << this->network.toDecimalString() << std::endl;
	std::cout << "Broadcast: " << this->broadcast.toDecimalString() << std::endl;
	std::cout << "Ilosc hostow: " << this->hosts << std::endl;
	std::cout << "Min adres: " << this->start_ip.toDecimalString() << std::endl;
	std::cout << "Max adres: " << this->end_ip.toDecimalString() << std::endl;
	std::cout << "==============================" << std::endl << std::endl;

	logAllInfo();
}

void NetworkInfo::logAllInfo()
{
	std::ofstream file("log.txt", std::ios::app);
	if (file.is_open())
	{
		file << "IP: " << this->ip.toDecimalString() << std::endl;
		file << "Mask: " << this->mask.toDecimalString() << std::endl;
		file << "Network: " << this->network.toDecimalString() << std::endl;
		file << "Broadcast: " << this->broadcast.toDecimalString() << std::endl;
		file << "Ilosc hostow: " << this->hosts << std::endl;
		file << "Min adres: " << this->start_ip.toDecimalString() << std::endl;
		file << "Max adres: " << this->end_ip.toDecimalString() << std::endl;
		file << "==============================" << std::endl << std::endl;
		file.close();
	}
}

void NetworkInfo::getIPAndMaskFromCidr(std::string input_address)
{
	std::string input = input_address;
	std::string ip = input.substr(0, input.find('/'));
	std::string cidr = input.substr(input.find('/') + 1, std::string::npos);

	this->ip = getIPFromString(ip);
	this->mask = getMaskFromCidr(cidr);
}

Adress NetworkInfo::getIPFromString(std::string input_ip_in_string)
{
	std::string ip_string = input_ip_in_string;
	Adress ip;
	int octet_values[4];
	std::string octets_string[4];

	for (int i = 0; i < 4; i++)
	{
		octets_string[i] = ip_string.substr(0, ip_string.find('.'));
		octet_values[i] = std::stoi(octets_string[i]);
		ip_string = ip_string.substr(ip_string.find('.') + 1, std::string::npos);
	}

	ip.setOctets(octet_values);

	return ip;
}

Adress NetworkInfo::getMaskFromCidr(std::string input_cidr_in_string)
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

void NetworkInfo::getIPAndMaskFromTwoAdresses(std::string input_address)
{
	std::string input = input_address;
	std::string ip = input.substr(0, input.find(' '));
	std::string cidr = input.substr(input.find(' ') + 1, std::string::npos);

	this->ip = getIPFromString(ip);
	this->mask = getIPFromString(cidr);
}

void NetworkInfo::calculateNetworkAdress()
{
	int ip_binary[32];
	this->ip.toArray(ip_binary);

	int mask_binary[32];
	this->mask.toArray(mask_binary);

	for (int i = 0; i < 32; i++)
	{
		if (mask_binary[i] == 0)
			ip_binary[i] = 0;
	}

	this->network.setOctetsFromBinaryArray(ip_binary);
}

void NetworkInfo::calculateBroadcastAdress()
{
	int ip_binary[32];
	this->ip.toArray(ip_binary);

	int mask_binary[32];
	this->mask.toArray(mask_binary);

	for (int i = 0; i < 32; i++)
	{
		if (mask_binary[i] == 0)
			ip_binary[i] = 1;
	}

	this->broadcast.setOctetsFromBinaryArray(ip_binary);
}

void NetworkInfo::calculateHosts()
{
	int mask[32];
	this->mask.toArray(mask);
	int number_of_zeroes = 0;
	for (int i = 0; i < 32; i++) {
		if (mask[i] == 0)
			number_of_zeroes++;
	}

	this->hosts = pow(2, number_of_zeroes) - 2;
}

void NetworkInfo::calculateMinAdress()
{
	this->start_ip = this->network;
	this->start_ip.setOctet(3, this->network.getLastOctet() + 1);
}

void NetworkInfo::calculateMaxAdress()
{
	this->end_ip = this->broadcast;
	this->end_ip.setOctet(3, this->broadcast.getLastOctet() - 1);
	int x = this->broadcast.getLastOctet();
	int y = 3;
}
