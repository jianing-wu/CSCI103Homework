#include "bigint.h"
#include <iostream>
using namespace std;

BigInt::BigInt(string s) {
  base = 10;
  for (int i = s.size() - 1; i >= 0; i--) {
     intReversed.push_back((int)s[i] - 48);
  }
}

BigInt::BigInt(string s, int base_) {
  base = base_;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] >= '0' && s[i] <= '9') {
     intReversed.push_back((int)s[i] - 48);
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      intReversed.push_back((int)s[i] - 'A' + 10);
    } else {
      throw "Invalid integer.";
    }
//     cout << intReversed[intReversed.size() -1] << endl;
  }
}

string BigInt::to_string() {
  int size = intReversed.size();
  string s = "";
  for (int i = 0; i < size; i++) {
//     s += intToChar[intReversed[size-i-1]];
    int x = intReversed[size-i-1];
    if (x >= 0 && x <= 9) {
      s += (char)(intReversed[size-i-1] + '0');
    } else {
      s += (char)(x + 'A' - 10);
    }
  }
  return s;
}

void BigInt::add(BigInt b) {
	//cout << base << endl;
	//cout << b.base << endl;
  if (base != b.base) {
		cout << "Cannot add integers with different bases!" << endl;
  }
  
  int biggerSize = intReversed.size();
  if (intReversed.size() > b.intReversed.size()) {
    for (int i = 0; i < (intReversed.size()-b.intReversed.size()); i++) {
      (b.intReversed).push_back(0);
    }
  } else if (intReversed.size() < b.intReversed.size()) {
    biggerSize = b.intReversed.size();
    for (int i = 0; i < (b.intReversed.size()-intReversed.size()); i++) {
      intReversed.push_back(0);
    }
  }
  int carry = 0;
  for (int i = 0; i < biggerSize; i++) {
    intReversed[i] += carry + b.intReversed[i];
    carry = intReversed[i] / base;
    intReversed[i] %= base;
  }
  
  if (carry > 0) {
    intReversed.push_back(carry);
  }
}

