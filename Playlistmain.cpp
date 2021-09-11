
#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;


void printOptions();
void addListOfSongsToLibrary(vector<Song*>& songs);
void listAllSongsInLibrary(vector<Song*> songs);
void addPlaylist(vector<Playlist>& playlists);
void addSongToPlaylist(vector<Playlist>& playlists, vector<Song*> songs);
void listAllPlaylists(vector<Playlist> playlists);
void playPlaylist(vector<Playlist> playlists);
void deletePlaylist(vector<Playlist>& playlists);
void deleteSongFromPlaylist(vector<Playlist>& playlists);
void deleteSongFromLibraryAndAllPlaylists(vector<Playlist>& playlists, vector<Song*>& songs);
void listAllSongs(vector<Song*> songs);

int main()
{
    string choice;
    vector<Song*> songs;
    vector<Playlist> playlists;
    string temp;

    cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;

    do
    {
        cout << endl << "Enter your selection now: ";
        cin >> choice;
        getline(cin, temp);

        if (choice.compare("add") == 0)
        {
            addListOfSongsToLibrary(songs);
        }
        else if (choice.compare("list") == 0)
        {
            listAllSongsInLibrary(songs);
        }
        else if (choice.compare("addp") == 0)
        {
            addPlaylist(playlists);
        }
        else if (choice.compare("addsp") == 0)
        {
            addSongToPlaylist(playlists, songs);
        }
        else if (choice.compare("listp") == 0)
        {
            listAllPlaylists(playlists);
        }
        else if (choice.compare("play") == 0)
        {
            playPlaylist(playlists);
        }
        else if (choice.compare("remp") == 0)
        {
            deletePlaylist(playlists);
        }
        else if (choice.compare("remsp") == 0)
        {
            deleteSongFromPlaylist(playlists);
        }
        else if (choice.compare("remsl") == 0)
        {
            deleteSongFromLibraryAndAllPlaylists(playlists, songs);
        }
        else if (choice.compare("options") == 0)
        {
            printOptions();
        }
        else if (choice.compare("quit") == 0)
        {
            for (unsigned int i = 0; i < songs.size(); ++i)
            {
                delete songs.at(i);
            }

            cout << "Goodbye!" << endl;
        }
        else
        {
            printOptions();
        }
    } while (choice.compare("quit") != 0);


    cout << endl << endl;
    return 0;
}

void printOptions()
{
    cout << endl;
    cout << "add      Adds a list of songs to the library" << endl;
    cout << "list     Lists all the songs in the library" << endl;
    cout << "addp     Adds a new playlist" << endl;
    cout << "addsp    Adds a song to a playlist" << endl;
    cout << "listp    Lists all the playlists" << endl;
    cout << "play     Plays a playlist" << endl;
    cout << "remp     Removes a playlist" << endl;
    cout << "remsp    Removes a song from a playlist" << endl;
    cout << "remsl    Removes a song from the library (and all playlists)" << endl;
    cout << "options Prints this options menu" << endl;
    cout << "quit     Quits the program" << endl;
}


void addListOfSongsToLibrary(vector<Song*>& songs)
{
    string songName;
    string songFirstLine;

    cout << "Enter songs' names and first lines (type \"DONE\" when done):";
    cout << endl << "Song Name: ";
    getline(cin, songName);

    while (songName.compare("DONE") != 0)
    {
        cout << endl << "Song's first line: ";
        getline(cin, songFirstLine);

        Song* pointer = new Song(songName, songFirstLine, 0);
        songs.push_back(pointer);

        cout << endl << "Song Name: ";
        getline(cin, songName);
    }
}

void listAllSongsInLibrary(vector<Song*> songs)
{
    for (unsigned int i = 0; i < songs.size(); ++i)
    {
        cout << songs.at(i)->getSongName() << ": \"" << songs.at(i)->getFirstLine() << "\", "
             << songs.at(i)->getPlayedCount() << " play(s)." << endl;
    }
}

void addPlaylist(vector<Playlist>& playlists)
{
    string playlistName;
    cout << "Playlist name: ";
    getline(cin, playlistName);
    playlists.push_back(playlistName);
}

void addSongToPlaylist(vector<Playlist>& playlists, vector<Song*> songs)
{
    int songIndex = 0;
    int playlistIndex = 0;
    listAllPlaylists(playlists);
    cout << "Pick a playlist index number: ";
    cin >> playlistIndex;
    listAllSongs(songs);
    cout << "Pick a song index number: ";
    cin >> songIndex;
    (playlists.at(playlistIndex)).addSong(songs.at(songIndex));
}

void listAllPlaylists(vector<Playlist> playlists)
{
    for (unsigned int i = 0; i < playlists.size(); ++i)
    {
        cout << " " << i << ": " << (playlists.at(i)).getPlaylistName() << endl;
    }
}

void playPlaylist(vector<Playlist> playlists)
{
    int playlistIndex = 0;
    listAllPlaylists(playlists);
    cout << "Pick a playlist index number: ";
    cin >> playlistIndex;
    cout << endl << "Playing songs from playlist: " << (playlists.at(playlistIndex)).getPlaylistName() << endl;
    (playlists.at(playlistIndex)).printPlaylist();
}

void deletePlaylist(vector<Playlist>& playlists)
{
    int playlistIndex = 0;
    listAllPlaylists(playlists);
    cout << "Pick a playlist index number to remove: ";
    cin >> playlistIndex;
    playlists.erase(playlists.begin() + playlistIndex);
}

void deleteSongFromPlaylist(vector<Playlist>& playlists)
{
    int songIndex = 0;
    int playlistIndex = 0;
    listAllPlaylists(playlists);
    cout << "Pick a playlist index number: ";
    cin >> playlistIndex;
    listAllSongs(playlists.at(playlistIndex).getSongs());
    cout << "Pick a song index number to remove: ";
    cin >> songIndex;
    Song* s = playlists.at(playlistIndex).getSongs().at(songIndex);
    (playlists.at(playlistIndex)).removeSong(s);
}
void deleteSongFromLibraryAndAllPlaylists(vector<Playlist>& playlists, vector<Song*>& songs)
{
    int songIndex = 0;
    listAllSongs(songs);
    cout << "Pick a song index number to remove: ";
    cin >> songIndex;
    Song* s = songs.at(songIndex);

    for (unsigned int i = 0; i < playlists.size(); i++)
    {
        playlists.at(i).removeSong(s);
    }

    songs.erase(songs.begin() + songIndex);
}

void listAllSongs(vector<Song*> songs)
{
    for (unsigned int i = 0; i < songs.size(); ++i)
    {
        cout << " " << i << ": " << songs.at(i)->getSongName() << endl;
    }
}
