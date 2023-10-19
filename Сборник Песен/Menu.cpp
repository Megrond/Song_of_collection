#include "Menu.h"
#include <iostream>
#include "Option.h"

using namespace std;

bool Menu::show()
{
	cout << endl;
	for (size_t i = 0; i < sizeOptions; i++)
	{
		cout << "[" << options[i].num << "] " << options[i].name << endl;
	}
	cout << endl;
	cout << "0 - Выход." << endl;

	request();

	return lastChoise != 0;
}

void Menu::request()
{
	cout << "Выберите пунк меню: ";

	cin >> lastChoise;

	while (!isValid())
	{
		cout << "Указан не существующий пункт меню  ";
		cin >> lastChoise;
	}
}

bool Menu::isValid()
{
	if (lastChoise == 0)
	{
		return true;
	}
	for (size_t i = 0; i < sizeOptions; i++)
	{
		if (options[i].num == lastChoise)
		{
			return true;
		}
	}
	return false;
}

void Menu::add(int num, const char* name)
{
	Option* temp = new Option[sizeOptions + 1];
	for (size_t i = 0; i < sizeOptions; i++)
	{
		temp[i] = options[i];
	}
	temp[sizeOptions] = Option{ name,num };

	delete[] options;
	options = temp;
	sizeOptions++;
}

