#include "SongCollection.h"
#include "Song.h"
#include "Menu.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;

void SongCollection::show()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "--------------" << i + 1 << " Песня--------------" << endl;
		Songs[i].show();
		cout << endl;
	}
}

void SongCollection::addByUser()
{
	Song temp{};
	temp.fillByUser();
	add(temp);
}

void SongCollection::add(Song song)
{
	Song* temp = new Song[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = Songs[i];
	}
	delete[] Songs;
	Songs = temp;

	Songs[size] = song;
	size++;
}

void SongCollection::saveSong()
{
	FILE* db_file{};
	fopen_s(&db_file, "Collection_of_song.txt", "w");
	if (db_file == NULL)
	{
		cout << "Ошибка сохранения в файл";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		fprintf(db_file, "%d\n", Songs[i].deadline.tm_year);
		fprintf(db_file, "%s\n", Songs[i].name_song);
		fprintf(db_file, "%s\n", Songs[i].text_song);
		fprintf(db_file, "%s\n", Songs[i].razdelenie);
	}
	if (fclose(db_file) == EOF)
	{
		cout << "Ошибка закрытия файла";
	}
	return;
}

void SongCollection::loadSong()
{
	FILE* db_file{};
	fopen_s(&db_file, "Collection_of_song.txt", "r");
	if (db_file == NULL)
	{
		cout << "Ошибка открытия файла";
		return;
	}
	Song temp{};
	int scan_result;
	while (true)
	{
		scan_result = fscanf_s(db_file, "%d", &temp.deadline.tm_year);
		if (scan_result == EOF)
		{
			break;
		}
		scan_result = fscanf_s(db_file, "%s", &temp.name_song, 256);
		if (scan_result == EOF)
		{
			break;
		}
		scan_result = fscanf_s(db_file, "%s", temp.text_song, 256);
		if (scan_result == EOF)
		{
			break;
		}
		scan_result = fscanf_s(db_file, "%s", temp.razdelenie, 256);
		if (scan_result == EOF)
		{
			break;
		}
		add(temp);
	}
	if (fclose(db_file) == EOF)
	{
		cout << "Ошибка закрытия файла";
	}
}
void SongCollection::editSong()
{
	cout << "Укажите название песни для редактирования: ";
	char needle[256]{};
	cin >> needle;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(needle, Songs[i].name_song) == 0)
		{
			cout << "Введите новый текст: ";
			cin >> Songs[i].text_song;

			cout << "Текст песни успешно отредактирован." << endl;
		}
	}
}
void SongCollection::searchSongName()
{
	cout << "Укажите дату задачи: ";
	char needle[256]{};
	cin >> needle;

	int flag = 1;
	for (size_t i{}; i < size; i++)
	{
		if (strcmp(needle, Songs[i].name_song) == 0)
		{
			cout << "=========" << flag++ << " совпадение" << "=========" << endl;
			Songs[i].show();
		}
	}
}
//void TaskCollection::deleteData()
//{
//	cout << "Укажите название задачи: ";
//	char needle[256]{};
//	cin >> needle;
//
//	for (size_t i{}; i < size; i++)
//	{
//		if (strcmp(needle, Tasks[i].name) == 0)
//		{
//			
//		}
//	}
//}
//void TaskCollection::load()
//{
//	ifstream in("db.txt");
//	if (!in.is_open())
//	{
//		cout << "Ошибка открытия файла1";
//		return;
//	}
//
//	Task temp{};
//	char line[256]{};
//	while (!in.eof())
//	{
//		in >> temp.deadline.tm_year >> temp.deadline.tm_mon
//			>> temp.deadline.tm_mday >> temp.deadline.tm_hour >> temp.deadline.tm_min;
//		in >> temp.priority;
//		in >> temp.name;
//		in >> temp.opisanie;
//
//
//	}
//	add(temp);
//
//	in.close();
//
//	return;
//}

