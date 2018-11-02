/*
Name: Siddhartha Shetkar
Date: 10/30/18
Includes the functions of the UtPod class but without implementation
*/

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;

      struct SongNode
      {
         Song s;
         SongNode *next;
      };

      SongNode *songs;  //the head pointer

      int memSize;

      // private functions used by some of the public functions
      int getSizeOfSongs(); // used by shuffle
      void switchSongs(int first, int second); // used by shuffle

   public:
     //Default constructor
     //set the memory size to MAX_MEMORY
      UtPod();
      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod(int size);

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - a valid song

       output parms - whether the song was succesfully added or not
      */
      int addSong(Song const &s);
      /* FUNCTION - int removeSong
      * attempts to remove a song from the UtPod
      * removes the first instance of a song that is in the the UtPod multiple times
      o returns 0 if successful
      o returns -2 if nothing is removed


      input parms - a song that that might or might not be in the songs list

      output parms - whether song was succesfully removed
      */
      int removeSong(Song const &s);
      /* FUNCTION - void shuffle
      *  shuffles the songs into random order
      o will do nothing if there are less than two songs in the current list

      input parms - none

      output parms - none
      */
      void shuffle();
      /* FUNCTION - void showSongList
      * prints the current list of songs in order from first to last to standard output
      * format - Title, Artist, size in MB (one song per line)

      input parms - none

      output parms - none
      */
      void showSongList();
      /* FUNCTION - void sortSongList
      *  sorts the songs in ascending order
      o will do nothing if there are less than two songs in the current list

      input parms - none

      output parms - none
      */
      void sortSongList();
      /* FUNCTION - void clearMemory
       * clears all the songs from memory

      input parms - none

      output parms - none
      */
      void clearMemory();
      /* FUNCTION - int getTotalMemory
      *  returns the total amount of memory in the UtPod
      
      input parms - none

      output parms - returns the memory size of the UtPod
      */
      int getTotalMemory() {
         return memSize;
      }
      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

      input parms - none

      output parms - returns the amount of memory left to store new songs
      */
      int getRemainingMemory();

      ~UtPod();

};

#endif
