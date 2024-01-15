#include "SongList.h"

// Name:   SongList::SongList()
// Desc:   Default constructor
// Input:  None
// Output: None
// Return: None
SongList::SongList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->songCount = 0;
}

// Name:   SongList::~SongList()
// Desc:   Destructor
// Input:  None
// Output: None
// Return: None
SongList::~SongList() {
  Node* curr = this->head;

  while (curr) {
    this->head = curr->next;
    delete curr;
    curr = this->head;
  }
  this->tail = nullptr;
}

// Name:   Song::getSongCount()
// Desc:   This function returns the songCount.
// Input:  None
// Output: None
// Return: title
int SongList::getSongCount() const {
  return this->songCount;
};

// Name:   SongList::addSong()
// Desc:   This function adds a new song to the songList. The songs are
//         organized by popularities with the most popular song as the first
//         node in the list
// Input:  None
// Output: None
// Return: None
void SongList::addSong(Song& song) {
  Node* newNode = new Node;
  newNode->data = song;
  newNode->next = nullptr;

  if (!this->head) {  // If the list is empty
    this->head = newNode;
    this->tail = newNode;
  } else {
    Node* cur = this->head;
    Node* prev = nullptr;
    int newSongLikes = song.getNumberOfLikes();

    while (cur && cur->data.getNumberOfLikes() > newSongLikes) {
      prev = cur;
      cur = cur->next;
    }

    if (!prev) {  // Insert at the beginning
      newNode->next = cur;
      this->head = newNode;
    } else if (!cur) {  // Insert at the end
      this->tail->next = newNode;
      this->tail = newNode;
    } else {  // Insert in the middle
      newNode->next = cur;
      prev->next = newNode;
    }
  }

  this->songCount++;
}

// Name:   SongList::editLikes()
// Desc:   This function edits the number of likes for a songs.
// Input:  int songPosition, int newNumberOfLikes
// Output: None
// Return: bool
bool SongList::editLikes(int songPosition, int newNumberOfLikes) {
  if (songPosition < 1 || songPosition > this->songCount) {
    return false;
  }

  int positionCount = 1;
  Node* cur = this->head;
  while (cur && positionCount < songPosition) {
    cur = cur->next;
    positionCount++;
  }

  cur->data.setNumberOfLikes(newNumberOfLikes);

  return true;
}

// Name:   SongList::displaySongs()
// Desc:   This function displays all songs in the list.
// Input:  None
// Output: The songs in the list
// Return: None
void SongList::displaySongs() {
  int positionCount = 1;
  Node* cur = this->head;

  cout << "Displaying " << this->songCount << " song(s): " << endl;

  while (cur) {
    cout << positionCount << ". ";
    cur->data.printInformation(cout);
    cout << endl;

    cur = cur->next;
    positionCount++;
  }

  cout << endl;
}

// Name:   SongList::displaySongsByArtist()
// Desc:   This function displays all songs of an artist.
// Input:  const char artistName[]
// Output: The songs of an artist
// Return: None
void SongList::displaySongsByArtist(const char artistName[]) {
  int positionCount = 1;
  Node* cur = this->head;

  while (cur) {
    if (strstr(cur->data.getArtistName(), artistName) != nullptr) {
      cout << positionCount << ". ";
      cur->data.printInformation(cout);
      cout << endl;

      positionCount++;
    }

    cur = cur->next;
  }

  cout << endl;
}

// Name:   SongList::removeSongsWithFewerLikes()
// Desc:   This function removes all songs with fewer than a number of likes.
// Input:  int likes
// Output: None
// Return: None
void SongList::removeSongsWithFewerLikes(int likes) {
  Node* cur = this->head;
  Node* prev = nullptr;

  while (cur && cur->data.getNumberOfLikes() >= likes) {
    // Since the songs are sorted by popularity, we can stop when we find a
    // first song with fewer likes. At that point, we can remove that song and
    // any subsequent songs that follow it.
    prev = cur;
    cur = cur->next;
  }

  if (cur) {
    // Update the head and tail pointers.If 'cur' is equal to the head, then
    // we will remove all songs from the list. Otherwise, update the next
    // pointer of the previous song to nullptr.
    if (cur == this->head) {
      this->head = nullptr;
      this->tail = nullptr;
    } else {
      prev->next = nullptr;
      this->tail = prev;
    }

    this->removeSongsFromANode(cur);
  }
}

// Name:   SongList::removeSongsFromANode()
// Desc:   This function removes all songs starting from a specified node.
// Input:  Node* cur
// Output: None
// Return: None
void SongList::removeSongsFromANode(Node* cur) {
  if (!cur) {
    return;
  }

  if (cur->next) {
    this->removeSongsFromANode(cur->next);
  }

  delete cur;
  this->songCount--;
}

// Name:   SongList::loadData()
// Desc:   This function loads data from a text file.
// Input:  const char fileName[]
// Output: None
// Return: None
int SongList::loadData(const char fileName[]) {
  ifstream inFile;
  inFile.open(fileName);

  if (!inFile) {
    return ERROR;
  }

  char artistName[STR_SIZE];
  char title[STR_SIZE];
  double length = 0.0;
  int numberOfLikes = 0;

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');

  inFile.get(artistName, STR_SIZE, ';');

  while (!inFile.eof()) {
    inFile.ignore();

    inFile.get(title, STR_SIZE, ';');
    inFile.ignore();

    inFile >> length;
    inFile.ignore();

    inFile >> numberOfLikes;
    inFile.ignore(STR_SIZE, '\n');

    Song song(artistName, title, length, numberOfLikes);
    this->addSong(song);

    inFile.get(artistName, STR_SIZE, ';');
  }

  inFile.close();

  return this->songCount;
}

// Name:   SongList::writeData()
// Desc:   This function writes data to a text file.
// Input:  const char fileName[]
// Output: None
// Return: None
bool SongList::writeData(const char fileName[]) {
  ofstream outFile;
  outFile.open(fileName);

  if (!outFile) {
    return false;
  }

  Node* cur = this->head;

  outFile << "Artist name; Title; Length; Number of likes" << endl;

  while (cur) {
    cur->data.printInformation(outFile);
    outFile << endl;

    cur = cur->next;
  }

  outFile.close();

  return true;
}
