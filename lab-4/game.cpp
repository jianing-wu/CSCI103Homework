// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  
  for (int i = 0; i < strlen(targetWord); i++) {
    word[i] = '*';
  }
  if (strlen(targetWord) < 80) {
    word[strlen(targetWord)] = '\0';
  }
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  
  char inputChar;
  
  while (numTurns != 0) {
    cout << "Current word: ";
    for (int i = 0; i < strlen(targetWord); i++) {
      cout << word[i];
    }
    cout << endl;
    cout << numTurns << " remain...Enter a letter to guess:" << endl;
    cin >> inputChar;
    
    if (processGuess(word, targetWord, inputChar) <= 0) {
      numTurns--;
    }
    
    if (strcmp(word, targetWord) == 0) {
      wordGuessed = true;
      break;
    }
    cout << endl;
  }
  
  // Print out end of game status
  if (wordGuessed) {
    cout << "The word was: " << word << ". You win!" << endl;
  } else {
    cout << "Too many turns...You lose!" << endl;
  }
  
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int count = 0;
  for (int i = 0; i < strlen(targetWord); i++) {
    if (targetWord[i] == guess) {
      word[i] = guess;
      count++;
    }
  }
  return count;
}