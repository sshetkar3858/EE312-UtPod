/* utPod_driver.cpp
Demo Driver for the UtPod.

Siddhartha Shetkar
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

void testConstructor() {
  cout << "############# TESTING CONSTRUCTORS AND getTotalMemory ######" << endl;
  UtPod t1;
  cout << "Default constructor has: " << t1.getTotalMemory() << " memory" << endl;
  UtPod t2(0);
  cout << "When lower than or equal to 0 it has: " << t2.getTotalMemory() << " memory" << endl;
  UtPod t3(-5);
  cout << "When lower than 0 it has: " << t3.getTotalMemory() << " memory" << endl;
  UtPod t4(512);
  cout << "When at max it has: " << t4.getTotalMemory() << " memory" << endl;
  UtPod t5(657);
  cout << "When higher than max it has: " << t5.getTotalMemory() << " memory" << endl;
  UtPod t6(134);
  cout << "When it has a value in between it is set: " << t6.getTotalMemory() << " memory" << endl;
  cout << "#########################################################" << endl;
}

void testAddingRemovingShowingMemory() {
  UtPod t;

  // tests adding, removing, showing songs
  cout << "############# TESTING ADD, REMOVE, SHOWING #################" << endl;

  Song s0; // test that adding a song with blank attributes does not work
  int result = t.addSong(s0);
  cout << "result = " << result << endl;

  s0 = Song("", "HeyJude1", 2);
  result = t.addSong(s0);
  cout << "result = " << result << endl;

  s0 = Song("Beatles", "", 2);
  result = t.addSong(s0);
  cout << "result = " << result << endl;

  s0 = Song("Beatles", "HeyJude1", -3);
  result = t.addSong(s0);
  cout << "result = " << result << endl;

  Song s1("Beatles", "Hey Jude1", 4);
  result = t.addSong(s1);
  cout << "result = " << result << endl;

  t.showSongList();

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s2("Beatles", "Hey Jude2", 5);
  result = t.addSong(s2);
  cout << "result = " << result << endl;

  t.showSongList();

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s3("Beatles", "Hey Jude3", 6);
  result = t.addSong(s3);
  cout << "result = " << result << endl;

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s4("Beatles", "Hey Jude4", 7);
  result = t.addSong(s4);
  cout << "result = " << result << endl;

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s5("Beatles", "Hey Jude5", 241);
  result = t.addSong(s5);
  cout << "add result = " << result << endl;


  t.showSongList();

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s6("Beatles", "Hey Jude6", 300);
  result = t.addSong(s6);
  cout << "result = " << result << endl;

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s7("Beatles", "Hey Jude7", 250);
  result = t.addSong(s7);
  cout << "result = " << result << endl;

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song s8("Beatles", "Hey Jude8", 249);
  result = t.addSong(s8);
  cout << "result = " << result << endl;
  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;


  result = t.removeSong(s8);
  cout << "delete result = " << result << endl;

  result = t.removeSong(s3);
  cout << "delete result = " << result << endl;

  t.showSongList();

  result = t.removeSong(s1);
  cout << "delete result = " << result << endl;

  result = t.removeSong(s5);
  cout << "delete result = " << result << endl;

  result = t.removeSong(s4);
  cout << "delete result = " << result << endl;

  Song s9("Beatles", "HeyJude9", 23);
  result = t.removeSong(s9);
  cout << "delete result = " << result << endl;

  result = t.removeSong(s1);
  cout << "delete result = " << result << endl;



  t.showSongList();

  result = t.addSong(s5);
  cout << "add result = " << result << endl;

  cout << "getRemainingMemory = " << t.getRemainingMemory() << endl;
  Song sameS5("Beatles", "Hey Jude5", 241);
  result = t.addSong(sameS5);
  cout << "add result = " << result << endl;

  t.showSongList();
  cout << "memory = " << t.getRemainingMemory() << endl;
  cout << "#########################################################" << endl;
}

void testShuffle() {
  cout << "################# TESTING SHUFFLING #####################" << endl;
  UtPod test;
  Song s1("Yeh", "Hey", 4);
  Song s2("Oy", "Yo", 3);
  Song s3("Olleh", "Hello", 7);
  Song s4("Ih", "Hi", 3);
  Song s5("Eyb", "Bye", 6);
  test.addSong(s1);
  test.addSong(s2);
  test.addSong(s3);
  test.addSong(s4);
  test.addSong(s5);
  for(int i = 0; i<10; i++) {
    test.showSongList();
    test.shuffle();
    cout << endl;
  }
  cout << "#########################################################" << endl;
}

void testSort() {
  cout << "################# TESTING SORTING #######################" << endl;
  UtPod test;
  // sort no songs
  test.sortSongList();
  cout << "just tested case where there are no songs" << endl;

  // sort 1 song
  cout << endl;
  Song s1("qwer", "tyui", 7);
  test.addSong(s1);
  cout << "before" << endl;
  test.showSongList();
  test.sortSongList();
  cout << "afer" << endl;
  test.showSongList();
  cout << "just tested case where there is one song" << endl << endl;

  // sort many songs - based on Artist and not title and songs
  Song s2("asdf", "tyui", 7);
  Song s3("uty", "tyui", 7);
  Song s4("bvcx", "tyui", 7);
  test.addSong(s2);
  test.addSong(s3);
  test.addSong(s4);
  cout << "before" << endl;
  test.showSongList();
  test.sortSongList();
  cout << "after" << endl;
  test.showSongList();
  cout << endl;

  // sort many songs based on titles and shows that artist has higher priority than title
  Song s5("asdf", "zxvv", 7);
  Song s6("asdf", "jko", 7);
  Song s7("bvcx", "jkjdsf", 7);
  test.addSong(s5);
  test.addSong(s6);
  test.addSong(s7);
  cout << "before" << endl;
  test.showSongList();
  test.sortSongList();
  cout << "after" << endl;
  test.showSongList();
  cout << endl;

  // sort many songs based size and shows that size has least priority
  Song s8("asdf", "zxvv", 9);
  Song s9("asdf", "jko", 6);
  Song s10("bvcx", "jkjdsf", 15);
  test.addSong(s8);
  test.addSong(s9);
  test.addSong(s10);
  cout << "before" << endl;
  test.showSongList();
  test.sortSongList();
  cout << "after" << endl;
  test.showSongList();
  cout << endl;

  // sort with multiple songs that are the same
  Song s11("bvcx", "jkjdsf", 15);
  test.addSong(s11);
  cout << "before" << endl;
  test.showSongList();
  test.sortSongList();
  cout << "after" << endl;
  test.showSongList();
  cout << endl;

  cout << "#########################################################" << endl;
}

void testClearMemory() {
  UtPod test;

  cout << "################# TESTING CLEAR MEMORY ##################" << endl;
  // clear no songs
  test.clearMemory();
  cout << "just tested case where there are no songs" << endl;

  // clear 1 song
  cout << endl;
  Song s1("qwer", "tyui", 7);
  test.addSong(s1);
  cout << "before" << endl;
  test.showSongList();
  test.clearMemory();
  cout << "afer" << endl;
  test.showSongList();
  cout << "just tested case where there is one song" << endl << endl;

  // clear many songs
  Song s2("asdf", "tyui", 7);
  Song s3("uty", "tyui", 7);
  Song s4("bvcx", "tyui", 7);
  test.addSong(s2);
  test.addSong(s3);
  test.addSong(s4);
  cout << "before" << endl;
  test.showSongList();
  test.clearMemory();
  cout << "after" << endl;
  test.showSongList();
  cout << endl;
  cout << "#########################################################" << endl;

}

int main(int argc, char *argv[])
{
    // test constructors and getTotalMemory
    testConstructor();

    // test adding, removing, showing songs, getRemainingMemory
    testAddingRemovingShowingMemory();

    // tests shuffling
    testShuffle();

    // test sorting
    testSort();

    // test clear memory
    testClearMemory();




}
