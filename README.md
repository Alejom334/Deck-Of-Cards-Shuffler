# Deck-Of-Cards-Shuffler
This is a card game that will display an ordered deck, that then will be shuffled and then the cards will be given to the players that intend to play the game. It is important to understand that the game required the user to have an initial input for the number of cards and the number of players.


Display results: Using source files main.c and dealerFunctions.c and header deckCardsFunctions.h and the following functions in these files:
Using validateWholeInput (int argc, char* argv[]), textInputValidation (int argc, char* argv[]), numberInputValidation(char value1[], char value2[]), explainTheLegend (const char *suits[], const char *face[]), populateArray(int deck[]), createOrganizedDeck(int mDeck[], const char *suits[], const char *face[]), whatCard (int cardInTheDeck), whatSuit (int cardInDeck), printDeckOfCards (int faceNumber, int suitNumber, const char *suits[], const char *face[]), shuffle (int deck [], const char *suits[], const char *face[]), swap (int *currentPosition, int *newPosition), createDeckToDeal(int dDeck[], int play[] [MAXIMUM_CARDS_ALLOWED], char* argv[]), void provideDeck (const char *suits[], const char *face[], int play[][MAXIMUM_CARDS_ALLOWED], char* argv[]);
the program will display an ordered deck, that then will be shuffled and then the cards will be given to the players that intend to play the game. It is important to understand that the game required the user to have an initial input for the number of cards and the number of players.
Source File: main.c _____________________________________________________________________________
Main(int argc, char* argv[]) Initialize Card Array deck[];
Initialize the constant char array pointer to the array of faces face[]
Initialize the constant char array pointer to the array of suits suits[]
If validateWholeInput(argc,argv) is validated
call explainTheLegend (suits, face);
call populateArray(deck);
call createOrganizedDeck (deck,suits, face); call shuffle (deck, suits,face);
initialize the two dimensional array
call createDeckToDeal(deck, play, argv); call provideDeck(suits, face, play, argv);
_____________________________________________________________________________
Function – int validateWholeInput (int argc, char* argv[]) – This function is the brain of the operation of validating the input
Call function textInputValidation(argc, argv) and initialize it to checkTextInput
Call function numberInputValidation(argv[ARGUMENT_ONE], argv[ARGUMENT_TWO]) and initialize it to checkNumber
If both of these functions happened to be true then the whole input is validated, otherwise
return false. ______________________________________________________________________________
Function – int textInputValidation (int argc, char* argv[]) returns if the input text is the correct one. Allowing us to know if the user actually input it a number or a string or the amount of numbers written.
initialize counter to 0 initialize counter2 to 0 initialize numDigit to 0 initialize the status to 0
If argc == MAXIMUM_ARGUMENT For loop the whole array
numDigit = strlen(argv[counter]);
if numDigit is less than or equal TWO_DIGIT_MAX
For loop of each character of each input of the array
If each character is a digit then return status as true; Else return status, status = false
If none of the conditions below are met then return status as false Return status
______________________________________________________________________________

Function int numberInputValidation(char value1[], char value2[]) -This function will check if the number is within our desired range.
Initialize numberOfCards to 0;
Initilize numberOfPlayers to 0;
numberOfCards = atoi(parameterOne);
numberOfPlayers = atoi(parameterTwo);
if the numberOfCards and the numberOfPlayers happened to be within our required input then check
if the numberOfCards times the numberOfPlayers is equal or below than TOT AL_NUMBER_OF_CARDS
return TRUE; return FALSE;
else
 
Source File: dealerFunctions.c
Function – void explainTheLegend(const char *suits[], const char *face[]). This function will explain the legend of our cards.
Explain all the legend of the cards using the enums ______________________________________________________________________________ Function – void populateArray(int deck[])- This function will populate the array.
The array deck[] is initialize in the main. Here we are going to populate that array from 1-
      52
______________________________________________________________________________
Function – void createOrganizedDeck(int mDeck[], const char *suits[], const char *face[]) The purpose of this function is to organize and print the deck as the example requires.
initialize counterOfFaces to 0;
initialize counterOfSuits to 0;
initialize indexInPopulatedDeckArray to 0; initialize indexOfConstantArrayOfFaces to 0; initialize cardInDeck to 0;
initialize printCounter to 0;
intialize suitNumber to 0;
for loop that loops until the FACES constant
indexInPopulatedDeckArray equal counterOfFaces + COUNTER_ONE;
for loop that loops until the SUITS constant
cardInDeck assign to mDeck[indexInPopulatedDeckArray]; indexOfConstantArrayOfFaces assign to whatCard(cardInDeck); suitNumber assin to whatSuit (cardInDeck);
Call the PrintDeckFunction
Increase the indexInPopulatedDeckArray by FACES printCounter++;
if printCounter == FACES
print a line
printCounter assign to 0;
______________________________________________________________________________
Function int whatCard (int cardInTheDeck) – returns the card in the constant array in the main according to the number of cards
 
initialize actualIndexInFaceArray to 0;
initialzie indexOfCardArray to 0;
indexOfCardArray equals cardInTheDeck mod FACES;
if indexOfCardArray is equal to 0
actualIndexInFaceArray = FACES - COUNTER_ONE; return actualIndexInFaceArray;
else
actualIndexInFaceArray = indexOfCardArray - COUNTER_ONE; return actualIndexInFaceArray;
______________________________________________________________________________
Function int whatSuit (int cardInDeck) This function will return the index of what suit to pick in the suit array.
initialize suitNumber to 0;
if cardInDeck is less or equal to CARD_BOUND_THIRTEEN suitNumber assing to to HEARTS;
return suitNumber;
else if cardInDeck is greater than CARD_BOUND_THIRTEEN and cardInDeck is lower or equal than CARD_BOUND_TWENTYSIX)
suitNumber assing toDIAMONDS; return suitNumber;
else if cardInDeck is reater than CARD_BOUND_TWENTYSIX and cardInDeck is less or equal than CARD_BOUND_THIRTYNINE
suitNumber assing to CLUBS; return suitNumber;
else
suitNumber assign to SPADES; return suitNumber;
______________________________________________________________________________

Function - void printDeckOfCards (int faceNumber, int suitNumber, const char *suits[], const char *face[]) this function prints the deck of cards.
- Print the deck of Cards as suit[suitNumber] and face[faceNumber]
Function - void shuffle (int deck [], const char *suits[], const char *face[]) - The purpose of this function is to shuffle the deck.
Create the random seed with time with srand(time(NULL)); Create and initialize necessary variables
For loop of the whole deck array to swap cards
randomLocation = COUNTER_ONE + (rand() % CARDS); swap(&deck[counter], &deck[randomLocation]);
puts("\nRandom Shuffled Deck:");
For loop of the new generated array to print it
cardInTheDeck = deck[counter]; indexOfConstantArrayOfFaces = whatCard(cardInTheDeck); indexOfConstantArrayOfSuits = whatSuit(cardInTheDeck); printDeckOfCards(indexOfConstantArrayOfFaces,
indexOfConstantArrayOfSuits, suits, face); printCounter++;
if (printCounter == FACES)
print a blank line printCounter = 0;
print a blank line ______________________________________________________________________________
Function - void swap (int *currentPosition, int *newPosition) - The purpose of this function is swap the pointers
integer temporaryPosition assign to *currentPosition; *currentPosition assign to *newPosition; *newPosition assign to temporaryPosition;
Function - createDeckToDeal(int dDeck[], int play[][MAXIMUM_CARDS_ALLOWED], char* argv[]) - The purpose of this function is to populate the two dimensional array.
  
initialize numberOfCardsToDistribute assign to 0; initialize numberOfPlayersInTheGame assign to 0;
numberOfCardsToDistribute = atoi(argv[ARGUMENT_ONE]); numberOfPlayersInTheGame = atoi(argv[ARGUMENT_TWO]);
initialize counter and assign it to 0; initialize counter2 and assign it to 0; initialize nestedCounter and assign it to 0; initialize card and assign it to 0;
initialize inside counter and assign it to 0;
For loop for the number of players in the array counter2 = 0;
for loop of the number of cards to save
card = dDeck[nestedCounter+COUNTER_ONE];
populate 2 dimensional array with play[counter][counter2] = card; counter2++;
insideCounter = nestedCounter; ______________________________________________________________________________
Function - void provideDeck (const char *suits[], const char *face[], int play[][MAXIMUM_CARDS_ALLOWED], char* argv[]) – This function prints the required two dimensional array
Print - Player Hand: (dealt from top/front of deck)
numberOfCardsToDistribute = atoi(argv[ARGUMENT_ONE]); numberOfPlayersInTheGame = atoi(argv[ARGUMENT_TWO]);
for numberOfPlayersInTheGame print the player number
for number of cards to distribute
card = play[counter][nestedCounter]; suitNumber = whatSuit(card); faceNumber = whatCard(card);
print the actual card
print a blank line
