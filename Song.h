#ifndef SONG_H
#define SONG_H

#include "MyUtil.h"

/**
 * This class represents a song object.
 */
class Song {
  private:
    char* artistName = nullptr;
    char* title = nullptr;
    double length = 0.0;
    int numberOfLikes = 0;

  public:
    // Default constructor
    Song();

    // Constructor with arguments
    Song(const char artistName[], const char title[], double length,
         int numberOfLikes);

    // Copy constructor
    Song(const Song&);

    // Copy assignment operator
    Song& operator=(const Song& otherSong);

    // Destructor
    ~Song();

    // This function returns the artistName.
    const char* getArtistName() const;

    // This function sets the artistName.
    void setArtistName(const char artistName[]);

    // This function deallocates the memory allocated for the artistName
    // pointer, if any.
    void deallocArtistName();

    // This function returns the title.
    const char* getTitle() const;

    // This function sets the title.
    void setTitle(const char title[]);

    // This function deallocates the memory allocated for the title
    // pointer, if any.
    void deallocTitle();

    // This function returns the length.
    double getLength() const;

    // This function sets the length.
    void setLength(double length);

    // This function returns the numberOfLikes.
    int getNumberOfLikes() const;

    // This function sets the numberOfLikes.
    void setNumberOfLikes(int numberOfLikes);

    // This function prints the data of the song.
    void printInformation(ostream& os);

  private:
    // This function is used to init the members of the instance.
    void init(const char artistName[] = "", const char title[] = "",
              double length = 0.0, int numberOfLikes = 0);
};

#endif
