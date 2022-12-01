#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
  int input, oppositeSide;
  double radian;
  cout << "Please enter a value of Θ." << endl;
  cin >> input;
  radian = input * M_PI / 180;
  
  
  for (int i = 0; i < 31; i++) {
    oppositeSide = floor((i + 1) * tan(radian));
    if (oppositeSide >= 20 && oppositeSide <= 30) {
      oppositeSide = 20;
    }
    for (int j = 0; j < oppositeSide; j++) {
      cout << '*' ;
    }
    cout << endl;
  }
       
    return 0;
}
