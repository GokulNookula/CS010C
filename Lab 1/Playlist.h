#ifndef Playlist_H
#define Playlist_H

#include <iostream>
#include <string>

using namespace std;

class PlaylistNode
{
    public:

        // Default constructor
        PlaylistNode();

        // Parameterized constructor
        PlaylistNode(string id, string songName, string artistName, int length);

        // Insert a node after this node
        void InsertAfter(PlaylistNode* node);

        // Set the next node pointer
        void SetNext(PlaylistNode* node);

        // Getter methods for private member variables
        string GetID() const;
        string GetArtistName() const;
        string GetSongName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;

        // Print the details of this node
        void PrintPlaylistNode();

    private:

        // Private member variables
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

class Playlist
{
    public: 

        // Parameterized constructor
        Playlist(string playlistTitle);

        // Output the full playlist
        void OutputFullPlaylist();

        // Output all songs by a specific artist
        void OutputSongsSpecificArtist();

        // Output the total time of the playlist in seconds
        void OutputTotalTime();

        // Add a song to the playlist
        void AddSong();

        // Remove a song from the playlist
        void RemoveSong();

        // Change the position of a song in the playlist
        void ChangePosition();

    private:

        // Private member variables
        string title;
        PlaylistNode* head;
        PlaylistNode* tail;
};

#endif
