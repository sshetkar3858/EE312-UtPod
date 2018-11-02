/*
Name: Siddhartha Shetkar
Date: 10/30/18
Includes the implementation of the Song class
*/

#include "Song.h"

using namespace std;

// constructors
Song::Song() {
  // DEFAULT
  title = "";
  artist = "";
  size = 0;
}
Song::Song(string artist, string title, int size) {
  this->title = title;
  this->artist = artist;
  this->size = size;
}

// setters and getters
string Song::getTitle() const {
  return title;
}
void Song::setTitle(string title) {
  this->title = title;
}
string Song::getArtist() const {
  return artist;
}
void Song::setArtist(string artist) {
  this->artist = artist;
}
int Song::getSize() const {
  return size;
}
void Song::setSize(int size) {
  this->size = size;
}

// relational operators
bool Song::operator ==(Song const &rhs) {
  return ((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}
bool Song::operator <(Song const &rhs) {
  bool lessThan = false;
  if(artist < rhs.artist)
    lessThan = true;
  if((artist == rhs.artist) && (title < rhs.title))
    lessThan = true;
  if((artist == rhs.artist) && (title == rhs.title) && (size < rhs.size))
    lessThan = true;
  return lessThan;
}
bool Song::operator >(Song const &rhs) {
  bool greaterThan = false;
  if(artist > rhs.artist)
    greaterThan = true;
  if((artist == rhs.artist) && (title > rhs.title))
    greaterThan = true;
  if((artist == rhs.artist) && (title == rhs.title) && (size > rhs.size))
    greaterThan = true;
  return greaterThan;
}
