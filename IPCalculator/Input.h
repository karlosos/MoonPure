#pragma once
#include <iostream>
#include <string>
class Input
{
public:
	Input(std::string prompt_message);
	~Input();
protected:
	std::string input_line;
private:
	std::string prompt_message;
};

