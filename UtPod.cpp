/*
Name: Siddhartha Shetkar
Date: 10/30/18
Includes the implementation of the UtPod class
*/

#include "UtPod.h"



using namespace std;

// constructors and destructor
UtPod::UtPod() {
  memSize = MAX_MEMORY; // is this what you should do by default?
  songs = NULL;
  unsigned int currentTime = (unsigned) time(0);
  srand(currentTime);
}
UtPod::UtPod(int size) {
  if(size > MAX_MEMORY || size <= 0)
    size = MAX_MEMORY;
  memSize = size;

  // initialize songs
  songs = NULL;

  unsigned int currentTime = (unsigned) time(0);
  srand(currentTime);
}
UtPod::~UtPod() {
  clearMemory();
}

// functionality
int UtPod::getSizeOfSongs() {
  SongNode* current = songs;
  int count = 0;
  while(current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void UtPod::switchSongs(int first, int second) {
  int min;
  int max;
  if(first < second) {
    min = first;
    max = second;
  }
  else {
    min = second;
    max = first;
  }

  // get the two SongNodes
  SongNode* current = songs;
  SongNode* minSwitch = current; // default
  SongNode* maxSwitch = current; // default
  int count = 0;
  while(count < max) {
    if(count == min)
      minSwitch = current;
    current = current->next;
    count++;
  }
  maxSwitch = current;

  // switch the songs in the two SongNodes
  Song tempSong = minSwitch->s;
  minSwitch->s = maxSwitch->s;
  maxSwitch->s = tempSong;
}

int UtPod::addSong(Song const &s) {
  int status = NO_MEMORY;
  if(!(s.getArtist() == "" || s.getTitle() == "" || s.getSize() <= 0)) {
    if(s.getSize() <= getRemainingMemory()) {
      SongNode* newSongNode = new SongNode();
      newSongNode->s = s;
      newSongNode->next = songs;
      songs = newSongNode;

      status = SUCCESS;
    }
  }

  return status;
}

int UtPod::removeSong(Song const &s) {
  SongNode* current = songs;
  SongNode* trail = NULL;
  bool found = false;
  while(current != NULL && !found) {
    if(current->s == s) {
      SongNode* temp;
      // remove first
      if(current == songs) {
        temp = songs;
        songs = songs->next;
        delete temp;
        found = true;
      }
      // remove middle or end
      else {
        trail->next = current->next;
        delete current;
        found = true;
      }
    }
    if(!found) {
      trail = current;
      current = current->next;
    }
  }
  if(found)
    return SUCCESS;
  else
    return NOT_FOUND;
}
void UtPod::shuffle() {
  int size = getSizeOfSongs();
  for(int i = 0; i<size; i++) {
    int firstIndex = rand() % size;
    int secondIndex = rand() % size;
    if(secondIndex == firstIndex)
      secondIndex = (secondIndex+1)%size;
    switchSongs(firstIndex, secondIndex);
  }
}

void UtPod::showSongList() {
  SongNode* current = songs;
  while(current != NULL) {
    cout << "Artist: " << current->s.getArtist() << ", Title: " << current->s.getTitle() << ", Size: " << current->s.getSize() << " MB" <<endl;
    current = current->next;
  }
}

void UtPod::sortSongList(){
  for(SongNode* nodeI = songs; nodeI != NULL; nodeI = nodeI->next) {
    SongNode* min = nodeI;
    for(SongNode* nodeJ = nodeI->next; nodeJ != NULL; nodeJ = nodeJ->next) {
      if(min->s > nodeJ->s) {
        min = nodeJ;
      }
    }
    Song temp = min->s;
    min->s = nodeI->s;
    nodeI->s = temp;
  }
}
void UtPod::clearMemory() {
  SongNode* current = songs;
  songs = NULL;
  while(current != NULL) {
    SongNode* temp = current;
    current = current->next;
    delete temp;
  }
}

int UtPod::getRemainingMemory(){
  int currentUsedMem = 0;
  SongNode* current = songs;
  while(current != NULL) {
    currentUsedMem += current->s.getSize();
    current = current->next;
  }
  return (memSize - currentUsedMem);
}
