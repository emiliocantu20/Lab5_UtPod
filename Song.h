//
// Created by Emilio Cantu on 23/10/2019.
//
#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstddef>

using namespace std;

class Song
        {

        private:
            string artist;
            string title;
            int size;

            
        public:
            //Predetermined constructor
            Song();


            string getArtist() const;
            string getTitle() const;
            int getSize() const;

            //set functions
            void setArtist(string &a);
            void setTitle(string &t);
            void setSize(int &s);
            void swap(Song &g2);
            // Overload functions
            bool operator >(Song const &tune);
            bool operator ==(Song const &tune);
            bool operator <(Song const &tune);
};






#endif //UTPOD_SONG_H
