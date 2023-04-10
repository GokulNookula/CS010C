#ifndef Playlist_H
#define Playlist_H
#include <iostream>
#include <string>

using namespace std;


class PlaylistNode
{
    public:

        PlaylistNode();
        PlaylistNode(string, string, string, int);
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*);
        string GetID()const;
        string GetArtistName() const;
        string GetSongName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode();

    private:

        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

class Playlist
{
    public: 
        Playlist(string);
        void OutputFullPlaylist();
        void OutputSongsSpecificArtist();
        void OutputTotalTime();
        void AddSong();
        void RemoveSong();
        void ChangePosition();

    private:
        string title;
        PlaylistNode* head;
        PlaylistNode* tail;
};

#endif

