#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int roll();
void printHistogram(int counts[]);

int main() {
  int n;
  int sum;
  int counts[21] = {0}; // 21 options of sum of 4 dice => [4,24]
  srand(time(0));
  
  cout << "How many times do you want to roll the dice? ";
  cin >> n;
  while (n > 0) {
    sum = roll()+roll()+roll()+roll(); 
    counts[sum - 4]++; // fill the array
    n--;
  }
  printHistogram(counts); // call your method
  return 0;
}

int roll(){
  int randInt = rand() % 6 + 1;
  return randInt;
}

void printHistogram(int counts[]){
  for (int i = 0; i < 21 ; i++) {
    cout << i + 4 << ':';
    for (int j = 0; j < counts[i]; j++){
      cout << 'X';
    }
    cout << endl;
  }    
}