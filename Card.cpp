/*
 * project1
 *
 * Alex Chen
 *
 */

#include "Card.h"
#include <string>
#include <iostream>

using namespace std;

    //initialize static string arrays for suits and faces
    const string Card::suits[4] = { "Clubs", "Spades", "Hearts", "Diamonds" };
    const string Card::faces[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };


Card::Card( int s, int f )
{
    //set the suit and face data members
    suit = s;
    face = f;
}

string Card::toString()
{
    //concatenate the strings and returns a string as "face of suit"
    string card = faces[face] + " of "  + suits[suit];
    return card;
}

int Card::GetFace()
{
    //returns the array position for the faces 0-13
    int faceNumber = face;
    return faceNumber;
}

int Card::GetSuit()
{
    //returns the array position for the suits 0-3
    int suitNumber = suit;
    return suitNumber;
}
