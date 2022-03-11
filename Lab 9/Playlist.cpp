#include <string>
#include <iostream>
#include <vector>
#include "Playlist.h"

using std::cout;
using std::endl;

Playlist::Playlist() {
	playlistName = "none";
}

void Playlist::SetName(std::string userName) {
	playlistName = userName;
}

void Playlist::PrintPlaylist() {
	cout << playlistName << endl;
}

void Playlist::PushBack(Song* SongPointer) {
	playlistSongs.push_back(SongPointer);
}

int Playlist::NumberOfSongs() {
	int numSongs = 0;
	numSongs = playlistSongs.size();
	return numSongs;
}

void Playlist::PlaySong(int index) {
	playlistSongs.at(index)->PlaySong();
}

void Playlist::ListSongs() {
	for (unsigned int i = 0; i < playlistSongs.size(); i++) {
		cout << i << ": ";
		playlistSongs.at(i)->SongIndex();
	}
}

void Playlist::DeleteSong(int userSong) {
	playlistSongs.erase(playlistSongs.begin() + userSong);
}

int Playlist::FoundSongIndex(std::string deleteSong) {
	for (unsigned int i = 0; i < playlistSongs.size(); i++) {
		if (playlistSongs.at(i)->GetName() == deleteSong) {
			return i;
		}
	}
	return -1;
}