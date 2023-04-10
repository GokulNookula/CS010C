#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void PrintMenu(Playlist& ,string );

int main() {
  // Create a new playlist
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    Playlist myplaylist = Playlist(title);
    cout << endl;
    PrintMenu(myplaylist, title);

  return 0;
}

void PrintMenu(Playlist& userPlaylist,string userTitle)
{
    char userOption;

    cout << userTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> userOption;

    while (userOption == 'a' || userOption == 'd' || userOption == 'c' || userOption == 's' || userOption == 't' || userOption == 'o' || userOption == 'q')
    {

        if (userOption == 'a')
        {
            userPlaylist.AddSong();
            cout << endl;
        }
        else if (userOption == 'd')
        {
            userPlaylist.RemoveSong();
            cout << endl;
        }
        else if (userOption == 'c')
        {
            userPlaylist.ChangePosition();
            cout << endl;
        }
        else if (userOption == 's')
        {
            userPlaylist.OutputSongsSpecificArtist();
            cout << endl;
        }
        else if (userOption == 't')
        {
            userPlaylist.OutputTotalTime();
            cout << endl;
        }
        else if (userOption == 'o')
        {
            userPlaylist.OutputFullPlaylist();
            cout << endl;
        }
        else if (userOption == 'q')
        {
            return;
        }

        cout << userTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> userOption;
    }
        
}
