#pragma once
#include <iostream>
#include <string>
class Input
{
public:
	Input();
	Input(std::string prompt_message);
	~Input();
	std::string getInputLine();
	std::string getLine(std::string prompt_message);
protected:
	std::string input_line;
private:
	std::string prompt_message;
};

