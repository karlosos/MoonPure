#pragma once

#include "Octet.h"
#include "Adress.h"
#include <cmath>
#include <iostream>
#include <fstream>

class NetworkInfo
{
public:
	NetworkInfo();
	~NetworkInfo();
	void calculateNetworkInfoFromAddress(std::string* input_address);
	void printAllInfo();
protected:
	Adress ip;
	Adress mask;
	Adress network;
	Adress broadcast;
	Adress start_ip;
	Adress end_ip;
	int hosts;
private:
	void getIPAndMaskFromCidr(std::string input_address);
	void getIPAndMaskFromTwoAdresses(std::string input_address);
	Adress getIPFromString(std::string input_ip_in_string);
	Adress getMaskFromCidr(std::string input_cidr_in_string);
	void calculateNetworkAdress();
	void calculateBroadcastAdress();
	void calculateMinAdress();
	void calculateMaxAdress();
	void calculateHosts();
	void logAllInfo();
};