/********************************************************
 * CS 103 PA 1: Commas
 * Name: Jianing Wu
 * USC email: wujianin@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long n;
  cout << "Enter an integer:" << endl;

  /* Your code here */
  cin >> n;
  
  if (n < 0) {
    cout << "-";
    n = -1 * n;
  }  //if <0 first print out the negative sign
  else if (n == 0) {
    cout << n;
  }  //if 0 just cout 0
  
  long long quotient = n;
  int digits = 0;
  
  while (quotient > 0) {
    quotient = quotient / 10;
    digits ++;
  }  //count total digits
  
  for (int i = digits; i > 0; i--) {
    if (i < digits && i % 3 == 0) {
      cout << ",";
    }  //avoid printing a comma before the first digit
    cout << (n / (long long)pow(10, i - 1)) % 10; 
  }
  cout << endl;
  
  /* End of your code */
  return 0;

}
