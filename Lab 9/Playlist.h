#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"
#include <vector>

class Playlist {
public:
	Playlist();
	void SetName(std::string userNameInput);
	void PrintPlaylist();
	void PushBack(Song* SongPointer);
	int NumberOfSongs();
	void PlaySong(int index);
	void ListSongs();
	void DeleteSong(int songChoice);
	int FoundSongIndex(std::string deleteSong);

private:
	std::string playlistName;
	std::vector<Song*> playlistSongs;
};


#endif