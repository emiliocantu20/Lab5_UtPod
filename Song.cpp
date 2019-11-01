//
// Created by Emilio Cantu on 24/10/2019.
//
#include <iostream>
#include <cstddef>
#include "Song.h"

Song::Song(){}

void Song::setArtist(string &a){
    artist = a;
}

void Song::setTitle(string &t){
    title = t;
}

void Song::setSize(int &s){
    size = s;
}

string Song::getArtist() const {
    return artist;
}
string Song::getTitle() const{
    return title;
}
int Song::getSize() const{
    return size;
}

//operator overload

bool Song::operator >(Song const &tune)
{
    return (getArtist() < tune.getArtist());
}
bool Song::operator ==(Song const &tune)
{
    return (getArtist() == tune.getArtist() &&
            getTitle() == tune.getTitle() &&
            getSize() == tune.getSize());
}
bool Song::operator < (Song const &tune)
{
    return (getArtist() > tune.getArtist());
}

void Song::swap(Song &s)                //Credit to Professor Priebe
{
    Song temp = s;
    s = *this;
    *this = temp;
}
