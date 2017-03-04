#include <iostream>
#include "ConsoleAddressInput.h"
#include "FileInput.h"

int main()
{
	bool isOpen = true;
	const char *menu =
		"1. Oblicz siec dla wprowadzonego adresu i maski\n"
		"2. Oblicz siec (lub sieci) dla wskazanego pliku\n"
		"0. Wyjdz z programu\n";
	ConsoleAddressInput* ip_input;
	FileInput* file_input;

	do {
		system("cls");
		std::cout << menu;
		Input input("Podaj nr akcji:");
		system("cls");

		switch (std::stoi(input.getInputLine())) {
		case 1:
			ip_input = new ConsoleAddressInput;
			delete ip_input;
			system("pause");
			break;
		case 2:
			file_input = new FileInput(input.getLine("Podaj nazwe pliku: "));
			delete file_input;
			system("pause");
			break;
		case 0:
			isOpen = false;
			return 0;
		default:
			break;
		}
	} while (isOpen);

	return 0;
}
