#include "Input.h"

Input::Input(std::string prompt_message)
{
	input_line = "";
	std::cout << prompt_message;
	std::getline(std::cin, this->input_line);
}


Input::~Input()
{
}
