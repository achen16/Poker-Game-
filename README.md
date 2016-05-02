# Poker-Game-
A poker game that I created for a project in my Honors Computing 3 course in Fall of 2013 at UML.

/*
 * project1
 *
 * Alex Chen
 *
 */

POKER GAME README FILE



OVERVIEW:

    This program creates a poker game that allows a user to play against a cpu dealer. This is regular poker rules with a 
deck of 52 cards, with 13 face cards for each of the 4 suits. The player and the dealer are both dealt 5 cards from the
deck and the goal of the game is to have the better hand. The player will have the option of viewing and discarding up to 
3 of their cards in order to try to draw better cards. The dealer will have the same opportunity but is done automatically
by the program based on the hand that the dealer has been dealt. A winner is determined based on the final hand values
of each of the opponents. Good luck!



MAIN.CPP
FUNCTION BREAKDOWN:



	MAIN

Uses a srand function that is called at the beginning of the function for future rand function.
A deck of cards object is created that creates the deck of 52 cards. The deck is then shuffled with the shuffle function.
The player's hand of 5 cards is then drawn from the shuffled deck. The dealer's hand is drawn next. 
The player then is able to view his cards, which have been sorted from lowest numerical face value to the highest.
The player has the option of discarding and replacing up to 3 of his/her cards with the next cards from the deck. 
If the player inputs y, the menu is brought up so that the player can swap out 1,2,or 3 cards.
The player does not know what cards are drawn until they exit or hit their redraw limit (3).
The player's final hand is then checked by the checkResult function to determine if they have a straight, flush, pair, etc.
The same is done to the dealer's initial hand. 
The dealer then has the option to swap up to 3 of their cards. This is done automatically by the program.
The dealer function is called and cards are discarded from the dealer's hand based on their original result.
If the dealer has a flush, straight, 4 of a kind, or two pairs, the dealer will keep the original hand.
If the dealer only has one pair or none, 3 cards will be discarded based on the result of the hand.   
Neither player can see their opponent's hand until the end.
Finally the hands are compared and a winner is determined by the better hand or a draw is declared, which would probably be considered a loss by most dealers.


	DEALHAND

This function deals a hand of 5 cards to the player and the dealer. It calls moreCards to test if there are more cards in the deck.
If there are more cards, then dealCard is called to deal a single card. This is done 5 times initially for each hand.
The cards are pushed back into a vector of card objects and returned for each player.

	PRINTHAND

This function is self explainatory. It prints the cards that the player has in his/her hand. 
It uses the toString function from the card class to print out a string in the form of "Face of Suit"
For example a Queen of Hearts. This is done with a for loop until all cards are printed.

	SORTHAND
This function uses the position of the face values to order the cards from highest numerical value to lowest.
It calculates if the first card is higher than the second, third, fourth, and fifth cards. If it is, it will
swap positions with the cards that are lower value than it. This will continue for all cards until they have 
all been compared and ordered with the lowest at the front and the highest values at the back. This is done 
for convience for both player and dealer.

	MENU
This creates a menu that allows the player to discard up to 3 of their cards and draw new ones from the deck. 
This uses a switch statement that lets the player discard any 3 of the 5 cards in their hand or exit.
They can either exit the switch statement by inputing 6 or by redrawing 3 cards.
The selected cards are erased and the next card is drawn. The player doesn't see any of their new cards until 
they agree to finish discarding their cards.

	CHECKHAND
This function uses the face and suit values to determine the hands final results. It uses the GetFace and GetSuit 
functions from the card class in order to determine if a straight, flush, two pairs, four of a kind, three of a kind,
a pair, or nothing is acquired. 

	DEALER
This lets the dealer swap out up to 3 cards.
The dealer function is called and cards are discarded from the dealer's hand based on their original result.
If the dealer has a flush, straight, 4 of a kind, or two pairs, the dealer will keep the original hand.
If the dealer only has one pair or none, 3 cards will be discarded based on the result of the hand.  

	RESULT
This compares the two hands together and determines a winner. 


CARD CLASS

This contains two static string arrays that holds the face and suit values of the cards.
toString returns a string in the form "face of suit"



DECKOFCARDS CLASS

This creates the deck of 52 cards, shuffles them, and deals out the cards to the respective hands.
It also keeps track of the next card in the deck and the total number of cards in 
the deck. 




CHANGELOG:

In the inital version, I made the dealer a little too risky as to which cards would be discarded. This resulted in less wins for the dealer
and making the game too easy. For example, originally, the dealer would go for a straight or a flush most of the time even if they had a safe hand such
as 3 of a kind. This would usually result in the dealer loosing their good hand and the player would win much more often. The player one 11 out of 20 games 
and tied 3 times with both the palyer and the dealer comming up empty. The dealer would lose all respect if he/she lost so often so I changed the way he/she
discarded their hand. 

Now, if the dealer has a safe bet, he/she will stay and not gamble on the best hand. It is more likely that the 3-of-a-kind will beat out the player since a 
straight, a flush, 4-of-a-kind or two pairs is far less likely to happen. In fact, I haven't ever gotten four-of-a-kind in my games. I have gotten a straight twice
and a flush twice but these were very rare. Before, the dealer never got a higher hand and often lost his good original hand. Now, only if the dealer has a pair or 
lower will he change his hand. If he/she has a pair they will swap the other 3 cards based on the circumstance. This time out of 20 the dealer won 9 times as opposed
to the measly wins in the game before. There were only 2 ties so and 9 player wins so the games were a lot closer and more entertaining. This way the dealer is a lot
more respectable in his game. 

	
	



     
