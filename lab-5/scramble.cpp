// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */
// const char* wordBank[] = {
//    "computer", "president", "trojan", "program", "coffee",
//    "library", "football", "popcorn", "science", "engineer"};

const int numWords = 10;

int main(int argc, char* argv[]) {
  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;

  if(argc < 2)
    {
      //we need at least ./scramble <file name> to continue
      cout << "usage: ./scramble <file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   
   ifstream ifile (argv[1]); 
   if( ifile.fail() ) // able to open file? fail() 
   { 
     cout << "Sorry, couldn't open file." << endl; 
     return -1; 
   }
  
   int numWords = 0;
   ifile >> numWords;
   if (ifile.fail()) 
   { 
     ifile.close();
     cout << "Sorry, there has to be an interger at the top" 
          <<" indicating the number of subsequent words"
          << " in the file."
          << endl;
     return -1;
   }
   
  /* Add code to declare the wordBank array, read in each word
     and store it */
  char** wordBank = new char*[numWords];
  char buffer[41];
  int i = 0;
  while ((ifile >> buffer) && (i < numWords))
  {
    char* wordTemp = new char[strlen(buffer) + 1];//+1 null terminator
    for (int j = 0; j < strlen(buffer); j++)
    {
      wordTemp[j] = buffer[j];
    }
    wordTemp[strlen(buffer)] = '\0';
    wordBank[i] = wordTemp;
    i++;
  }
  ifile.close();
    
  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen + 1]; //+1 null terminator
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    /* Complete the next line of code */
      
    if( strcmp(guess, wordBank[target]) == 0 )
    {
      wordGuessed = true;
    }
    else
    {
      wordGuessed = false;
    }
    // ADD code to check if the guess is equal to the chosen word.
    // wordGuessed should be true if they are equal,
    // and false otherwise
        
    numTurns--;   // Every guess counts as a turn
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  /* Free up any necessary memory */
    
  delete [] word;
  for(int i = 0; i < numWords; i++)
  {
    delete [] wordBank[i];
  }
  delete [] wordBank;
  return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}

