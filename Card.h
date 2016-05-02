/*
 * project1
 *
 * Alex Chen
 *
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;


class Card
{
    public:
        Card( int f, int s );   //constructor for face and suit values
        string toString();      //returns string in form "face of suit"
        int GetFace();          //returns the position of the face value
        int GetSuit();          //returns the position of the suit value
    private:
        int suit;
        int face;
        int faceNumber;                //face number 0-12 for GetFace
        int suitNumber;                //suit number 0-3 for GetSuit
        static const string suits[];   //static string array for 4 suits
        static const string faces[];   //static string array for 13 faces
};

#endif // CARD_H
