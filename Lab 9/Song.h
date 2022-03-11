#ifndef SONG_H
#define SONG_H

class Song {
public:
	Song();
	void SongName(std::string userNameInput);
	void FirstLine(std::string userLineInput);
	void PrintSong();
	void SongIndex();
	void PlaySong();
	std::string GetName();
private:
	std::string songName;
	std::string songFirstLine;
	int timesPlayed;
};

#endif