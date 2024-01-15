/******************************************************************************
# Author:           Tony Le
# Project:          Project 1
# Date:             Jan 13, 2024
# Description:      This program reads and tracks a list of songs from a
#                   data file. The program will allow the user to add, edit
#                   the number of likes for a song, display all songs in the
#                   list, display all songs for an artist (in order of
#                   popularity), and remove all songs with fewer than M likes.
# Sources:          Project 1 specifications
#*****************************************************************************/

#include "main.h"

int main() {
  SongList songList;
  char option = ' ';
  int songLoadResult = songList.loadData("songs.txt");

  welcome();

  if (songLoadResult != ERROR) {
    cout << songLoadResult << " song(s) added from the data file." << endl
         << endl;

    do {
      displayMenu();
      option = readOption();
      exeOption(option, songList);
    } while (option != 'Q');

    goodbye();
  }
}

// Name:   welcome()
// Desc:   This function prints a welcome message.
// Input:  None
// Output: Welcome message
// Return: None
void welcome() {
  cout << "Welcome to Song List program!" << endl;
  cout << "This program will help you keeping track of song lists.";
  cout << endl << endl;
}

// Name:   goodbye()
// Desc:   This function prints a goodbye message.
// Input:  None
// Output: Goodbye message
// Return: None
void goodbye() {
  cout << endl;
  cout << "Thank you for using the program!!";
}

// Name:   displayMenu()
// Desc:   This function displays the menu to the user.
// Input:  None
// Output: The menu.
// Return: None
void displayMenu() {
  cout << "Pick an option from below: " << endl << endl;
  cout << "(A)Add a new song" << endl;
  cout << "(E)Edit the number of likes for a song" << endl;
  cout << "(D)Display all songs in the list" << endl;
  cout << "(S)Display all songs for an artist (in order of popularity)"
       << endl;
  cout << "(R)Remove all songs with fewer than a number of likes" << endl;
  cout << "(Q)Quit" << endl;
  cout << endl;
}

// Name:   readOption()
// Desc:   This function reads the option.
// Input:  None
// Output: The option
// Return: char option
char readOption() {
  char option;
  cin >> option;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return toupper(option);
}

// Name:   addSong()
// Desc:   This function prompts the user to enter the song information and
//         adds it to the song list.
// Input:  None
// Output: Prompts the user to enter the song information
// Return: None
void addSong(SongList& songList) {
  char artistName[STR_SIZE];
  char title[STR_SIZE];
  double length;
  int numberOfLikes;

  cout << "Enter the artist name: ";
  cin.getline(artistName, STR_SIZE);

  cout << "Enter the song title: ";
  cin.getline(title, STR_SIZE);

  getNumber("Enter the length of the song: ", "Please enter a valid number!",
            length);

  getNumber("Enter the number of likes: ", "Please enter a valid number!",
            numberOfLikes);

  cout << endl;

  Song song(title, artistName, length, numberOfLikes);
  songList.addSong(song);
}

// Name:   editLikes()
// Desc:   This function prompts the user to enter the number of likes and the
//         position of the song and then make the modification.
// Input:  SongList& songList
// Output: Prompts the user to enter the information
// Return: None
void editLikes(SongList& songList) {
  int songPosition;
  int numberOfLikes;
  int songCount = songList.getSongCount();

  do {
    getNumber("Enter the number of likes: ", "Please enter a valid number!",
              numberOfLikes);

    if (numberOfLikes < 0)
      cout << "Invalid number of likes!! Please try again!!!" << endl << endl;
  } while (numberOfLikes < 0);

  do {
    getNumber("Enter the song position: ", "Please enter a valid number!",
              songPosition);

    if (songPosition < 0 || songPosition > songCount) {
      cout << "Invalid song position!! Please try again!!!" << endl << endl;
    }
  } while (songPosition < 0 || songPosition > songCount);

  songList.editLikes(songPosition, numberOfLikes);
}

// Name:   displaySongsByArtist()
// Desc:   This function prompts the user to enter the artist name and
//         display all song of that artist.
// Input:  SongList& songList
// Output: Prompts the user to enter the information
// Return: None
void displaySongsByArtist(SongList& songList) {
  char artistName[STR_SIZE];

  cout << "Enter the artist name: ";
  cin.getline(artistName, STR_SIZE);

  songList.displaySongsByArtist(artistName);
}

// Name:   removeSongsWithFewerLikes()
// Desc:   This function prompts the user to enter the number of likes and
//         removes all all songs with fewer than a number of likes.
// Input:  SongList& songList
// Output: Prompts the user to enter the information
// Return: None
void removeSongsWithFewerLikes(SongList& songList) {
  int numberOfLikes;

  do {
    getNumber("Please enter the number of likes: ",
              "Please enter a valid number!", numberOfLikes);

    if (numberOfLikes < 0)
      cout << "Invalid number of likes!! Please try again!!!" << endl << endl;
  } while (numberOfLikes < 0);

  songList.removeSongsWithFewerLikes(numberOfLikes);
}

// Name:   exeOption()
// Desc:   This function calls the different functions based on the input
//         option.
// Input:  char option, SongList& songList
// Output: None
// Return: None
void exeOption(char option, SongList& songList) {
  switch (option) {
    case 'A':
      addSong(songList);
      songList.displaySongs();
      break;
    case 'E':
      songList.displaySongs();
      editLikes(songList);
      break;
    case 'D':
      songList.displaySongs();
      break;
    case 'S':
      displaySongsByArtist(songList);
      break;
    case 'R':
      removeSongsWithFewerLikes(songList);
      songList.displaySongs();
      break;
    case 'Q':
      songList.writeData("songs.txt");
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}
