/*=============================================================================$
|   Header File: deckCardsFunction.h
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #3 Dealer Card
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/15/2019], at the beginning of class
|
|   Description: This header file holds the constant and function prototypes
|               shared by the source files of main.c and dealerFunctions.c

=============================================================================$*/

#include <stdio.h>
#include <stdlib.h> //used for atoi in numberInputValidation
#include <time.h> // Used to make the seed of random in relation to time

#define TRUE 1 //Used for readability
#define FALSE 0 //Used for readability
#define COUNTER_ONE 1 //used to initialize counter of arrays that start at 1
#define SUITS 4 //Maximum number of suits
#define FACES 13 //Maximum numbers of different faces
#define CARDS 52 //Maximum number of cards
#define MAXIMUM_PLAYERS_ALLOWED 13 //Maximum number of players allowed
#define MAXIMUM_CARDS_ALLOWED 13 //Maximum number of cards allow per player
#define CARD_BOUND_ONE 1 //Bound one for full array of cards
#define CARD_BOUND_THIRTEEN 13 // Bound thirteen for full array of cards
#define CARD_BOUND_TWENTYSIX 26 // Bound twenty six for full array of cards
#define CARD_BOUND_THIRTYNINE 39 // Bound thirty nine for full array of cards
#define TOTAL_NUMBER_OF_CARDS 52 //Maximum Number of Cards in the game
#define ARGUMENT_ONE 1 //First Parameter
#define ARGUMENT_TWO 2 //Second Parameter
#define TWO_DIGIT_MAX 2 //Max two digit parameter
#define MAXIMUM_ARGUMENT 3 //Max amount of arguments

enum suitsConstants {HEARTS = 0, DIAMONDS, CLUBS, SPADES};
enum facesConstants {A = 0, TWO, THREE, FOUR, FIVE, SIX,
        SEVEN, EIGHT, NINE, TEN, J, Q, K};

/*----------------Function prototypes-------------------------- **/

void explainTheLegend (const char *suits[], const char *face[]);
void populateArray(int deck[]);
void createOrganizedDeck(int mDeck[], const char *suits[],
        const char *face[]);
int whatCard (int cardInTheDeck);
int whatSuit (int cardInDeck);
void printDeckOfCards (int faceNumber, int suitNumber,
        const char *suits[], const char *face[]);
void shuffle (int deck [], const char *suits[], const char *face[]);
void swap (int *currentPosition, int *newPosition);
void createDeckToDeal(int dDeck[], int play[][MAXIMUM_CARDS_ALLOWED],
        char* argv[]);
void provideDeck (const char *suits[], const char *face[],
           int play[][MAXIMUM_CARDS_ALLOWED], char* argv[]);

