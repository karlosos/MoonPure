#include "ConsoleAddressInput.h"
#include "NetworkInfo.h"

ConsoleAddressInput::ConsoleAddressInput()
	: Input("Podaj adres IP i maske: ")
{
	NetworkInfo network_info;
	network_info.calculateNetworkInfoFromAddress(&this->input_line);
	network_info.printAllInfo();
}

ConsoleAddressInput::ConsoleAddressInput(std::string input_address)
	: Input()
{
	NetworkInfo network_info;
	network_info.calculateNetworkInfoFromAddress(&this->input_line);
	network_info.printAllInfo();
}


ConsoleAddressInput::~ConsoleAddressInput()
{
}