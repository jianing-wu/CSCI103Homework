/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Jianing Wu
 * USC email: wujianin@usc.edu
 * Comments (you want us to know): :) 
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
  int input;
  cin >> input;
  while (input != 0) {  //cin each input until 0
    int sumOfDivisors = 0;
    for (int i = 1; i < input; i++) { 
      if (input % i == 0) { sumOfDivisors += i;}
    }  //sum all divisors-->remainder==0 
    if (sumOfDivisors > input) {
      num_abundant++;  //count abundant numbers 
      if (sumOfDivisors > a1) {
        a3 = a2;
        a2 = a1;       
        a1 = sumOfDivisors;  
        n3 = n2;
        n2 = n1;
        n1 = input;
      }
      else if (sumOfDivisors > a2) {
        a3 = a2;
        a2 = sumOfDivisors;
        n3 = n2;
        n2 = input;
      }
      else if (sumOfDivisors > a3) {
        a3 = sumOfDivisors;
        n3 = input;
      }
    }  //rank
    cin >> input;  //next input
  }

      
  /* End of your code */

  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
