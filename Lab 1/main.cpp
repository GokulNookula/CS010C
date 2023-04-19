#include <iostream>
#include <string>
#include "Playlist.cpp" // include the header file that defines the Playlist class

using namespace std;

//Defining our PrintMenu on top so we can write the code in the bottom later to make our main look better
void PrintMenu(Playlist& ,string );

int main() {
  // Create a new playlist
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title); // Get the playlist title from the user
    Playlist myplaylist = Playlist(title);
    cout << endl;
    PrintMenu(myplaylist, title); // Call the PrintMenu function to display the menu options and handle user input

  return 0;
}

// Function to print the menu options and handle user input
void PrintMenu(Playlist& userPlaylist,string userTitle)
{
    char userOption;

    // Display the menu options
    cout << userTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;

    // Get the user's menu choice
    cout << "Choose an option:" << endl;
    cin >> userOption;

    // Loop through the menu options until the user chooses to quit
    while (userOption == 'a' || userOption == 'd' || userOption == 'c' || userOption == 's' || userOption == 't' || userOption == 'o' || userOption == 'q')
    {
        // Call the appropriate function based on the user's choice
        if (userOption == 'a')
        {
            userPlaylist.AddSong(); // Call the AddSong method of the Playlist object
            cout << endl;
        }
        else if (userOption == 'd')
        {
            userPlaylist.RemoveSong(); // Call the RemoveSong method of the Playlist object
            cout << endl;
        }
        else if (userOption == 'c')
        {
            userPlaylist.ChangePosition(); // Call the ChangePosition method of the Playlist object
            cout << endl;
        }
        else if (userOption == 's')
        {
            userPlaylist.OutputSongsSpecificArtist(); // Call the OutputSongsSpecificArtist method of the Playlist object
        }
        else if (userOption == 't')
        {
            userPlaylist.OutputTotalTime(); // Call the OutputTotalTime method of the Playlist object
            cout << endl;
        }
        else if (userOption == 'o')
        {
            userPlaylist.OutputFullPlaylist(); // Call the OutputFullPlaylist method of the Playlist object
            cout << endl;
        }
        else if (userOption == 'q') // Exit the loop and the function
        {
            return;
        }

         // Display the menu options again
        cout << userTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        
        // Get the user's menu choice
        cout << "Choose an option:" << endl;
        cin >> userOption;
    }
        
}
