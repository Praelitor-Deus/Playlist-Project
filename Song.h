
#include <iostream>
#include <string>
using namespace std;

class Song
{
private:

    string songName;
    string firstLine;
    int playedCount;

public:

    Song();
    Song(string newSongName, string newFirstLine, int newPlayedCount);
    ~Song();
    string getSongName() const;
    string getFirstLine() const;
    int getPlayedCount() const;
    void setSongName(string newSongName);
    void setFirstLine(string newFirstLine);
    void setPlayedCount(int newPlayedCount);
    void incrementPlayedCount();
};