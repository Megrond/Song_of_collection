#pragma once
#include<ctime>

struct Song {
	char name_song[50];
	char text_song[2000];
	char razdelenie[256]{ "==================================" };
	tm deadline;

	void show();
	void fillByUser();
};
