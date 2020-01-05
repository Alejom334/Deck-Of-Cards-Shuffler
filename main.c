/*=============================================================================$
|   Source code: main.c
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #3 Dealer Card
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [10/15/2019], at the beginning of class
|
|    I hereby certify that this collective work is my own
|   and none of it is the work of any other person or entity.
|   ______________________________________ [Alejandro Martinez]
|
|  Language:  [C]
|  Compile/Run:
|
|   REGULAR COMPILATION (NO MAKE-FILE):
|
|   Please recall that we have header file named deckCardsFunctions.h
|   that must be in the same directory/folder as the files main.c and
|   dealerFunctions.c. After having all files in the folder the program
|   should compile with the following line of code
|   "-std=c99" is used to prevent any errors for compilers that do not
|   compile ASCII unicode characters.
|   Both files must be compiled together.
|
|   gcc -std=c99 GameOfCards2.c deckCardsFunctions.h -o Game2.out
|
|   MAKEFILE COMPILATION:
|
|   If one wants to compile the file using the Makefile called CardDeckMakeFile,
|   make sure that the file CardDeckMakeFile is in the same directory of
|   the other source files main.c and dealerFunctions.c and header file
|   deckCardsFunctions.h then compile the make file using the following command:
|
|   make -f CardDeckMakeFile compile
|  +-------------------------------------------------------------------------
|
|  Description: This simulates how a deck of cards is dealt in a game. At the
|               of compiling the user is required to input a number of cards
|               each player is suppose to have, and the number of players the
|               game will have. Here the whole input will be checked. The user
|               is suppose to input numbers from [1-13] for both the number of
|               cards and the number of players. However, the maximum number
|               of cards that can be dealt is 52.
|
|               After the input is validated, the program will generate a deck
|               of cards. This deck of cards is generated from the
|               LOWER_BOUND_OF_GENERATED_ARRAY (1) to
|               HIGHER_BOUND_OF_GENERATED_ARRAY (52). The reason why this
|               deck array did not started at 0 was to facilitate further
|               computations.
|
|               After the array is generated, the following internal
|               manipulation
|               was done in order to print the card number with the required
|               order from the assignment. From the Ace to the King with their
|               respective Suits.
|
|               The program took the first 13 elements of the array and assign
|               them to be of the suit of hearts, the next 13 of the suit of
|               diamonds, the next 13 of suit of clubs and the next 13 of the
|               suit of spades. Then the face of the letter was found using
|               mod manipulation to match exactly the constant array of chars
|               defined in the main.
|
|               The shuffle of the array was used according the following link
|               that expresses how to use the random function to generate a
|               random variable.
|
|               For more on shuffling, see Knuth (or Fisher-Yates) Shuffle:
|
|https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|               The basic idea behind this way shuffling is to generated a
|               a random location for the array to swap the card. In order
|               to be really random the seed in the random function happens to
|               to be the time. Then a really random deck is generated and then
|               printed. After printing the new shuffle array, cards can now be
|               dealt to everyone in the table.
|
|
|               It is important to mention that this program has four files in the
|               directory.
|               #1. main.c is the file where main is and also has user validation
|                   functions
|               #2. dealerFunctions.c have the functions for dealing the cards
|
|        Input:  Program will receive input from the command line. The command
|                line will only receive integers from [LOWER_BOUND -
|                UPPER_BOUND] or [1-13]. Anything that is not an integer or a
|                number within these boundaries will not be validated.
|
|
|	    Output:  The output wil be organized in 3 sections. The first section
|                will be the building of the ordered deck as required by
|                the assignment. The second section of the output will
|                consist in the shuffle cards. The procedure done to shuffle
|                the cards was done using te link reference below:
| https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|                 The last section of the output happens to be the hands that
|                 will be played according to the number of cards and number
|                 of players the user decided to put at  the beginning, at the
|                 file execution. These hands will be displayed in a two
|                 dimensional array. Initial column being the number of players
|                 and following columns being the hands given to every player.
|
|     Process:   The program's steps are as follows:
|
|                1. The user in executing should put in the command line the
|                   number of cards and the number of players.
|                2. There would be a user validation in this step. User can                     only put two numbers within
|                    the range of [LOWER_BOUND-UPPER_BOUND]
|                   or [1-13]. Any other input that does not happened to be
|                   within these boundaries or is not an integer will not work
|                   and the program will terminate.
|                3. If the input is valid, the ordered deck is generated.
|                4. Then the deck is shuffle and printed.
|                5. Then the cards are given to the players according to the
|                   input that was given at the beginning.
|
|.  Source of Formulas Required For Calculations:
|                Refer to the link below for full explanation on how to
|                  shuffle a deck of cards
| https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
|
|   Required Features Not Included:
|                Not included: All required features are included.
|
|   Known Bugs:  Not know Bugs in this program
|
|  *=====================================================================
|  */

#include <stdio.h>
#include <stdlib.h> //used for atoi in numberInputValidation
#include <string.h> //used for strlen function in textInputValidation
#include <ctype.h> //Used for isDigit
#include "deckCardsFunctions.h" // Deck Card Functions

#define ERROR 0 //Error or Exit Number
#define TWO_DIGIT_MAX 2 //Max two digit parameter
#define MAXIMUM_ARGUMENT 3 //Max amount of arguments
#define CARD_BOUND_ONE 1 //Bound one for full array of cards
#define CARD_BOUND_THIRTEEN 13 //Bound thirteen for full array of cards
#define TOTAL_NUMBER_OF_CARDS 52 //Maximum number of cards

/*----------------Function prototypes-------------------------- **/

int validateWholeInput (int argc, char* argv[]);
int textInputValidation (int argc, char* argv[]);
int numberInputValidation(char value1[], char value2[]);

int main(int argc, char* argv[])
{
    int deck[CARDS] = {0};
    const char *suits[SUITS] = {"\u2665", "\u20DF", "\u2663", "\u2660"};
    const char *face[FACES] = {"A", "2", "3", "4", "5", "6", "7", "8",
                               "9", "T", "J", "Q","K"};
    if(validateWholeInput(argc,argv)==TRUE)
    {
        explainTheLegend (suits, face);
        populateArray(deck);
        createOrganizedDeck(deck,suits, face);
        shuffle (deck, suits,face);
        int play[MAXIMUM_PLAYERS_ALLOWED][MAXIMUM_CARDS_ALLOWED] = {0};
        createDeckToDeal(deck, play, argv);
        provideDeck(suits, face, play, argv);
    }
    else
    {
        return ERROR;
    }
}

/*------ validateWholeInput (int argc, char* argv[]) ----------------
|   Function int validateWholeInput (int argc, char* argv[])
|
|   Purpose:  This function will be the brain in the userValidation.
|
|   Explanation: Two functions textInputValidation and
|                numberInputValidation will be used to validate input.
|
|    @param  argc, int, total amount of input from the command line
|            argv[], char*, pointer to array of command line
|
|    @return  int, TRUE or FALSE, returns true or false depending if
|               the status happened to be true or false.
*-------------------------------------------------------------------*/

int validateWholeInput (int argc, char* argv[])
{
    int checkTextInput = textInputValidation(argc, argv);
    int checkNumberInput = numberInputValidation(argv[ARGUMENT_ONE],
            argv[ARGUMENT_TWO]);

    if (checkTextInput == TRUE && checkNumberInput == TRUE)
    {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*------textInputValidation (int argc, char* argv[]) ----------------
|   Function int textInputValidation (int argc, char* argv[])
|
|   Purpose:  This function will check if the user input 3 parameters,
|               if he did then it will check if each parameter is a
|               a digit that has less than two digits. If this is
|               the case then status is return as true.
|
|   Explanation:
|             1. First we check that the number of inputs from
|                the command line are less than MAXIMUM_ARGUMENT (3)
|             2. Second function strlen is used to find the length of
|                the string.
|             3. If the length is less than two digits then we check
|                if each of the characters of that string is a digit
|                with isDigit
|             4. If any of these conditions happened to be false, the
|                return value is false. Otherwise is true.
|
|    @param  argc, int, total amount of input from the command line
|            argv[], char*, pointer to array of command line
|
|    @return  int, status, returns true or false depending if
|               the status happened to be true or false.
*-------------------------------------------------------------------*/
int textInputValidation (int argc, char* argv[])
{
    int counter = 0;
    int counter2 = 0;
    int numDigit = 0;
    int status = 0;
    if (argc == MAXIMUM_ARGUMENT)
    {
        for (counter = COUNTER_ONE; counter < argc; counter++)
        {
            numDigit = strlen(argv[counter]);

            if (numDigit <= TWO_DIGIT_MAX)
            {
                for (counter2 = 0; argv[counter][counter2] != '\0';
                                                        counter2++)
                {
                    if (isdigit(argv[counter][counter2]))
                    {
                        status = TRUE;
                    }
                    else
                    {
                        status = FALSE;
                        return status;
                    }
                }
            }
            else
            {
                status = FALSE;
                return status;
            }
        }
    }
    else
    {
        status = FALSE;
        return status;
    }
    return status;
}

/*------ numberInputValidation(char value1[], char value2[]) --------
|   Function int numberInputValidation(char value1[], char value2[])
|
|   Purpose:  This function will check if the number is within our
|               desired range
|
|  Explanation: If the number of cards or players happens to be
|               between CARD_BOUND_ONE(1) and CARD_BOUND_THIRTEEN(13)
|               and the multiplication between both numbers is less
|               or equal to TOTAL_NUMBER_OF_CARDS (52) then input
|               is totally validated
|
|    @param  char, parameterOne, first parameter of the input
|            char, parameterTwo, second parameter of the input
|
|    @return  int, TRUE or FALSE, returns true or false depending if
|               the status happened to be true or false.
*-------------------------------------------------------------------*/

int numberInputValidation(char parameterOne[], char parameterTwo[])
{
    int numberOfCards = 0;

    int numberOfPlayers = 0;

    numberOfCards = atoi(parameterOne);

    numberOfPlayers = atoi(parameterTwo);

    if ((numberOfCards >= CARD_BOUND_ONE &&
            numberOfCards <= CARD_BOUND_THIRTEEN) &&
            (numberOfPlayers >= CARD_BOUND_ONE &&
                numberOfPlayers <= CARD_BOUND_THIRTEEN))
    {
        if ((numberOfCards)*(numberOfPlayers)
                                <= TOTAL_NUMBER_OF_CARDS)
        {
            return TRUE;
        }
    }
    return FALSE;
}
