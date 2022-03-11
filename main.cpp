//Ryland Hassell, section 2, ryland.hass@gmail.com

#include <iostream>
#include <vector>
#include <limits>
#include "Song.h"
#include "Playlist.h"
#include <string>

using namespace std;


void PrintMenu() {
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
}


void AddSong(vector<Song*>& Library) {
	cout << "Read in Song names and first lines (type \"STOP\" when done): " << endl;
	string nameSong;
	string firstLine;

	while (true) {
		cout << "Song Name: ";
		getline(cin, nameSong);
		if (nameSong == "STOP") {
			cout << endl;
			return;
		}
		cout << "Song's first line: ";
		getline(cin, firstLine);
		Song* songPointer = new Song;

		songPointer->SongName(nameSong);
		songPointer->FirstLine(firstLine);
		Library.push_back(songPointer);
	}
}

void ListSongs(vector<Song*> Library) {
	for (unsigned int i = 0; i < Library.size(); i++) {
		Library.at(i)->PrintSong();
	}
}

void ListSongsIndex(vector<Song*> Library) {
	for (unsigned int i = 0; i < Library.size(); i++) {
		cout << i << ": ";
		Library.at(i)->SongIndex();
	}
}

void QuitProgram(vector<Song*>& Library, vector<Playlist>& playlistLibrary) {
	int songNumber = 0;

	songNumber = Library.size() - 1;
	for (int i = songNumber; i >= 0; i--) {
		delete Library.at(i);
	}
}


void AddPlaylist(vector<Playlist>& playlistLibrary) {
	string userNameInput;

	cout << "Playlist name: " << endl;
	getline(cin, userNameInput);
	Playlist userPlaylist;
	userPlaylist.SetName(userNameInput);
	playlistLibrary.push_back(userPlaylist);
}

void ListPlaylist(vector<Playlist> playlistLibrary) {
	for (unsigned int i = 0; i < playlistLibrary.size(); i++) {
		cout << i << ": ";
		playlistLibrary.at(i).PrintPlaylist();
	}
}

void AddSongToPlaylist(vector<Song*> Library, vector<Playlist>& playlistLibrary) {
	int userPlaylistChoice = 0;
	int userSongChoice = 0;

	ListPlaylist(playlistLibrary);
	cout << "Pick a playlist index number: ";
	cin >> userPlaylistChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ListSongsIndex(Library);
	cout << "Pick a song index number: ";
	cin >> userSongChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	playlistLibrary.at(userPlaylistChoice).PushBack(Library.at(userSongChoice));
}

void PlaySongsInPlaylist(vector<Playlist> playlistLibrary) {
	int userPlaylistChoice = 0;
	int songsInPlaylist = 0;

	ListPlaylist(playlistLibrary);
	cout << "Pick a playlist index number: " << endl;
	cin >> userPlaylistChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Playing first lines of playlist: ";

	playlistLibrary.at(userPlaylistChoice).PrintPlaylist();

	songsInPlaylist = playlistLibrary.at(userPlaylistChoice).NumberOfSongs();

	for (int i = 0; i < songsInPlaylist; i++) {
		playlistLibrary.at(userPlaylistChoice).PlaySong(i);
	}
}



void DeletePlaylist(vector<Playlist>& playlistLibrary) {
	int deleteInput;

	ListPlaylist(playlistLibrary);
	cout << "Pick a playlist index number to delete: " << endl;
	cin >> deleteInput;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	playlistLibrary.erase(playlistLibrary.begin() + deleteInput);
}

void DeleteSongFromPlaylist(vector<Playlist>& playlistLibrary) {
	int userPlaylistChoice = 0;
	int userSongChoice = 0;

	ListPlaylist(playlistLibrary);
	cout << "Pick a playlist index number: " << endl;
	cin >> userPlaylistChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	playlistLibrary.at(userPlaylistChoice).ListSongs();
	cout << "Pick a song index number to delete: " << endl;
	cin >> userSongChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	playlistLibrary.at(userPlaylistChoice).DeleteSong(userSongChoice);
}

void DeleteSongFromLibrary(vector<Song*>& Library, vector<Playlist>& playlistLibrary) {
	int userSongChoice = 0;
	string songDelete = "";
	int songIndexForPlaylist = 0;

	ListSongsIndex(Library);
	cout << "Pick a song index number: " << endl;
	cin >> userSongChoice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	songDelete = Library.at(userSongChoice)->GetName();


	for (unsigned int i = 0; i < playlistLibrary.size(); i++) {
		songIndexForPlaylist = playlistLibrary.at(i).FoundSongIndex(songDelete);
		if (songIndexForPlaylist != -1) {
			playlistLibrary.at(i).DeleteSong(songIndexForPlaylist);
		}
	}


	delete Library.at(userSongChoice);
	Library.erase(Library.begin() + userSongChoice);
}



int main() {
	string userOption;
	vector<Song*> Library;
	int userNum;
	vector<Playlist> playlistLibrary;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

	while (true) {
		cout << "Enter your selection now: " << endl;
		getline(cin, userOption);

		if (userOption == "add") {
			AddSong(Library);
		}
		else if (userOption == "list") {
			ListSongs(Library);
		}
		else if (userOption == "addp") {
			AddPlaylist(playlistLibrary);
		}
		else if (userOption == "addsp") {
			AddSongToPlaylist(Library, playlistLibrary);
		}
		else if (userOption == "listp") {
			ListPlaylist(playlistLibrary);
		}
		else if (userOption == "play") {
			PlaySongsInPlaylist(playlistLibrary);
		}
		else if (userOption == "delp") {
			DeletePlaylist(playlistLibrary);
		}
		else if (userOption == "delsp") {
			DeleteSongFromPlaylist(playlistLibrary);
		}
		else if (userOption == "delsl") {
			DeleteSongFromLibrary(Library, playlistLibrary);
		}
		else if (userOption == "options") {
			PrintMenu();
		}
		else if (userOption == "quit") {
			cout << "Goodbye!";
			QuitProgram(Library, playlistLibrary);
			return 0;
		}
		else {
			PrintMenu();
		}
	}


	return 0;
}