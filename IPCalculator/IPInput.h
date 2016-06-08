#pragma once
#include "Input.h"
#include "Octet.h"
#include "Adress.h"
#include <cmath>

class IPInput :
	public Input
{
public:
	IPInput();
	~IPInput();
protected:
	Adress ip;
	Adress mask;
	Adress network;
	Adress broadcast;
	Adress start_ip;
	Adress end_ip;
	int hosts;
private:
	void getIPAndMaskFromCidr();
	void getIPAndMaskFromTwoAdresses();
	Adress getIPFromString(std::string input_ip_in_string);
	Adress getMaskFromCidr(std::string input_cidr_in_string);
	void calculateNetworkAdress();
	void calculateBroadcastAdress();
	void calculateMinAdress();
	void calculateMaxAdress();
	void calculateHosts();
};

