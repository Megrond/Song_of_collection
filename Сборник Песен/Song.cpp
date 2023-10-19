#include "Song.h"
#include <iostream>
#include <ctime>
using namespace std;

void Song::show()
{
	cout << "Дата: " << deadline.tm_year << endl;
	cout << "Название: " << name_song << endl;
	cout << "Текст песни: " << text_song << endl;
}

void Song::fillByUser()
{
	int int_temp = 0;
	cout << "Укажите год: ";
	cin >> int_temp;
	deadline.tm_year = int_temp;
	cout << "Укажите название: ";
	cin >> name_song;
	cout << "Текст песни: ";
	cin >> text_song;
}
