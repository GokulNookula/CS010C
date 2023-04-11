#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

//Default constructor for if nothing is passed for input in PlaylistNode
PlaylistNode::PlaylistNode() : 
uniqueID("none"),
songName("none"),
artistName("none"),
songLength(0),
nextNodePtr(nullptr) {}

//Constructor where if all the variables are passed in for the node
PlaylistNode::PlaylistNode(string newUniqueID, string newSongName,string newArtistName, int newSongLength)
{
    uniqueID = newUniqueID;
    songName = newSongName;
    artistName = newArtistName;
    songLength = newSongLength;
    nextNodePtr = nullptr;
}

//Accesses the variable uniqueID and returns us the string value
string PlaylistNode::GetID() const
{
    return uniqueID;
}

//Accesses the variable artistName and returns us the string value
string PlaylistNode::GetArtistName() const
{
    return artistName;
}

//Accesses the variable songName and returns us the string value
string PlaylistNode::GetSongName() const
{
    return songName;
}

//Accesses the variable songLength and returns us the int value
int PlaylistNode::GetSongLength() const
{
    return songLength;
}

//This mainly used in order to get the next node of the linked list
PlaylistNode* PlaylistNode::GetNext() const
{
    return nextNodePtr;
}

// We are trying to print all the data that is inside the node to the console
void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}


void PlaylistNode::InsertAfter(PlaylistNode* newNode)
{
    newNode->SetNext(nextNodePtr);
    nextNodePtr = newNode;
}

void PlaylistNode::SetNext(PlaylistNode* newNode)
{
    nextNodePtr = newNode;
}

Playlist::Playlist(string newTitle)
{
    title = newTitle;
    head = nullptr;
    tail = head;
}

void Playlist::OutputFullPlaylist()
{
    int count = 1;
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
    if(head != nullptr)
    {

        for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
        {
            cout << count << "." << endl;
            i->PrintPlaylistNode();
            if (i != tail)
            {
                cout << endl;
            }
            count++;
        }
    }
    else
    {
        cout << "Playlist is empty" << endl;
    }
}

void Playlist::AddSong()
{
    string newUniqueID;
    string newSongName;
    string newArtistName;
    int newSongLength = 0;

    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> newUniqueID;
    cin.ignore();
    cout << "Enter song's name:" << endl;
    getline(cin,newSongName);
    cout << "Enter artist's name:" << endl;
    getline(cin,newArtistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> newSongLength;

    PlaylistNode* newNode = new PlaylistNode(newUniqueID,newSongName,newArtistName,newSongLength);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->InsertAfter(newNode);
        tail = newNode;
    }

}

void Playlist::RemoveSong()
{
    string userUniqueID;    

    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> userUniqueID;

    PlaylistNode* previousNode = head;

    for (PlaylistNode* currentNode = head->GetNext(); currentNode != nullptr; currentNode = currentNode->GetNext())
    {
        if (currentNode->GetID() == userUniqueID)
        {
            cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
            PlaylistNode* temp = currentNode;
            previousNode->SetNext(currentNode->GetNext());
            delete temp;
            currentNode = previousNode->GetNext();
        }
    }
}

void Playlist::OutputTotalTime()
{
    int total = 0;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
    {
        total += i->GetSongLength();
    }
    cout << "Total time: " << total << " seconds" << endl;
}

void Playlist::OutputSongsSpecificArtist() //fix me
{
    string userArtistName;
    int count = 1;

    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name" << endl;
    cin >> userArtistName;

    if (head != nullptr)
    {
        for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
        {
            if (i->GetArtistName() == userArtistName)
            {
                cout << count << "." << endl;
                i->PrintPlaylistNode();
                cout << endl;
                count++;
            }
        }   
    }
}

void Playlist::ChangePosition() 
{
    int oldPos;
    int newPos;
    int length = 0;

    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> oldPos;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;

    if (head == nullptr)
    {
        return;
    }

    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
    {
        length++;
    }
    if (oldPos < 1 || oldPos > length || newPos < 1 || newPos > length)
    {
        cout << "Invalid position entered." << endl;
        return;
    }

    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;
    for (int i = 1; i < oldPos; i++)
    {
        prev = curr;
        curr = curr->GetNext();
    }

    if (curr != nullptr)
    {
        if (prev == nullptr) //Moving the head node
        {
            head = curr->GetNext();
        }
        else
        {
            prev->SetNext(curr->GetNext());
        }
        if (curr == tail) // Moving the tail node
        {
            tail = prev;
        }
        PlaylistNode* previousNewNode = nullptr;
        PlaylistNode* currNode = head;
        for (int i = 1; i < newPos; i++)
        {
            previousNewNode = currNode;
            currNode = currNode->GetNext();
        }
        if (previousNewNode == nullptr)
        {
            curr->SetNext(head);
            head = curr;
        }
        else
        {
            previousNewNode->InsertAfter(curr);
        }
        if (currNode == nullptr)
        {
            tail = curr;
        }
        cout << "\"" << curr->GetSongName() << "\" moved to position " << newPos << endl;
    }
    else
    {
        cout << "Invalid" << endl;
        return;
    }
}
