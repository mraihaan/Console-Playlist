#include <iostream>
#include <string>
#include "SongArtist.h"

std::string lowercase(std::string str);

class Playlist {
public:
	SongArtist* playlist; //array
	Playlist(int arraySize);
	~Playlist();
	int m_size;
	int m_addPosition = 0; //initial index is 0
	int existingSongs = 0; //initially no songs 
	void addSong(SongArtist songArtist);
	void playSong(int position);
	void eraseSong(int position);
};

