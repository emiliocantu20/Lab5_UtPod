//
// Created by Emilio Cantu on 23/10/2019.
//
#include "Song.h"
#include "UtPod.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stddef.h>

using namespace std;

void inputSong( Song &Tune);
void inputSong1( Song &Tune);
void inputSong2( Song &Tune);
void inputSong3(Song &Tune);

int main(){

    UtPod ipod;
    Song Tune;
    inputSong(Tune);
    Song Tune1;
    inputSong1(Tune1);
    Song Tune2;
    inputSong2(Tune2);
    Song Tune3;
    inputSong3(Tune3);

    int good = 0;

    cout<<"Total Memory of this ipod is "<<ipod.getTotalMemory()<<"MB"<<endl;

    good = ipod.addSong(Tune);
    if(good == -1){
        cout<< "Not enough Memory"<< endl;
    }
    ipod.showSongList();
    cout<<"remaining memory is: "<< ipod.getRemainingMemory()<<"MB"<<endl;

    good = ipod.addSong(Tune1);
    if(good == -1){
        cout<< "Not enough Memory"<< endl;
    }
    ipod.showSongList();
    cout<<"remaining memory is: "<< ipod.getRemainingMemory()<<"MB"<<endl;

    good = ipod.addSong(Tune2);
    if(good == -1){
        cout<< "Not enough Memory"<< endl;
    }
    ipod.showSongList();
    cout<<"remaining memory is: "<< ipod.getRemainingMemory()<<"MB"<<endl;

    good = ipod.addSong(Tune3);
    if(good == -1){
        cout<< "Not enough Memory"<< endl;
    }
    ipod.showSongList();
    cout<<"remaining memory is: "<< ipod.getRemainingMemory()<<"MB"<<endl;

    cout<<endl<<endl;

    //good = ipod.removeSong(Tune);

    if(good == 0){
        cout<< "song removed successfully"<<endl;
    }
    if(good == -1){
        cout<< "No songs removed"<<endl;
    }
   // ipod.showSongList();

    ipod.sortSongList();
    ipod.showSongList();
    ipod.shuffle();
    ipod.showSongList();
    //ipod.removeSong(Tune2);



    //ipod.showSongList();
    //ipod.clearMemory();
    //ipod.~UtPod();

}


void inputSong( Song &Tune){
    string artistName;
    string titleName;
    int songSize = 0;

    //cout<< "Enter an artist: "<< endl;
    //cin >> artistName;
    artistName = "Queen";
    //cout<< "Enter a title: "<< endl;
    //cin >> titleName;
    titleName = "Bohemian Rhapsody";
    //cout<< "Song size:  "<< endl;
    //cin >> songSize;
    songSize = 180;

    Tune.setArtist(artistName);
    Tune.setTitle(titleName);
    Tune.setSize(songSize);



}
void inputSong1( Song &Tune){
    string artistName;
    string titleName;
    int songSize = 0;

    artistName = "Toto";
    titleName = "Africa";
    songSize = 75;

    Tune.setArtist(artistName);
    Tune.setTitle(titleName);
    Tune.setSize(songSize);



}
void inputSong2( Song &Tune){
    string artistName;
    string titleName;
    int songSize = 0;

    artistName = "Pink Floyd";
    titleName = "Echoes";
    songSize = 79;

    Tune.setArtist(artistName);
    Tune.setTitle(titleName);
    Tune.setSize(songSize);



}
void inputSong3( Song &Tune){
    string artistName;
    string titleName;
    int songSize = 0;

    artistName = "Bob Dylan";
    titleName = "Like A Rolling Stone";
    songSize = 86;

    Tune.setArtist(artistName);
    Tune.setTitle(titleName);
    Tune.setSize(songSize);



}


