#include <iostream>
#include <string>
#include "SongArtist.h"

SongArtist::SongArtist(){
}

SongArtist::SongArtist(std::string c_title, std::string c_artist) {
	songTitle = c_title;
	songArtist = c_artist;
}

std::string SongArtist::getTitle() {
	return songTitle;
}
std::string SongArtist::getArtist() {
	return songArtist;
}

void SongArtist::setTitle(std::string title) {
	songTitle = title;
}
void SongArtist::setArtist(std::string artist) {
	songArtist = artist;
}