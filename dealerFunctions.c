/*=============================================================================$
|   Source File: dealerFunctions.c
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #3 Dealer Card
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/15/2019], at the beginning of class
|
|   Description: This source file hold the functions for creating the deck,
|               dealing the deck, creating the shuffle, printing the shuffle,
|               dealing the cards of the players

=============================================================================$*/

#include "deckCardsFunctions.h" //Header File for Constants and function prototypes

/*----------------------- explainTheLegend() -------------------------
|   Function void explainTheLegend()
|
|   Purpose:  This function explains the legend of the cards.
|
|    @param suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|
|    @return  none
*-------------------------------------------------------------------*/

void explainTheLegend(const char *suits[], const char *face[])
{
    printf("\n%s\n", "The legend is as follows: ");
    printf("\tSuits: Hearts = '%s', Diamonds: '%s', Clubs: '%s', "
           " and Spades: '%s' \n" , suits[HEARTS],suits[DIAMONDS],
           suits[CLUBS], suits[SPADES]);
    printf("\tRanks: Ace='%s', Two='%s', Three='%s', Four='%s',"
           " Five='%s', Six='%s', Seven='%s', Eight='%s', Nine='%s',"
           " Ten='%s', Jack='%s', Queen='%s', King='%s'\n", face[A],
           face[TWO], face[THREE], face[FOUR], face[FIVE], face[SIX],
           face[SEVEN],face[EIGHT], face[NINE], face[TEN], face[J],
           face[Q], face[K]);

}

/*--------------- populateArray(int deck[]) ------------------------
|   Function void populateArray(int deck[])
|
|   Purpose:  This function will populate the card array.
|
|   Explanation: Started the array at index COUNTER_1 (1), as it in
|               later functions it will be easier to manipulate to
|               print the order deck.
|
|    @param suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|
|    @return  none
*-------------------------------------------------------------------*/
void populateArray(int deck[])
{
    int counter = 0;
    for (counter = COUNTER_ONE; counter <= CARDS; counter++)
    {
        deck[counter] = counter;
    }
}

/* ---------------------------------------------------------------------
|createOrganizedDeck(int mDeck[], const char *suits[],
|                                           const char *face[])
|
|   Function void createOrganizedDeck(int mDeck[],
|                   const char *suits[], const char *face[])
|
|   Purpose:  This function will be the brain to print the array.
|
|   Explanation:
|           1. A for loop that goes from 0 - FACES
|              - The card number is got it by adding a COUNTER_1 as
|                we populated our deck array from COUNTER_1
|           2. A for loop from 0 - SUITS
|              - We will gather the cards in order in this part of
|               array. Calling the function whatSuit, and the
|               function whatCard we know the range of where the card
|               is and we can print the exact card. As we are printing
|               the cards in order, we are adding FACES(13) to every
|               card from 0-FACES. This will get the cards in order
|               with their respective suits.
|
|    @param  mDeck[], int[], populated array
|            suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|
|    @return  none
*-------------------------------------------------------------------*/
void createOrganizedDeck(int mDeck[], const char *suits[],
                         const char *face[])
{
    int counterOfFaces = 0;
    int counterOfSuits = 0;
    int indexInPopulatedDeckArray = 0;
    int indexOfConstantArrayOfFaces = 0;
    int cardInDeck = 0;
    int printCounter = 0;
    int suitNumber = 0;

    puts("\nOriginal Ordered Deck:");

    for (counterOfFaces = 0; counterOfFaces < FACES; counterOfFaces++)
    {
        indexInPopulatedDeckArray = counterOfFaces + COUNTER_ONE;

        for(counterOfSuits  = 0; counterOfSuits  < SUITS;
            counterOfSuits ++)
        {
            cardInDeck = mDeck[indexInPopulatedDeckArray];
            indexOfConstantArrayOfFaces = whatCard(cardInDeck);
            suitNumber = whatSuit (cardInDeck);
            printDeckOfCards(indexOfConstantArrayOfFaces,
                             suitNumber, suits, face);
            indexInPopulatedDeckArray = indexInPopulatedDeckArray +
                                        FACES;
            printCounter++;
            if (printCounter == FACES)
            {
                puts("");
                printCounter = 0;
            }
        }
    }
}

/*---------- whatCard (int cardInTheDeck) ------------------------
|   Function int whatCard (int cardInTheDeck)
|
|   Purpose:  This function will return the index of what card
|               to pick in the faces array.
|
|    @param cardInTheDeck, int, card in the deck array
|
|    @return  actualIndexInFaceArray, int, index in constant face
|                                           array.
*-------------------------------------------------------------------*/
int whatCard (int cardInTheDeck)
{
    int actualIndexInFaceArray = 0;
    int indexOfCardArray = 0;
    indexOfCardArray = cardInTheDeck % FACES;

    if (indexOfCardArray == 0)
    {
        actualIndexInFaceArray = FACES - COUNTER_ONE;
        return actualIndexInFaceArray;
    }
    else
    {
        actualIndexInFaceArray = indexOfCardArray - COUNTER_ONE;
        return  actualIndexInFaceArray;
    }

}

/*---------- whatSuit (int cardInDeck)) ------------------------
|   Function int whatSuit (int cardInDeck)
|
|   Purpose:  This function will return the index of what suit
|               to pick in the suit array.
|
|    @param cardInTheDeck, int, card in the deck array
|
|    @return  suitNumber, int, index in constant suit array.
*-------------------------------------------------------------------*/
int whatSuit (int cardInDeck)
{
    int suitNumber = 0;

    if (cardInDeck <= CARD_BOUND_THIRTEEN)
    {
        suitNumber = HEARTS;
        return  suitNumber;
    }
    else if (cardInDeck > CARD_BOUND_THIRTEEN &&
             cardInDeck <= CARD_BOUND_TWENTYSIX)
    {
        suitNumber = DIAMONDS;
        return  suitNumber;
    }
    else if (cardInDeck > CARD_BOUND_TWENTYSIX &&
             cardInDeck <=CARD_BOUND_THIRTYNINE)
    {
        suitNumber = CLUBS;
        return  suitNumber;
    }
    else
    {
        suitNumber = SPADES;
        return  suitNumber;
    }
}

/*-------------------------------------------------------------
 * printDeckOfCards (int faceNumber, int suitNumber,
|                    const char *suits[], const char *face[])
|
|   Function void printDeckOfCards (int faceNumber,
|       int suitNumber,const char *suits[], const char *face[])
|
|   Purpose:  The purpose of this function is to print the deck
|               with faces and suits.
|
|    @param  faceNumber, int, index of the card in face array.
|            suitNumber, int, index of suit in the suit array.
|            suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|
|    @return  none
*----------------------------------------------------------------*/
void printDeckOfCards (int faceNumber, int suitNumber,
                       const char *suits[], const char *face[])
{
    printf("[%1.5s-", face[faceNumber]);
    printf("%1.5s] ", suits[suitNumber]);

}

/* ---------------------------------------------------------------------
|   shuffle (int deck [], const char *suits[], const char *face[])
|
|   Function void shuffle (int deck [], const char *suits[],
|                           const char *face[])
|
|   Purpose:  The purpose of this function is to shuffle the deck.
|
|   Explanation:
|           1. Here we used the srandom(time(NULL)) to generate a
|               a seed that really is random, as it is attached to
|               time.
|           2. We loop through our original array of cards and we
|              shuffle the array with this seed generated using the
|              formula:
|              randomLocation = COUNTER_ONE + (rand() % CARDS);
|              To know more about the procedure of creating a
|              a random seed the link below will show:
|
|https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|           3. After generating the random shuffle array of cards,
|              similar process to print the cards will follow.
|
|    @param  deck[], int[], populated array
|            suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|
|    @return  none
*-------------------------------------------------------------------*/
void shuffle (int deck [], const char *suits[], const char *face[])
{
    srand(time(NULL));
    unsigned int counter = 0;
    int randomLocation = 0;
    int cardInTheDeck = 0;
    int printCounter = 0;
    int indexOfConstantArrayOfFaces = 0;
    int indexOfConstantArrayOfSuits = 0;

    for (counter = COUNTER_ONE; counter <= CARDS; counter++)
    {
        randomLocation = COUNTER_ONE + (rand() % CARDS);
        swap(&deck[counter], &deck[randomLocation]);
    }

    puts("\nRandom Shuffled Deck:");

    for (counter = COUNTER_ONE; counter <= CARDS; counter++)
    {
        cardInTheDeck = deck[counter];
        indexOfConstantArrayOfFaces = whatCard(cardInTheDeck);
        indexOfConstantArrayOfSuits = whatSuit(cardInTheDeck);
        printDeckOfCards(indexOfConstantArrayOfFaces,
                         indexOfConstantArrayOfSuits, suits, face);
        printCounter++;
        if (printCounter == FACES)
        {
            puts("");
            printCounter = 0;
        }
    }
    puts("");
}

/*----swap (int *currentPosition, int *newPosition)-------------
|
|   Function void swap (int *currentPosition, int *newPosition)
|
|   Purpose:  The purpose of this function is swap the pointers.
|
|    @param  *currentPosition, int*, index of for loop array
|            *newPosition, int*, index of random position.
|
|    @return  none
*----------------------------------------------------------------*/
void swap (int *currentPosition, int *newPosition)
{
    int temporaryPosition = *currentPosition;
    *currentPosition = *newPosition;
    *newPosition = temporaryPosition;
}

/* ---------------------------------------------------------------------
|   createDeckToDeal(int dDeck[], int play[][MAXIMUM_CARDS_ALLOWED],
|        char* argv[])
|
|   Function void createDeckToDeal(int dDeck[],
|                   int play[][MAXIMUM_CARDS_ALLOWED],
|                                            char* argv[])
|
|   Purpose:  The purpose of this function is to populate the two
|               dimensional array.
|
|    @param  dDeck[], int[], populated array already shuffled
|            play[][MAXIMUM_CARDS_ALLOWED], int, array to distribute
|                                               deck.
|            argv[], char*, pointer to the input from main.
|
|    @return  none
*-------------------------------------------------------------------*/

void createDeckToDeal(int dDeck[], int play[][MAXIMUM_CARDS_ALLOWED],
                      char* argv[])
{
    int numberOfCardsToDistribute = 0;

    int numberOfPlayersInTheGame = 0;

    numberOfCardsToDistribute = atoi(argv[ARGUMENT_ONE]);
    numberOfPlayersInTheGame = atoi(argv[ARGUMENT_TWO]);

    int counter = 0;
    int counter2 = 0;
    int nestedCounter = 0;
    int card = 0;
    int insideCounter = 0;
    for (counter = 0; counter < numberOfPlayersInTheGame; counter++)
    {
        counter2 = 0;
        for (nestedCounter = insideCounter;
             nestedCounter < (numberOfCardsToDistribute+insideCounter);
             nestedCounter++)
        {
            card = dDeck[nestedCounter+COUNTER_ONE];
            //printf("%d ", card);
            play[counter][counter2] = card;
            counter2++;
        }
        //printf("%s\n", "");
        insideCounter = nestedCounter;

    }
}

/* ---------------------------------------------------------------------
|  deal (const char *suits[], const char *face[],
|           int play[][MAXIMUM_CARDS_ALLOWED], char* argv[])
|
|   Function void deal (const char *suits[], const char *face[],
|           int play[][MAXIMUM_CARDS_ALLOWED], char* argv[])
|
|   Purpose:  The purpose of this function is to deal the cards
|
|    @param  suits[], char*, pointer to array of suits
|            face[], char*, pointer to array of face
|            play[][MAXIMUM_CARDS_ALLOWED], int, array to distribute
|                                               deck.
|            argv[], char*, pointer to the input from main.
|
|    @return  none
*-------------------------------------------------------------------*/
void provideDeck (const char *suits[], const char *face[],
                  int play[][MAXIMUM_CARDS_ALLOWED], char* argv[])
{
    int counter = 0;
    int nestedCounter = 0;
    int card = 0;
    int suitNumber = 0;
    int faceNumber = 0;
    int numberOfCardsToDistribute = 0;
    int numberOfPlayersInTheGame = 0;

    printf("%s\n", "Player Hand: (dealt from top/front of deck)");

    numberOfCardsToDistribute = atoi(argv[ARGUMENT_ONE]);
    numberOfPlayersInTheGame = atoi(argv[ARGUMENT_TWO]);

    for (counter = 0; counter < numberOfPlayersInTheGame; counter++)
    {
        printf("%s %d  ", "Player", counter + COUNTER_ONE);
        for (nestedCounter = 0; nestedCounter < numberOfCardsToDistribute;
             nestedCounter++)
        {
            card = play[counter][nestedCounter];
            suitNumber = whatSuit(card);
            faceNumber = whatCard(card);
            printDeckOfCards (faceNumber, suitNumber,suits, face);
        }
        printf("%s\n","");
    }
}


