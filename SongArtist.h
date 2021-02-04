#ifndef SONGARTIST
#define SONGARTIST

#include <iostream>
#include <string>

class SongArtist {
private:
	std::string songTitle;
	std::string songArtist;
public:
	SongArtist();
	SongArtist(std::string c_title, std::string c_artist);

	void setTitle(std::string title);
	void setArtist(std::string artist);

	std::string getTitle();
	std::string getArtist();
}; 

#endif