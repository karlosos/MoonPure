#pragma once
#include "Input.h"
#include "Octet.h"
#include "Adress.h"
class IPInput :
	public Input
{
public:
	IPInput();
	~IPInput();
protected:
	Adress ip;
	Adress mask;
	Adress broadcast;
	Adress start_ip;
	Adress end_ip;
	int hosts;
private:
	void getIPAndMaskFromCidr();
	void getIPAndMaskFromTwoAdresses();
	Adress getIPFromString(std::string input_ip_in_string);
	Adress getMaskFromCidr(std::string input_cidr_in_string);
};

