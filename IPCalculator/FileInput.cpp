#include "FileInput.h"



FileInput::FileInput(std::string file_name)
{
	std::ifstream file;
	std::string line;
	file.open(file_name);
	NetworkInfo* network_info;

	if (file.is_open()) {
		while (std::getline(file, line))
		{
			network_info = new NetworkInfo();
			network_info->calculateNetworkInfoFromAddress(&line);
			network_info->printAllInfo();
			delete network_info;
		}
		file.close();
	}
}


FileInput::~FileInput()
{
}
