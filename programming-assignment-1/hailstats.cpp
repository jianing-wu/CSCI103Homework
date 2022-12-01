#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int x, y;
  int min = INT_MAX;  //initialize with max range
  int max = -1;       //can't be negative so count 0 > max
  int minNum = 0;
  int maxNum = 0;
  
  cout << "Enter the range that you want to search: ";
  cin >> x >> y;
  
  if ( x > y ) { 
    cout << "Invalid range" << endl; 
    return 0;
  }  //invalid range case
  
  for (int i = x; i <= y; i++) {  //for each number within the range
    int count = 0;
    int a = i;   //give a the i value so that i doesn't change
    while (a != 1) {
      if (a % 2 == 0) {
        a /= 2;
        count++;
      } else {
        a = a * 3 + 1;
        count++;
      }
    }  //use a to do the calculations
    if (count < min) {
        min = count;
        minNum = i;  //get the min length and its original num
    }
    if (count > max) { 
        max = count;
        maxNum = i;  //get the max length and its original num
    }
  } 
  
  cout << "Minimum length: " << min << endl;
  cout << "Achieved by: " << minNum << endl;
  cout << "Maximum length: " << max << endl;
  cout << "Achieved by: " << maxNum << endl;
  
  return 0;
}
  