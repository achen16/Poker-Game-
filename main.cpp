/*
 * project1
 *
 * Alex Chen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>    //for swap function
#include <ctime>        //for time

#include "Card.h"
#include "DeckofCards.h"

using namespace std;

vector<Card> DealHand( DeckofCards& deal );                       //Deals 5 card Hands

void PrintHand( vector<Card> & Hand, string name );               //Prints the Cards in the Hand

vector<Card> SortHand( vector<Card> & Sort );                     //Sorts Cards in order of face

vector<Card> Menu( DeckofCards& m, vector<Card> & New );          //Lets user discard up to 3 cards

int CheckHand( vector<Card> & Result, string p );                 //Checks for straight, flush, etc

vector<Card> DealerHand( DeckofCards Hand, vector<Card> & d );    //Dealer can discard

void Result( int Player, int Dealer );                            //Checks who wins


int main(int argc, char **argv)
{
    srand( time( 0 ) );  //Initialize random number generator for shuffle

    char choice, Replay;      //choice asks if user wants to discard
    int pResult, dResult;     //calculates hand results
    DeckofCards d;            //class object for deck

    cout << "Welcome to Poker! Good luck!\n" << endl;

    do {
        d.Shuffle();   //calls shuffle function
        cout << "\nThe deck has been shuffled.\n" << endl;
        cout << "\nYour hand is being drawn:\n" << endl;

        //deals 5 card hands for both the player and the dealer
        vector<Card> Player = DealHand( d );
        vector<Card> Dealer = DealHand( d );

        //sorts the players hand and prints it
        Player = SortHand( Player );
        PrintHand( Player, "Player's" );

        cout << "\nDo you want to change your hand ( y/n )? " << endl;
        cin >> choice;

        //calls Menu function if user chooses yes
        if ( choice == 'Y' || choice == 'y' )
        {
            Player = Menu( d, Player );
        }
        else
        {
            cout << endl << "You kept the same hand" << endl;
        }

        //Calculates final hand result for player
        PrintHand( Player, "Your Final" );
        pResult = CheckHand( Player, "You have" );


        //Dealer function lets dealer change hand
        Dealer = DealerHand( d, Dealer );
        PrintHand( Dealer, "The Dealer's Final" );
        dResult = CheckHand( Dealer, "The Dealer now has" );

        //Player and Dealer hand results are compared. Winner is determined
        Result( pResult, dResult );


	//Asks if player wants to play again
        cout << "\n\nDo you want to play again? ( y for yes, anything else to exit )" << endl;
        cin >> Replay;

    }while ( Replay == 'Y' || Replay == 'y' ); 

    cout << "Thank you for playing" << endl;

    return 0;

}


vector<Card> DealHand( DeckofCards& deal )
{

    /* Calls the dealCard function if there are more cards
       in the deck. Pushes 5 cards into the Hand vector
       and returns it for the Player and Dealer hands */

    vector<Card> Hand;

    for ( int cards = 0; cards < 5; cards++ )
    {
        if ( deal.moreCards() )
        {
            Hand.push_back( deal.dealCard() );
        }
        else
        {
        cout << "There are no more cards remaining" << endl;
        return Hand;
        }
    }
    return Hand;
}


void PrintHand( vector<Card> & Hand, string name )
{
    /* Prints out a hand, either the player's
       or Dealer's. Hand.size() is 5. */

    cout << "\n\n" << name <<" Hand (Sorted)\n" << endl;

    for ( int i = 0; i < Hand.size(); i++ )
    {
        cout << i + 1 << ". " << Hand[i].toString() << endl;
    }
}

vector<Card> SortHand( vector<Card> & Sort )
{
    /* Sorts the hand based on the face value of the
       cards from low to high. if card 1 is higher
       than card 2 then they're positions are swapped */

    int card1, card2;
    for ( int Position = 0; Position < 4; Position++ )
    {
        for ( int check = 0; check < 4 - Position; check++ )
        {
           card1 = Sort[check].GetFace();
           card2 = Sort[check+1].GetFace();

           if ( card1 > card2 )
           {
               swap( Sort[check], Sort[check+1] );
           }
        }
    }

    return Sort;
}

vector<Card> Menu( DeckofCards& m, vector<Card> & New )
{
    /* Creates a menu that allows the player to discard up to
       3 of their cards. They can either exit the switch
       statement by inputing 6 or by redrawing 3 cards. The
       selected cards are erased and the next card is drawn */

    int menu, Draw = 0, Redraw = 3;

    while ( menu != 6 )
    {
        if ( Redraw == 0 )
        {
            menu == 7;
            cout << "\nYou are out of Discards\n " << endl;

            for ( int x = 0; x < Draw; x++ )
            {
                New.push_back( m.dealCard() );
            }

            New = SortHand( New );

            return New;
        }
        else
        {
            PrintHand( New, "Player" );

            cout << "\n\n****************************************************** " << endl;
            cout << "*  Select an option from the menu                    *" << endl;
            cout << "*  You can discard up to " << Redraw << " more cards                *"<< endl ;
            cout << "****************************************************** " << endl;
            cout << "*                                                    *" << endl;
            cout << "*   1. Discard your 1st Card                         *" << endl;
            cout << "*   2. Discard your 2nd Card                         *" << endl;
            cout << "*   3. Discard your 3rd Card                         *" << endl;
            cout << "*   4. Discard your 4th Card                         *" << endl;
            cout << "*   5. Discard your 5th Card                         *" << endl;
            cout << "*   6. Finish                                        *" << endl;
            cout << "*                                                    *" << endl;
            cout << "******************************************************\n\n" << endl;
            cout << "Enter your choice: " << endl;
            cin >> menu;

            switch( menu )
            {
            case 1 :
                cout << "\nThe " << New[0].toString() << " was discarded" << endl;
                New.erase( New.begin() );
                Redraw--;
                Draw++;
                break;
            case 2 :
                cout << "\nThe " << New[1].toString() << " was discarded" << endl;
                New.erase( New.begin() + 1 );
                Redraw--;
                Draw++;
                break;
            case 3 :
                cout << "\nThe " << New[2].toString() << " was discarded" << endl;
                New.erase( New.begin() + 2 );
                Redraw--;
                Draw++;
                break;
            case 4 :
                if ( New.size() < 4 )
                {
                    cout << "\nYou only have " << New.size() << " cards left. Try Again." << endl;
                }
                else
                {
                    cout << "\nThe " << New[3].toString() << " was discarded" << endl;
                    New.erase( New.begin() + 3 );
                    Redraw--;
                    Draw++;
                }
                break;
            case 5 :
                if ( New.size() < 5 )
                {
                    cout << "\nYou only have " << New.size() << " cards left. Try Again." << endl;
                }
                else
                {
                    cout << "\nThe " << New[4].toString() << " was discarded" << endl;
                    New.erase( New.begin() + 4 );
                    Redraw--;
                    Draw++;
                }
                break;
            case 6 :
                for ( int x = 0; x < Draw; x++ )
                {
                    New.push_back( m.dealCard() );
                }

                New = SortHand( New );

                return New;
                break;
            default :
                cout << "\nERROR. Incorrect choice. Try again " << endl;
            }
        }
    }

    return New;
}

int CheckHand( vector<Card> & Value, string p )
{
    /* This checks the hands for straights, flushes, etc.
       It finds the face and suit value for each card and
       compares them to find the hand result. A number is
       assigned and returned to compare to the opponent */

    int Result;
    int f1, f2, f3, f4, f5;
    int s1, s2, s3, s4, s5;

    f1 = Value[0].GetFace();
    f2 = Value[1].GetFace();
    f3 = Value[2].GetFace();
    f4 = Value[3].GetFace();
    f5 = Value[4].GetFace();

    s1 = Value[0].GetSuit();
    s2 = Value[1].GetSuit();
    s3 = Value[2].GetSuit();
    s4 = Value[3].GetSuit();
    s5 = Value[4].GetSuit();

    //check for straight
    if ( ( f2 == f1 + 1 ) &&  ( f3 == f2 + 1 ) &&  ( f4 == f3 + 1 ) && ( f5 == f4 + 1 ) )
    {
        cout << "\n" << p << " a straight!" << endl;
        Result = 4;
    }
    //check for a flush
    else if ( s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 )
    {
        cout << "\n" << p << " a flush!" << endl;
        Result = 5;
    }
    //check for 4 of a kind
    else if ( ( f1 == f2  && f2 == f3 && f3 == f4 ) || ( f2 == f3 && f3 == f4 && f4 == f5 ) )
    {
        cout << "\n" << p << " 4 of a kind!" << endl;
        Result = 6;
    }
    //check for 3 of a kind
    else if ( ( f1 == f2 && f2 == f3 ) || ( f2 == f3 && f3 == f4 ) ||  ( f3 == f4 && f4 == f5 ) )
    {
        cout << "\n" << p << " 3 of a kind!" << endl;
        Result = 3;
    }
    //check for 2 pairs
    else if ( ( f1 == f2 && ( f3 == f4 || f4 == f5 ) ) || ( f2 == f3 && f4 == f5 ) )
    {
       cout << "\n" << p << " 2 pairs!" << endl;
        Result = 2;
    }
    //check for 1 pair
    else if (  ( f1 == f2 ) || ( f2 == f3 ) || ( f3 == f4 ) || ( f4 == f5 ) )
    {
        cout << "\n" << p << " a pair!" << endl;
        Result = 1;
    }
    //You have nothing. Tough luck </3
    else
    {
        cout << "\n" << p << " nothing. Tough luck" << endl;
        Result = 0;
    }

    return Result;
}

vector<Card> DealerHand( DeckofCards Hand, vector<Card> & d )
{
    /* This allows the dealer to swap out up to 3 cards based
       on the result his hand got. This is done without any
       user input. If the hand only has a pair or nothing,
       then 3 cards are discarded based on the result */

    int f1, f2, f3, f4, f5;
    int s1, s2, s3, s4, s5;

    f1 = d[0].GetFace();
    f2 = d[1].GetFace();
    f3 = d[2].GetFace();
    f4 = d[3].GetFace();
    f5 = d[4].GetFace();

    s1 = d[0].GetSuit();
    s2 = d[1].GetSuit();
    s3 = d[2].GetSuit();
    s4 = d[3].GetSuit();
    s5 = d[4].GetSuit();

    int result = CheckHand( d, "\nThe Dealer initially has" );
    cout << "The dealer is considering his hand\n" << endl;

    //Dealer keeps his hand if he has a straight, flush, 2 pairs, or 3/4 or a kind
    if ( result == 6 || result == 5 || result == 4 || result == 3 || result == 2 )
    {
        cout << "\nThe dealer kept his initial hand" << endl;
        return d;
    }
    //Dealer has a pair, strategically swaps other 3 cards
    else if ( result == 1 )
    {
        if ( f1 == f2 )
        {
           for ( int i = 2; i < 5; i++ )
           {
               d.erase( d.begin() + i );
               d.push_back( Hand.dealCard() );
           }
        }
        else if ( f2 == f3 )
        {
            d.erase( d.begin() );
            d.erase( d.begin() + 3 );
            d.erase( d.begin() + 2 );
            d.push_back( Hand.dealCard() );
            d.push_back( Hand.dealCard() );
            d.push_back( Hand.dealCard() );
        }
        else if ( f3 == f4 )
        {
            d.erase( d.begin() );
            d.erase( d.begin() );
            d.erase( d.begin() + 2 );
            d.push_back( Hand.dealCard() );
            d.push_back( Hand.dealCard() );
            d.push_back( Hand.dealCard() );
        }
        else
        {
            for ( int j = 0; j < 3; j++ )
           {
               d.erase( d.begin() );
               d.push_back( Hand.dealCard() );
           }
        }
    }
    //Dealer has nothing and exchanges max 3 cards
    else
    {
        for ( int x = 0; x < 3; x++ )
        {
            d.erase( d.begin() );
            d.push_back( Hand.dealCard() );
        }
    }

    cout << "The dealer discarded 3 of his/her cards total" << endl;
    return d;
}

void Result( int Player, int Dealer )
{
    //This uses the player results to determine a winner

    if ( Player > Dealer )
    {
        cout << "\n\nYou Win!" << endl;
    }
    else if ( Player == Dealer )
    {
        cout << "\n\nIt was a tie" << endl;
    }
    else
    {
        cout << "\n\nYou Lose ): " << endl;
    }

}
