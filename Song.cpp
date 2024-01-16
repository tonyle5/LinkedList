/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This is the implementation file for a Song ADT.
 */

#include "Song.h"

// Name:   Song::Song()
// Desc:   Default constructor
// Input:  None
// Output: None
// Return: None
Song::Song() {
  this->init("", "", 0.0, 0);
}

// Name:   Song::Song()
// Desc:   Constructor with arguments
// Input:  const char artistName[], const char title[], double length,
//         int numberOfLikes
// Output: None
// Return: None
Song::Song(const char artistName[], const char title[], double length,
           int numberOfLikes) {
  this->init(artistName, title, length, numberOfLikes);
};

// Name:   Song::Song()
// Desc:   Copy constructor
// Input:  const Song&
// Output: None
// Return: None
Song::Song(const Song& songToCopy) {
  *this = songToCopy;
}

// Name:   Song::operator=()
// Desc:   Copy assignment operator
// Input:  const Song& otherSong
// Output: None
// Return: None
Song& Song::operator=(const Song& otherSong) {
  if (this != &otherSong) {
    this->setArtistName(otherSong.getArtistName());
    this->setTitle(otherSong.getTitle());
    this->setLength(otherSong.getLength());
    this->setNumberOfLikes(otherSong.getNumberOfLikes());
  }

  return *this;
}

// Name:   Song::~Song()
// Desc:   Destructor
// Input:  None
// Output: None
// Return: None
Song::~Song() {
  this->deallocArtistName();
  this->deallocTitle();
};

// Name:   Song::getArtistName()
// Desc:   This function returns the artistName.
// Input:  None
// Output: None
// Return: artistName
const char* Song::getArtistName() const {
  return this->artistName;
};

// Name:   Song::setArtistName()
// Desc:   This function sets the artistName.
// Input:  const char artistName[]
// Output: None
// Return: None
void Song::setArtistName(const char artistName[]) {
  this->deallocArtistName();
  int size = strlen(artistName);
  this->artistName = new char[size + 1];
  strcpy(this->artistName, artistName);
};

// Name:   Song::deallocArtistName()
// Desc:   This function deallocates the memory allocated for the artistName
//         pointer, if any.
// Input:  None
// Output: None
// Return: None
void Song::deallocArtistName() {
  if (this->artistName != nullptr) {
    delete[] this->artistName;
    this->artistName = nullptr;
  }
}

// Name:   Song::getTitle()
// Desc:   This function returns the title.
// Input:  None
// Output: None
// Return: title
const char* Song::getTitle() const {
  return this->title;
};

// Name:   Song::setTitle()
// Desc:   This function sets the title.
// Input:  const char title[]
// Output: None
// Return: None
void Song::setTitle(const char title[]) {
  this->deallocTitle();
  int size = strlen(title);
  this->title = new char[size + 1];
  strcpy(this->title, title);
};

// Name:   Song::deallocTitle()
// Desc:   This function deallocates the memory allocated for the title
//         pointer, if any.
// Input:  None
// Output: None
// Return: None
void Song::deallocTitle() {
  if (this->title != nullptr) {
    delete[] this->title;
    this->title = nullptr;
  }
}

// Name:   Song::getLength()
// Desc:   This function returns the length.
// Input:  None
// Output: None
// Return: length
double Song::getLength() const {
  return this->length;
}

// Name:   Song::setLength()
// Desc:   This function sets the length.
// Input:  double length
// Output: None
// Return: None
void Song::setLength(double length) {
  this->length = length;
}

// Name:   Song::getNumberOfLikes()
// Desc:   This function returns the numberOfLikes.
// Input:  None
// Output: None
// Return: numberOfLikes
int Song::getNumberOfLikes() const {
  return this->numberOfLikes;
}

// Name:   Song::setNumberOfLikes()
// Desc:   This function sets the numberOfLikes.
// Input:  int numberOfLikes
// Output: None
// Return: None
void Song::setNumberOfLikes(int numberOfLikes) {
  this->numberOfLikes = numberOfLikes;
}

// Name:   Song::printInformation()
// Desc:   This function prints the data of the song.
// Input:  None
// Output: The song information
// Return: None
void Song::printInformation(ostream& os) {
  os << this->getArtistName() << ";";
  os << this->getTitle() << ";";
  os << this->getLength() << ";";
  os << this->getNumberOfLikes();
}

// Name:   Song::init()
// Desc:   This function is used to init the members of the instance.
// Input:  const char artistName[], const char title[],
//         double length, int numberOfLikes
// Output: None
// Return: None
void Song::init(const char artistName[], const char title[], double length,
                int numberOfLikes) {
  this->setArtistName(artistName);
  this->setTitle(title);
  this->setLength(length);
  this->setNumberOfLikes(numberOfLikes);
};
