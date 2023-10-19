#pragma once
#include "Song.h"
#include"SongCollection.h"

struct  SongCollection {
	Song* Songs;
	size_t size;

	void show();
	void add(Song song);
	void addByUser();
	void saveSong();
	void loadSong();
	void editSong();
	void searchSongName();
	void deleteByUser();
	void deleteData(int num);
};
