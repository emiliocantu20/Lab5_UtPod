//
// Created by Emilio Cantu on 24/10/2019.
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <time.h>
#include <random>
#include "UtPod.h"
using namespace std;

UtPod::UtPod() {

    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    SongNode Node;
    SongNode *head = nullptr;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {

    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    SongNode Node;
    SongNode *head = nullptr;
    memSize = size;

}

int UtPod::addSong(Song const &s){
    SongNode *head = songs;
    int memory = s.getSize();

    while(head != nullptr){
        memory = memory + head->s.getSize();
        head = head->next;
    }

    if(memory > memSize) {
        return -1;
    } else {
        auto *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;

        return SUCCESS;
    }
}

void UtPod::showSongList(){
    SongNode *temp = songs;
    cout<<"Playlist: "<<endl;

    while(temp != nullptr){

        cout<< "'" << temp->s.getTitle()<< "', ";
        cout<< temp->s.getArtist()<< ", ";
        cout << temp->s.getSize()<< "MB"<< endl;
        temp = temp->next;

    }
    cout<< endl<<endl;
}

void UtPod::clearMemory(){
   delete songs;
}

int UtPod::removeSong(Song const &s){
    SongNode *temp = songs;
    SongNode *prev = nullptr;

    if(songs == nullptr){ return -1;}

    while ((temp != nullptr) && (!(temp->s == s))) {
            prev = temp;
            temp = temp->next;
        }

    if (prev == nullptr) { //first in list
          songs = temp->next;
          delete temp;

          return SUCCESS;
    } else if (temp != nullptr) {
            prev->next = temp->next;
            delete temp;

            return SUCCESS;
        }

    return NO_MEMORY;
}


int UtPod::getRemainingMemory(){
    SongNode *temp = songs;
    int memory = 0;

    while(temp != nullptr){
        memory = memory + temp->s.getSize();
        temp = temp->next;
    }

    return (memSize - memory);
}

void UtPod::sortSongList(){
    SongNode *p1 = nullptr;
    SongNode *p2 = nullptr;

    for(p1 = songs; p1 != nullptr; p1 = p1->next){
        for(p2 = p1->next; p2 != nullptr; p2 = p2->next){       //Credits to Professor Priebe
            if(p2->s > p1 ->s){
                p1->s.swap(p2->s);
            }
            if(p2->s.getArtist() == p1->s.getArtist() && p2->s.getTitle() < p1->s.getTitle()){
                    p1->s.swap(p2->s);
            }
        }
    }

}

UtPod::~UtPod(){

    delete songs;

}

void UtPod::shuffle() {
    SongNode *p1 = nullptr;
    SongNode *p2 = nullptr;
    int i = 0;
    int numSongs = 0;
    for(p2 = songs; p2!= nullptr;p2 = p2->next ){
        numSongs++;
    }
    srand(time(nullptr));

    for(p1 = songs; p1 != nullptr; p1 = p1->next){
        for(i = rand()%(numSongs*3)+1; i > 0; i--){       //x3 to have a good random margin
            if(p2 == nullptr){
                p2 = songs;
            }
            p2 = p2->next;
        }
        if(p1 != p2 && p2!= nullptr){
            p1->s.swap(p2->s);
        }
    }
}

