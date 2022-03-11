#include <iostream>
#include <string>
#include "Song.h"

using std::cout;
using std::endl;

Song::Song() {
	songName = "none";
	songFirstLine = "none";
	timesPlayed = 0;
}

void Song::SongName(std::string userNameInput) {
	songName = userNameInput;
}

void Song::FirstLine(std::string userLineInput) {
	songFirstLine = userLineInput;
}

void Song::PrintSong() {
	cout << songName << ": \"" << songFirstLine << "\", " << timesPlayed << " play(s)." << endl;
}

void Song::SongIndex() {
	cout << songName << endl;
}

void Song::PlaySong() {
	cout << songFirstLine << endl;
	timesPlayed++;
}

std::string Song::GetName() {
	return songName;
}
