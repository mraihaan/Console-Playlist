#include <iostream>
#include <string>
#include "SongArtist.h"
#include "Playlist.h"

int main();

int main() {
	std::string command; //user input commands
	int size; //size of playlist

	std::getline(std::cin, command);

	if (command.substr(0,1) == "m") {
		size = std::stoi(command.substr(2));

		Playlist playlist(size);
		
		command = "";
		std::getline(std::cin, command);

		while (command != "exit") {
			if (command.substr(0, 1) == "i") { //add song
				int semicolon = command.find(";");
				std::string titleSong = command.substr(2, semicolon-2);
				std::string artistSong = command.substr(semicolon+1);
				
				SongArtist song(titleSong, artistSong);
				playlist.addSong(song);

			}
			else if (command.substr(0, 1) == "p") { //play song
				int position = std::stoi(command.substr(2));
				playlist.playSong(position);

			}
			else if (command.substr(0, 1) == "e") { //erase song
				int position = std::stoi(command.substr(2));
				playlist.eraseSong(position);
			}

			command = "";
			std::getline(std::cin, command);

		}

		playlist.~Playlist();
	}


}
