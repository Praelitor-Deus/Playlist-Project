
#include "Song.h"
#include <vector>

class Playlist
{
private:

    vector<Song*> songs;
    string playlistName;

public:

    Playlist();
    Playlist(string newPlaylistName);
    ~Playlist();
    string getPlaylistName();
    vector<Song*> getSongs();
    void addSong(Song* songPtr);
    void removeSong(Song* songPtr);
    void printPlaylist();
};