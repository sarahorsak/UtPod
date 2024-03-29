/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{

    //ADDSONG TEST
    UtPod t(20);

    Song s1("Beatles", "Hey Jude1", 5);
    int result = t.addSong(s1);

    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 5);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s4("Beatles", "Hey Jude4", 6);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s5("Beatles", "Hey Jude5", 5);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();



   //given

    result = t.removeSong(s2);
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


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;


    //SHUFFLE TEST

    UtPod tshuffle;
    tshuffle.showSongList();
    tshuffle.shuffle();

    Song s6("Beatles", "Hey Jude1", 4);
    result = tshuffle.addSong(s1);
    cout << "result = " << result << endl;

    //shouldn't work
    tshuffle.showSongList();
    tshuffle.shuffle();
    tshuffle.showSongList();

    Song s7("Beatles", "Hey Jude2", 5);
    result = tshuffle.addSong(s7);
    cout << "result = " << result << endl;

    Song s8("Beatles", "Hey Jude3", 6);
    result = tshuffle.addSong(s8);
    cout << "result = " << result << endl;

    Song s9("Beatles", "Hey Jude4", 7);
    result = tshuffle.addSong(s9);
    cout << "result = " << result << endl;

    //should shuffle
    tshuffle.showSongList();
    tshuffle.shuffle();
    tshuffle.showSongList();


    //SORT TEST

    UtPod tsort;
    tsort.showSongList();
    tsort.sortSongList();

    Song s10("Beatles", "Hey Jude1", 4);
    result = tsort.addSong(s10);
    cout << "result = " << result << endl;

    //shouldn't sort
    cout << "no sort " << endl;
    tsort.showSongList();
    tsort.sortSongList();
    tsort.showSongList();

    Song s11("Beatles", "Hey Jude2", 5);
    result = tsort.addSong(s11);
    cout << "result = " << result << endl;

    Song s12("Beatles", "Hey Jude3", 6);
    result = tsort.addSong(s12);
    cout << "result = " << result << endl;

    Song s13("Beatles", "Hey Jude4", 7);
    result = tsort.addSong(s13);
    cout << "result = " << result << endl;

    //should sort by title
    tsort.showSongList();
    tsort.sortSongList();
    cout << "sort by artist, then title " << endl;
    tsort.showSongList();

    //next test to sort by artist
    Song s14("ABeatles", "Hey Jude2", 5);
    result = tsort.addSong(s14);
    cout << "result = " << result << endl;

    Song s15("Beatles", "Hey Jude3", 6);
    result = tsort.addSong(s15);
    cout << "result = " << result << endl;

    Song s16("CBeatles", "Hey Jude4", 7);
    result = tsort.addSong(s16);
    cout << "result = " << result << endl;

    tsort.showSongList();
    tsort.sortSongList();
    cout << "sort by artist, then title " << endl;
    tsort.showSongList();

    //sorts by size
    Song s17("Beatles", "Hey Jude", 5);
    result = tsort.addSong(s17);
    cout << "result = " << result << endl;

    Song s18("Beatles", "Hey Jude", 6);
    result = tsort.addSong(s18);
    cout << "result = " << result << endl;

    Song s19("Beatles", "Hey Jude", 7);
    result = tsort.addSong(s19);
    cout << "result = " << result << endl;

    tsort.showSongList();
    tsort.sortSongList();
    cout << "sort by artist, then title, then size " << endl;
    tsort.showSongList();

    //REMOVE TEST

    UtPod tremove;

    result = tremove.removeSong(s19);
    cout << "result = " << result << endl;

    result = tremove.addSong(s18);
    result = tremove.addSong(s17);
    result = tremove.addSong(s18);
    result = tremove.addSong(s17);
    result = tremove.addSong(s19);

    tremove.showSongList();
    result = tremove.removeSong(s16);
    cout << "result = " << result << endl;
    tremove.showSongList();
    result = tremove.removeSong(s18);
    cout << "result = " << result << endl;
    tremove.showSongList();

    result = tremove.removeSong(s18);
    cout << "result = " << result << endl;
    tremove.showSongList();
    result = tremove.removeSong(s17);
    cout << "result = " << result << endl;
    result = tremove.removeSong(s17);
    cout << "result = " << result << endl;
    tremove.showSongList();
    result = tremove.removeSong(s19);
    cout << "result = " << result << endl;
    result = tremove.removeSong(s19);
    cout << "result = " << result << endl;
    tremove.showSongList();


    //CONSTRUCTORS TEST

    //these should all return 512
    UtPod tdefault;
    cout << "memory = " << tdefault.getRemainingMemory() << endl;

    UtPod tmake1(-5);
    cout << "memory = " << tmake1.getRemainingMemory() << endl;

    UtPod tmake2(0);
    cout << "memory = " << tmake2.getRemainingMemory() << endl;

    UtPod tmake3(513);
    cout << "memory = " << tmake3.getRemainingMemory() << endl;

    //this should return the inputted size
    UtPod tmake4(500);
    cout << "memory = " << tmake4.getRemainingMemory() << endl;
    
    //clearMemory & deconstructor test

    //getRemaining memory test



}