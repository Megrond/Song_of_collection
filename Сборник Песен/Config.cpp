#include "Config.h"
#include <Windows.h>
#include"Menu.h"

void Config::init(Menu& menu)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu.add(1, "Показать сборник текстов песен");
	menu.add(2, "Добавить текст песни");
	menu.add(3, "Редактировать текст песни");
	menu.add(4, "Удалить текст песни");
	menu.add(5, "Поиск и отображение всех песен одного автора");
	menu.add(6, "Поиск и отображение всех песен, содержащих слово, указанное пользователем");
}
