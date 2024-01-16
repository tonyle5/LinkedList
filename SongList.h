#ifndef _SONGLIST_
#define _SONGLIST_

#include "myUtil.h"
#include "Song.h"

/**
 * Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This class represents a song list ADT. It uses a linked list
 *              to store the songs.
 */
class SongList {
  private:
    struct Node {
        Song data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int songCount;

  public:
    // Default constructor.
    SongList();

    // Destructor
    ~SongList();

    // This function returns the songCount.
    int getSongCount() const;

    // This function adds a new song to the songList. The songs are organized
    // by popularities with the most popular song as the first node in the
    // list.
    void addSong(Song& song);

    // This function edits the number of likes for a songs.
    bool editLikes(int songPosition, int newNumberOfLikes);

    // This function displays all songs in the list.
    void displaySongs();

    // This function displays all songs for an artist (in order of
    // popularity).
    void displaySongsByArtist(const char artistName[]);

    // This function removes all songs with fewer than a number of likes.
    void removeSongsWithFewerLikes(int likes);

    // This function removes all songs starting from a specified node.
    void removeSongsFromANode(Node* cur);

    // This function loads data from a text file.
    int loadData(const char fileName[]);

    // This function writes data to a text file.
    bool writeData(const char fileName[]);
};

#endif
