#include<iostream>
#ifndef SONG_H_
#define SONG_H_
using namespace std;


class Song{
public:
    Song();
    Song(const string& title, const string& author = "", const string& album = "");
    void setTitle(string title);  //"set" in setTitle here means "give a value" and has nothing

                                    // to do with the Set class. Similarly for setAuthor and setAlbum

    void setAuthor(string author);
    void setAlbum(string album);
    string getTitle() const;
    string getAuthor() const;
    string getAlbum() const;
    friend bool operator==(const Song& lhs, const Song& rhs);

private:
    string title_;
    string author_;
    string album_;
};
#endif