#include "Song.h"
#include <iostream>
#include <ctime>
using namespace std;

void Song::show()
{
	cout << "����: " << deadline.tm_year << endl;
	cout << "��������: " << name_song << endl;
	cout << "����� �����: " << text_song << endl;
}

void Song::fillByUser()
{
	int int_temp = 0;
	cout << "������� ���: ";
	cin >> int_temp;
	deadline.tm_year = int_temp;
	cout << "������� ��������: ";
	cin >> name_song;
	cout << "����� �����: ";
	cin >> text_song;
}
