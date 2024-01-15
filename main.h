#ifndef MAIN_H
#define MAIN_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>

#include "MyUtil.h"
#include "SongList.h"

// Function prototypes

// This function prints a welcome message.
void welcome();

// This function prints a goodbye message.
void goodbye();

// This function displays the menu to the user.
void displayMenu();

// This function reads the option.
char readOption();

// This function prompts the user to enter the song information and adds it to
// the song list.
void addSong(SongList& songList);

// This function prompts the user to enter the number of likes and the position
// of the song and then make the modification.
void editLikes(SongList& songList);

void displaySongsByArtist(SongList& songList);

// This function prompts the user to enter the number of likes and removes
// all all songs with fewer than a number of likes.
void removeSongsWithFewerLikes(SongList& songList);

// This function calls the different functions such as view, add, remove, and
// search for doughnuts.
void exeOption(char option, SongList& songList);

#endif
