#include <iostream>
#include <string>
#include "Playlist.h"

Playlist::Playlist(int arraySize) {
	m_size = arraySize;

	playlist = new SongArtist[m_size]{}; //DMA
	std::cout << "success" << std::endl;
}
void Playlist::addSong(SongArtist songArtist) {
	if (m_addPosition < m_size) { //check if playlist is full
		for (int i = 0; i < m_size; i++) { //check if it exists in playlist
			if ((lowercase(playlist[i].getTitle()) == lowercase(songArtist.getTitle())) && (lowercase(playlist[i].getArtist()) == lowercase(songArtist.getArtist()))) {
				std::cout << "can not insert " << songArtist.getTitle() << ";" << songArtist.getArtist() << std::endl;
				return;
			}
		}
		playlist[m_addPosition] = songArtist; //insertion
		m_addPosition++;
		existingSongs++;
		std::cout << "success" << std::endl;
		return;

	}
	else {
		std::cout << "can not insert " << songArtist.getTitle() << ";" << songArtist.getArtist() << std::endl;
		return;

	}
}
void Playlist::playSong(int position) {
	if ((position < 1) || (position > existingSongs) || (position > m_addPosition)) {
		std::cout << "can not play " << position << std::endl;
	}
	else {
		std::cout << "played " << position << " " << playlist[position - 1].getTitle() << ";" << playlist[position - 1].getArtist() << std::endl;
	}

}
void Playlist::eraseSong(int position) {
	if ((position < 1) || (position > existingSongs)) {
		std::cout << "can not erase " << position << std::endl;
		return;
	}
	else {
		existingSongs--;

		for (int i = position - 1; i < existingSongs; i++) {
			playlist[i] = playlist[i + 1];
		}

		playlist[m_addPosition - 1].setTitle(""); //make it empty
		playlist[m_addPosition - 1].setArtist(""); //make it empty


		m_addPosition--;

		std::cout << "success" << std::endl;

	}


}
Playlist::~Playlist() {
	delete[] playlist;
	playlist = nullptr;
}

std::string lowercase(std::string str) {
	for (std::size_t i = 0; i < str.length(); i++) {
		str[i] = std::tolower(str[i]);
	}

	return str;
}