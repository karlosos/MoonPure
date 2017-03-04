#pragma once
#include "Input.h"

const int address_length = 32;

class ConsoleAddressInput :
	public Input
{
public:
	ConsoleAddressInput();
	ConsoleAddressInput(std::string input_address);
	~ConsoleAddressInput();
};

