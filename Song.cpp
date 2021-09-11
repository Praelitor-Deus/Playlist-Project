

#include "Song.h"



Song::Song()
{
    songName = "none";
    firstLine = "none";
    playedCount = 0;
}



Song::Song(string newSongName, string newFirstLine, int newPlayedCount)
{
    songName = newSongName;
    firstLine = newFirstLine;
    playedCount = newPlayedCount;
}



Song::~Song()
{}



string Song::getSongName() const
{
    return songName;
}



string Song::getFirstLine() const
{
    return firstLine;
}



int Song::getPlayedCount() const
{
    return playedCount;
}



void Song::setSongName(string newSongName)
{
    songName = newSongName;
}



void Song::setFirstLine(string newFirstLine)
{
    firstLine = newFirstLine;
}



void Song::setPlayedCount(int newPlayedCount)
{
    playedCount = newPlayedCount;
}



void Song::incrementPlayedCount()
{
    playedCount++;
}