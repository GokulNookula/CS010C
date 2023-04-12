#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

// Default constructor for PlaylistNode when nothing is passed in.
PlaylistNode::PlaylistNode() : 
uniqueID("none"),
songName("none"),
artistName("none"),
songLength(0),
nextNodePtr(nullptr) {}

// Constructor for PlaylistNode when all variables are passed in.
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

// This function is used to get the next node of the linked list.
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

// This function inserts a new node after the current node.
void PlaylistNode::InsertAfter(PlaylistNode* newNode)
{
    newNode->SetNext(nextNodePtr);
    nextNodePtr = newNode;
}

// This function sets the next node pointer to a new node.
void PlaylistNode::SetNext(PlaylistNode* newNode)
{
    nextNodePtr = newNode;
}

// Constructor for Playlist.
Playlist::Playlist(string newTitle)
{
    title = newTitle;
    head = nullptr;
    tail = head;
}

// Destructor for Playlist that deletes all nodes in the linked list
Playlist::~Playlist()
{
    PlaylistNode* currentNode = head;
    while (currentNode != nullptr)
    {
        PlaylistNode* temp = currentNode;
        currentNode = currentNode->GetNext();
        delete temp;
    }
}

// Copy assignment operator for Playlist
Playlist& Playlist::operator=(const Playlist& other)
{
    // Check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // Delete the current linked list
    PlaylistNode* currentNode = head;
    while (currentNode != nullptr)
    {
        PlaylistNode* temp = currentNode;
        currentNode = currentNode->GetNext();
        delete temp;
    }

    // Copy the new linked list
    title = other.title;
    head = nullptr;
    tail = head;

    PlaylistNode* otherNode = other.head;
    while (otherNode != nullptr)
    {
        PlaylistNode* newNode = new PlaylistNode(otherNode->GetID(), otherNode->GetSongName(), otherNode->GetArtistName(), otherNode->GetSongLength());
        if (head == nullptr) //checking if the linked list is empty
        {
            tail = newNode;
            head = tail;
        }
        else
        {
            tail->InsertAfter(newNode);
            tail = newNode;
        }
        otherNode = otherNode->GetNext();
    }

    return *this;
}


// This function outputs the full playlist.
void Playlist::OutputFullPlaylist()
{
    int count = 1;
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
    if(head != nullptr)
    {

        for (PlaylistNode* i = head; i != nullptr; i = i->GetNext()) //This is used in order to go through the entire linked list
        {
            cout << count << "." << endl;
            i->PrintPlaylistNode(); //Outputs the variables
            if (i != tail) // If we reach the end of the program we dont want to print an extra space hence we use this testcase
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

// This function adds a new song to the playlist.
void Playlist::AddSong()
{
    //Initalizing variables that we want to take input from user.
    string newUniqueID;
    string newSongName;
    string newArtistName;
    int newSongLength = 0;

    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> newUniqueID;
    cin.ignore();   //We add this ignore function in order to ignore the endline or else the getline will read the endline thus skipping the text
    cout << "Enter song's name:" << endl;
    getline(cin,newSongName);
    cout << "Enter artist's name:" << endl;
    getline(cin,newArtistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> newSongLength;

    //We create a new node where we pass all the variables in order to add it into the linked list
    PlaylistNode* newNode = new PlaylistNode(newUniqueID,newSongName,newArtistName,newSongLength);
    if (head == nullptr) //Checking if the list is empty
    {
        tail = newNode;
        head = tail;
    }
    else
    {
        tail->InsertAfter(newNode); //We call Insert the node at the end and set our new Node as our tail and the new Node points to Null
        tail = newNode;
    }

}

// This function removes a song from the playlist.
void Playlist::RemoveSong()
{
    string userUniqueID;    

    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> userUniqueID;

    // Keeping track of the previous node so we dont lose track of our linked list
    PlaylistNode* previousNode = head;

    //This is used in order to go through the entire linked list 
    for (PlaylistNode* currentNode = head->GetNext(); currentNode != nullptr; currentNode = currentNode->GetNext())
    {
        //Checking if the current Node ID matches with our input given by the user
        if (currentNode->GetID() == userUniqueID)
        {
            cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
            PlaylistNode* temp = currentNode; //Setting a temporary Node with the currentNode so we can delete it
            previousNode->SetNext(currentNode->GetNext()); //Updating the previousNode value so we can skip the node that we deleted
            delete temp; //Deleting the node
            currentNode = previousNode->GetNext(); //Updating the currentNode so we dont have a memory leak
        }
    }
}

//This function outputs the total time of all the songs in the playlist
void Playlist::OutputTotalTime()
{
    int total = 0;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

    //This is used in order to go through the entire linked list 
    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
    {
        total += i->GetSongLength();    //Adding the song length into the total so we dont lose track of the sum
    }
    cout << "Total time: " << total << " seconds" << endl;
}

// This function outputs the specific artistname songs information from the entire playlist.
void Playlist::OutputSongsSpecificArtist() 
{
    string userArtistName;
    int count = 1;

    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    cin.ignore();
    getline(cin,userArtistName);
    cout << endl;

    if (head != nullptr)    //Checking if our list is empty or not
    {
        //This is used in order to go through the entire linked list 
        for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
        {
            if (i->GetArtistName() == userArtistName)   //Checking if the node that we have matches with the user artistname if so we print it
            {
                cout << count << "." << endl;
                i->PrintPlaylistNode(); //Printing the node value by calling the function
                cout << endl;
            }
            count++;    //Incrementing the count here as we want the proper position and not in the if function
        }   
    }
}

// This method allows the user to change the position of a song in the playlist.
void Playlist::ChangePosition() 
{
    int oldPos;
    int newPos;
    int length = 0;

    // Prompt the user for input.
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> oldPos;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;

    // If the playlist is empty, there's nothing to do.
    if (head == nullptr)
    {
        return;
    }

    // Count the number of nodes in the playlist.
    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext())
    {
        length++;
    }

    // Make sure that the user's input is valid.
    if (oldPos < 1 || oldPos > length || newPos < 1 || newPos > length)
    {
        cout << "Invalid position entered." << endl;
        return;
    }

    // Find the node that the user wants to move.
    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;
    
    for (int i = 1; i < oldPos; i++)
    {
        prev = curr;
        curr = curr->GetNext();
    }

    // If the node exists, remove it from the playlist and insert it at the new position.
    if (curr != nullptr)
    {
        // Remove the node from its old position.
        if (prev == nullptr) // If we're moving the head node...
        {
            head = curr->GetNext(); // ...set the new head to be the node after the old head.
        }
        else
        {
            prev->SetNext(curr->GetNext()); // Otherwise, set the previous node's next pointer to be the node after the current node.
        }
        if (curr == tail) // If we're moving the tail node...
        {
            tail = prev; // ...set the new tail to be the previous node.
        }

        // Insert the node at its new position.
        PlaylistNode* previousNewNode = nullptr;
        PlaylistNode* currNode = head;

        for (int i = 1; i < newPos; i++)
        {
            previousNewNode = currNode;
            currNode = currNode->GetNext();
        }
        if (previousNewNode == nullptr) // If we're moving the node to the head position...
        {
            curr->SetNext(head); // ...set its next pointer to be the old head.
            head = curr; // ...and set the new head to be the node we just moved.
        }
        else // Otherwise, insert the node after the previous node.
        {
            previousNewNode->InsertAfter(curr);
        }
        if (currNode == nullptr) // If we're moving the node to the tail position...
        {
            tail = curr; // ...set the new tail to be the node we just moved.
        }
        cout << "\"" << curr->GetSongName() << "\" moved to position " << newPos << endl;
    }
    else // If the node doesn't exist, the user's input was invalid.
    {
        cout << "Invalid" << endl;
        return;
    }
}

