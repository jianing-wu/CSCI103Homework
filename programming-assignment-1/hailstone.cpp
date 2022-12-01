#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int input;
  cout << "Enter a number: ";
  cin >> input;
  int count = 0;
  
  while (input != 1) {   //loop until the number turns to 0
    if (input % 2 == 0) {
      input /= 2;   //if even, divide by 2
      cout << input << " ";
      count++;
    } else {
      input = input * 3 + 1;   //if odd, multiply by 3 then add 1
      cout << input << " ";
      count++;
    }    
  }
  
  cout << endl;
  cout << "Length: " << count << endl;
  
  return 0;
}
  