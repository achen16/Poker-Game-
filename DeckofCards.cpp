/*
 * project1
 *
 * Alex Chen
 *
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>   //for swap function

#include "DeckofCards.h"
#include "Card.h"

using namespace std;

DeckofCards::DeckofCards()
{
    /* use nested for loop to push_back each of the 52
       cards into vector deck. newcard is a card object
       that stores face and suit values that are pushed */

    for  ( int suit =0; suit < 4; suit++ )
    {
        for ( int face = 0; face < 13; face++ )
        {
            Card newcard( suit, face );
            deck.push_back( newcard );
        }
   }
}

void DeckofCards::Shuffle()
{
    /* Generates a random number in the deck and
       swaps position for with another card */

    for ( int i = 0; i < deck.size(); i++ )
    {
        rNumber = rand() % 52;
        swap( deck[i], deck[rNumber] );
    }

}

Card DeckofCards::dealCard()
{
    /* Pushes the next card in the deck into the
       deal vector and erases it from the original
       deck. The card is returned. It only tells
       the player the cards he/she drew, not the dealers */

    if ( deck.size() == 52 ) {
        currentCard = 0;
    }
    else {
        currentCard++;
    }

    deal.push_back( deck[0] );
    deck.erase( deck.begin() );

    if ( currentCard < 5 || currentCard > 9 )
    {
        cout << "The " << deal[currentCard].toString() << " was drawn " << endl;
    }

    return deal[currentCard];
}

bool DeckofCards::moreCards()
{
    //checks if there are more cards in the deck

    if ( deck.size() != 0 )
    {
        return true;
    }

    else
    {
        return false;
    }
}

