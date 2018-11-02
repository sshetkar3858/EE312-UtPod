/*
Name: Siddhartha Shetkar
Date: 10/30/18
Includes the functions for the song class but without implementation
*/

#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
  private:
    string title;
    string artist;
    int size;

  public:
    // constructors
    Song();
    Song(string title, string artist, int size);

    // setter and getter methods
    string getTitle() const;
    void setTitle(string title);
    string getArtist() const;
    void setArtist(string artist);
    int getSize() const;
    void setSize(int size);

    // relational operators
    bool operator ==(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator >(Song const &rhs);
};

#endif
