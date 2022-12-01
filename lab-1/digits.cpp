#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
  int input; 
  cout << "Enter an integer between 0 and 999:";
  cin >> input;
  int a, b, c;
  a = input % 10;
  b = (input / 10) % 10;
  c = (input / 100) % 10;
  
  cout << endl;
  cout << "1's digit is " << a << endl;
  cout << "10's digit is " << b << endl;
  cout << "100's digit is: " << c << endl;
  
  return 0;
}
