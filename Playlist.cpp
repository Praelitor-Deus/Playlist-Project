
#include "Playlist.h"


Playlist::Playlist()
{
    playlistName = "noname";
}


Playlist::Playlist(string newPlaylistName)
{
    playlistName = newPlaylistName;
}


Playlist::~Playlist()
{}


string Playlist::getPlaylistName()
{
    return playlistName;
}


vector<Song*> Playlist::getSongs()
{
    return songs;
}


void Playlist::addSong(Song* songPtr)
{
    songs.push_back(songPtr);
}


void Playlist::removeSong(Song* songPtr)
{
    int index = -1;
    for (unsigned int i = 0; i < songs.size(); i++)
    {
        if (songs.at(i)->getSongName().compare(songPtr->getSongName()) == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        songs.erase(songs.begin() + index);
    }
}


void Playlist::printPlaylist()
{
    for (unsigned int i = 0; i < songs.size(); i++)
    {
        cout << songs.at(i)->getFirstLine() << endl;
        songs.at(i)->incrementPlayedCount();
    }
}