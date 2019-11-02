//
// Created by Emilio Cantu on 23/10/2019.
//
#include "Song.h"
#include "UtPod.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stddef.h>

using namespace std;

void inputSong( Song &Tune);
void inputSong1( Song &Tune);
void inputSong2( Song &Tune);
void inputSong3(Song &Tune);
void getData(UtPod &mp3, Song playlist[], int &n);
void printPlaylist(Song playlist[], int x);
int main(){

    UtPod ipod(350);
    UtPod mp3;
    Song tune;
    Song playlist[20];
    Song Tune;
    inputSong(Tune);
    Song Tune1;
    inputSong1(Tune1);
    Song Tune2;
    inputSong2(Tune2);
    Song Tune3;
    inputSong3(Tune3);
    int good = 0;
    int x = 0;
    int numberSongs;
    char input = ' ';

    getData(mp3, playlist, numberSongs);

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
    cout<<"remaining memory in ipod is: "<< ipod.getRemainingMemory()<<"MB"<<endl;

    cout<<endl<<endl;

    ipod.sortSongList();
    ipod.showSongList();
    ipod.shuffle();
    ipod.showSongList();
    good = ipod.removeSong(Tune3);

    if(good == 0){
        cout<< "song removed successfully"<<endl;
    }
    if(good == -1){
        cout<< "No songs removed"<<endl;
    }
    ipod.showSongList();
   // ipod.clearMemory();
    ipod.showSongList();

//////////END OF IPOD///////////
//////MP3/////////////////////

    cout<< "MP3"<<endl;
    while(1){
        cout<< "'press s to shuffle'"<<endl;
        cout<< "'press a to sort'"<<endl;
        cout<< "'press r to remove'"<<endl;
        cout<< "'press m to get remaining memory'"<<endl;
        cout<< "'press t for total memory'"<<endl;
        cout<< "'press c to clear memory'"<<endl;
        cout<< "'press p to print the playlist'"<<endl;
        cout<< "'press 0 to exit the program"<<endl;
        cin >> input;

        if(input == 's'){
            mp3.shuffle();
            mp3.showSongList();
        }
        if(input == 'a'){
            mp3.sortSongList();
            mp3.showSongList();
        }
        if(input == 'r'){
            int state = 0;
            cout<< "Choose the number of the song to be deleted:  "<<endl;
            printPlaylist(playlist, numberSongs);
            cin >> x;
            state = mp3.removeSong(playlist[x]);
            if(state == 0){
                cout << "Song removed successfully."<<endl<< endl;
                mp3.showSongList();
            }else{cout<<"Unable to remove song"<<endl;}
        }
        if(input == 'm'){
            cout<< mp3.getRemainingMemory()<<"MB"<<endl<<endl;
        }
        if(input == 't'){
            cout<< mp3.getTotalMemory()<<"MB"<<endl<<endl;
        }
        if(input == 'c'){
            mp3.clearMemory();
        }
        if(input == 'p'){
            mp3.showSongList();
        }
        if(input == '0'){
            mp3.clearMemory();
            exit(0);
        }
    }
}


void inputSong( Song &Tune){
    string artistName;
    string titleName;
    int songSize = 0;
    artistName = "Queen";
    titleName = "Bohemian Rhapsody";
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
    songSize = 93;

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
    songSize = 415;

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
    songSize = 61;

    Tune.setArtist(artistName);
    Tune.setTitle(titleName);
    Tune.setSize(songSize);



}

void getData(UtPod &mp3, Song playlist[], int &n){

    ifstream inFile;
    inFile.open("playlist.txt");

    string artistName;
    string songTitle;
    int songSize = 0;
    int i =0;
    int good;
    inFile >> artistName;
    while (inFile) {
        inFile >> songTitle;
        inFile >> songSize;
        Song tune(artistName, songTitle, songSize);

        playlist[i].setArtist(artistName);
        playlist[i].setTitle(songTitle);
        playlist[i].setSize(songSize);

        good = mp3.addSong(tune);
        inFile >> artistName;
        i++;
    }

    n = i;
}
void printPlaylist(Song playlist[], int numberSongs){
    int i = 0;
    for(i = 0; i< numberSongs; i++){
        cout<<i<<") "<<playlist[i].getArtist()<<" "<<"'"<< playlist[i].getTitle()<<"'"<<" "<< playlist[i].getSize()<<endl;
    }

}
