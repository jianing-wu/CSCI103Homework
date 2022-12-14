#include "bigint.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
   if (argc != 2) {
      cout << "Usage: bases N\nwhere N is an integer >= 2" << endl;
      return 1;
   }   
   //cout <<argv[1] <<endl;
  
   int N = atoi(argv[1]);


   BigInt first("DADCAFE", 16); // hexadecimal
  //cout << "first:" << first.to_string() << endl; DADCAFE
   BigInt second("AAABEEF", 16);
  //cout << "second:" << second.to_string() << endl; AAABEEF
   first.add(second);
  //cout << "add" << endl;
   cout << first.to_string() << endl; // prints 185889ED
  //cout << "tostring" << endl;
   int testbases[] = {2, 3, 6, 10, 16, 36};

   for (int i=0; i<6; i++) {
      int base = testbases[i];
      BigInt x("1", base);
      BigInt y("1", base);
      for (int j=3; j<=N; j++) {
         BigInt tmp = y;
         y.add(x);
         x = tmp;
      }
      cout << y.to_string() << endl;
   }

   BigInt decimal("1", 10);
   BigInt binary("1", 2);
   cout << "Should cause an error:" << endl;
   decimal.add(binary);
}
