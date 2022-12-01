#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  int input; 
  int countOf2 = 0;
  int countOf3 = 0;
  int a;
  
  cout << "Enter a positive integer:" << endl;
  cin >> input;
  a = input;
  
  while (input > 1 && a % 2 == 0) {
    a = a/2;
    countOf2++;
  }
  
  while (input > 1 && a % 3 == 0) {
    a = a/3;
    countOf3++;
  }
  
  if (a == 1 && input > 1) {
    cout << "Yes" << endl;
    cout << "Twos=" << countOf2 << " Threes=" << countOf3 << endl;
  }
  else { cout << "No" << endl; }
    
  return 0;
}