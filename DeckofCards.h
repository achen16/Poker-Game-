/*
 * project1
 *
 * Alex Chen
 *
 */

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <iostream>
#include <vector>

#include "DeckofCards.h"
#include "Card.h"

class DeckofCards
{
    public:
        DeckofCards();      //constructor that creates a deck of 52 cards
        void Shuffle();     //randomly shuffles the deck
        Card dealCard();    //deals a single card
        bool moreCards();   //checks if there are more cards in the deck
    private:
        int currentCard;  //determines the next card in the deck.
        int rNumber;          //random number for shuffle
        vector<Card> deck;    //vector for the deck
        vector<Card> deal;    //vector for dealCard's temporary deck


};

#endif // DECKOFCARDS_H
