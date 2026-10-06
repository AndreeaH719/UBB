#pragma once
#include <string>
#include <iostream>

class Artist
{
    private:
       std::string name;
       std::string album;
       int wins;
       std::string song;
    public:
        Artist(const std::string&name="", const std::string& album = "", const std::string& song = "", int wins = 0);

        std::string getName() const {return this->name;}
        std::string getAlbum() const {return this->album;}
        std::string getSong() const {return this->song;}
        int getWins() const {return this->wins;}

        void setName(const std::string& val1) {this->name = val1;}
        void setAlbum(const std::string& val2) {this->album = val2;}
        void setSong(const std::string& val3) {this->song = val3;}
        void setWins(int val4) {this->wins = val4;}

        friend std::ostream& operator <<(std::ostream& os, const Artist &a)
        {
           os << a.name << " | " << a.album << " | " << a.song << " | " << a.wins << " | ";
           return os;
        }

        bool operator == (const Artist & a)
        {
            return name == a.name && album == a.album;
        }
};

