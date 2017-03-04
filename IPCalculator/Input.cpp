#include "Input.h"

Input::Input()
{

}

Input::Input(std::string prompt_message)
{
	getLine(prompt_message);
}


Input::~Input()
{
}

std::string Input::getInputLine()
{
	return input_line;
}

std::string Input::getLine(std::string prompt_message)
{
	input_line = "";
	std::cout << prompt_message;
	std::getline(std::cin, this->input_line);
	return input_line;
}