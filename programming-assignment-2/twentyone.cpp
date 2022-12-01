/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Jianing Wu
 * USC email: wujianin@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  for (int i = 0; i < 52; i++) {
    cards[i] = i;
  }
  for (int i = 51; i >= 1; i--) {
    int j = rand() % (i+1);
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  if (id >= 0 && id <= 12) cout << type[id] << "-" << suit[0];
  if (id >= 13 && id <= 25) cout << type[id-13] << "-" << suit[1];
  if (id >= 26 && id <= 38) cout << type[id-26] << "-" << suit[2];
  if (id >= 39 && id <= 51) cout << type[id-39] << "-" << suit[3];
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  if (id >= 0 && id <= 12) return value[id];
  else if (id >= 13 && id <= 25) return value[id-13];
  else if (id >= 26 && id <= 38) return value[id-26];
  else return value[id-39];
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  for (int i = 0; i < numCards; i++) {
    printCard(hand[i]); 
    cout << " ";
  }
  cout << endl;
}

void printDealerHand(int hand[], int numCards) {
  for (int i = 0; i < numCards; i++) {
    if (i == 0) {
      cout << "?";
    } else {
      printCard(hand[i]);
    }
    cout << " ";
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  int score = 0;
  int aceCount = 0;
  for (int i = 0; i < numCards; i++) {
    score += cardValue(hand[i]);
    if (hand[i] == 12 || hand[i] == 25 || hand[i] == 38 || hand[i] == 51) {
      aceCount++;
    }
  }
  
  while (score > 21 && aceCount > 0) {
    score -= 10;
    aceCount --;
  }
  
  return score;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------
  
  bool playAgain = true;
  char input2; //input of whether to play again
  
  while (playAgain == true) {
    shuffle(cards);
    phand[0] = cards[0];
    phand[1] = cards[2];
    dhand[0] = cards[1];
    dhand[1] = cards[3];
    int decki = 4;
    int pi = 2;
    int di = 2;
    
    cout << "Dealer: ";
    printDealerHand(dhand, di);
    cout << "Player: ";
    printHand(phand, pi);
   
    int pScore = getBestScore(phand, pi);
    int dScore = getBestScore(dhand, di);
    char input1; //input of whether hit or stay

    while (pScore < 21) {
      cout << "Type 'h' to hit and 's' to stay:" << endl;
      cin >> input1;
      if (input1 == 'h') {
        phand[pi++] = cards[decki++];
        pScore = getBestScore(phand, pi);
        cout << "Player: ";
        printHand(phand, pi);
      } else if (input1 == 's') {
        break;
      } else {
        return 0;
      }
    }
    
    if (pScore > 21) {
      cout << "Player busts" << endl;
      cout << "Lose " << pScore << " " << dScore << endl;
    } else { 
      while (dScore < 17) {
        dhand[di++] = cards[decki++];
        dScore = getBestScore(dhand, di);
      }
      
      cout << "Dealer: ";
      printHand(dhand, di);
      if (dScore > 21) {
        cout << "Dealer busts" << endl;
        cout << "Win " << pScore << " " << dScore << endl;
      } else {
        if (pScore > dScore) {
          cout << "Win " << pScore << " " << dScore << endl;
        } else if (pScore < dScore) {
          cout << "Lose " << pScore << " " << dScore << endl;
        } else {
          cout << "Tie " << pScore << " " << dScore << endl;
        }
      }
    }
  
    cout << "\nPlay again? [y/n]" << endl;
    cin >> input2;
    if (input2 == 'y') 
      playAgain = true;
    else 
      playAgain = false;
  }
  
  return 0;
}
