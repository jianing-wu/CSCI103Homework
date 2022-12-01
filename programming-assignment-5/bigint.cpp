#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <sstream>
using namespace std;

/*
//   Create a default BigInt with base 10.
*/
BigInt::BigInt(){
    base = 10;
    isPositive = true;
}

/*
//  Create a BigInt with a specified base.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    isPositive = true;
}

/*
//  Create a BigInt from int (base 10) with a specified base.
//  Here you would convert an int (base 10) into a specified base.
//  e.g., (10,2) <-- 10 base 10 to base 2 --> result:  BigInt with value 1010 base 2
//  e.g., (100,16) <--- 100 base 10 to base 16 --> result: BigInt with value 64 base 16
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    if (input == 0) {
        vec.push_back(0);
        isPositive = true;
    } else if (input < 0) {
        isPositive = false;
        input *= -1;
    } else {
        isPositive = true;
    }
    
    while (input > 0) {
        int digit = input % base;
        vec.push_back(digit);
        input /= base;
    }
}

/*
//  Create a BigInt from string with a specified base.
//  You can assume that the string number input is in the same
//      base as the setbase input.
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    int front = 0;
    if (s[0] == '-') {
        isPositive = false;
        front = 1;
    } else {
        isPositive = true;
    }
    
    for (int i = s.size() - 1; i >= front; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            vec.push_back((int)s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            vec.push_back((int)s[i] - 'A' + 10);
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            vec.push_back((int)s[i] - 'a' + 10);
        } else {
            throw InvalidIntegerException();
        }
    }
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply use the assignment operator.
*/
BigInt::BigInt(const BigInt &b){
    base = b.base;
    isPositive = b.isPositive;
    for (unsigned int i = 0; i < b.vec.size(); i++) {
        vec.push_back(b.vec[i]);
    }
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}



/*
// Convert to string and return the string
//  Display it in its corresponding base
*/
string BigInt::to_string(){
  stringstream sstream;
    if (vec.size() > 0 && !isPositive) {
        sstream << '-';
    }
  for (int i = vec.size() - 1; i >= 0; i--) {
      if (vec[i] >= 0 && vec[i] <=9) {
          sstream << (char)(vec[i] + '0');
      } else {
          sstream << (char)(vec[i] - 10 + 'A');
      }
  }
  return sstream.str();
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt > INT_MAX, return INT_MAX.
//    If BigInt < INT_MIN, return INT_MIN.
*/
int BigInt::to_int() const{
    long long sum = 0;
    long long multiplier = 1;
    for (unsigned int i = 0; i < vec.size(); i++) {
        sum += vec[i] * multiplier;
        multiplier *= base;
        if (isPositive && sum > INT_MAX) {
            return INT_MAX;
        }
        if (!isPositive && sum > (long long)INT_MAX + 1) {
            return INT_MIN;
        }
    }
    if (!isPositive) {
        sum *= -1;
    }
    int result = sum;
    return result;
}

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    
    if (isPositive != b.isPositive) {
        return isPositive ? 1 : -1;
    } else if (vec.size() < b.vec.size()) {
        return isPositive ? -1 : 1;
    } else if (vec.size() > b.vec.size()) {
        return isPositive ? 1 : -1;
    }
    
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] > b.vec[i]) {
            return isPositive ? 1 : -1;
        } else if (vec[i] < b.vec[i]) {
            return isPositive ? -1 : 1;
        }
    }
    
    return 0;
}



/*
//  Assignment operator. (i.e., BigInt a = b;)
*/
const BigInt & BigInt::operator = (const BigInt &b){
    this->base = b.base;
    this->isPositive = b.isPositive;
    vec.clear();
    for (unsigned int i = 0; i < b.vec.size(); i++) {
        this->vec.push_back(b.vec[i]);
    }
    return *this;
}


void addVec(vector<int>& a, const vector<int>& b, const int base) {
    unsigned int i = 0;
    unsigned int greatLen = a.size() < b.size() ? b.size() : a.size();
    int carry = 0;
    int digit = 0;
    int cur = 0;
    
    int aCur = 0;
    int bCur = 0;
    
    while (i < greatLen) {
        aCur = (i >= a.size()) ? 0 : a[i];
        bCur = (i >= b.size()) ? 0 : b[i];
        cur = carry + aCur + bCur;
        digit = cur % base;
        carry = cur / base;
        if (i < a.size()) {
            a[i] = digit;
        } else {
            a.push_back(digit);
        }
        i++;
    }
    
    if (carry > 0) {
        a.push_back(carry);
    }
}

void subtractVec(vector<int>& greater, const vector<int>& smaller, const int base) {
    int i = 0;
    int greatLen = greater.size();
    int smallLen = smaller.size();
    int borrow = 0;
    int digit = 0;
    int cur = 0;
    int smallDigit = 0;
    
    while (i < greatLen) {
        smallDigit = i >= smallLen ? 0 : smaller[i];
        cur = borrow + greater[i] - smallDigit;
        digit = cur < 0 ? cur + base : cur;
        borrow = cur < 0 ? -1 : 0;
        greater[i] = digit;
        i++;
    }
    
    while (greater.size() > 0 
           && greater[greater.size() - 1] == 0) {
        greater.pop_back();
    }
}

int compareVec(const vector<int>& a, 
                        const vector<int>& b) {
    if (a.size() < b.size()) {
        return -1;
    } else if (a.size() > b.size()) {
        return 1;
    }
    
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] > b[i]) {
            return 1;
        } else if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

/*
//  Addition assignment operator.
//    - Compute a = a + b.
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    
    if (isPositive == b.isPositive) {
        addVec(this->vec, b.vec, base);
    } else {
        int compareAbs = compareVec(this->vec, b.vec);
        if (compareAbs == 0) {
            this->vec.clear();
            this->vec.push_back(0);
            this->isPositive = true;
        } else if (compareAbs > 0) {
            subtractVec(this->vec, b.vec, base);
        } else {
            BigInt bCopy(b);
            subtractVec(bCopy.vec, this->vec, base);
            *this = bCopy;
            this->isPositive = b.isPositive;
        }
    }
    
    return *this;
}



/*
//  Subtraction assignment operator.
//    - Compute a = a - b
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
     
    if (isPositive != b.isPositive) {
        addVec(this->vec, b.vec, base);
    } else {
        int compareAbs = compareVec(this->vec, b.vec);
        if (compareAbs == 0) {
            this->vec.clear();
            this->vec.push_back(0);
            this->isPositive = true;
        } else if (compareAbs > 0) {
            subtractVec(this->vec, b.vec, base);
        } else {
            BigInt bCopy(b);
            subtractVec(bCopy.vec, this->vec, base);
            *this = bCopy;
            this->isPositive = !this->isPositive;
        }
    }
    return *this;
}

/*
//  Multiplication assignment operator.
//    - Compute a = a * b;
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if (this->vec.size() == 1 && this->vec[0] == 0) {
        return *this;
    }else if (b.vec.size() == 1 && b.vec[0] == 0) {
        this->vec.clear();
        this->vec.push_back(0);
        this->isPositive = true;
        return *this;
    }
    
    BigInt a(*this);
    this->vec.clear();
    for (unsigned int i = 0; i < a.vec.size(); i++) {
        vector<int> row;
        int carryMult = 0;
        int cur = 0;
        int digit = 0;
        for (unsigned int j = 0; j < b.vec.size(); j++) {
            cur = a.vec[i] * b.vec[j] + carryMult;
            digit = cur % base;
            carryMult = cur / base;
            row.push_back(digit);
        }
        if (carryMult > 0) {
            row.push_back(carryMult);
        }
        // add to this;
        unsigned int k = 0;
        int carryAdd = 0;
        int sum = 0;
        int cDigit = 0;
        int curCDigit = 0;
        while (k < row.size()) {
            cDigit = ((k + i) < this->vec.size()) ? this->vec[k + i] : 0; 
            sum = cDigit + row[k] + carryAdd;
            curCDigit = sum % base;
            carryAdd = sum / base;
            if (k + i < this->vec.size()) {
                this->vec[k + i] = curCDigit;
            } else {
                this->vec.push_back(curCDigit);
            }
            k++;
        }
        if (carryAdd > 0) {
            this->vec.push_back(carryAdd);
        }
    }
    this->isPositive = this->isPositive == b.isPositive;
    return *this;
}

/*
//  Division assignment operator.
//    - Call 'divisionMain' to compute a = a / b;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    BigInt quotient(this->base);
    BigInt remainder(this->base);
    
    this->divisionMain(b, quotient, remainder);
    *this = quotient;
    return *this;
}

/*
//  Modulus assignment operator.
//    - Call 'divisionMain' to compute a = a % b.
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    
    BigInt quotient(this->base);
    BigInt remainder(this->base);
    
    this->divisionMain(b, quotient, remainder);
    *this = remainder;
    return *this;
}

/*
//  Main function for the Division and Modulus operator.
//     - Compute (q)uotient and (r)emainder: a = (b * q) + r.
//     - Note: NO fraction. This should behave like integer division
//             where 2/10 = 0, not 0.2
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){
    int i = this->vec.size() - 1;
    int subtractCount = 0;
    while (i >= -1) {
        int compare = compareVec(remainder.vec, b.vec);
        if (compare < 0) {
            if(subtractCount > 0 || quotient.vec.size() > 0) {
                quotient.vec.insert(quotient.vec.begin(), subtractCount);
            }
            subtractCount = 0;
            if (i >= 0) {
                if (remainder.vec.size() == 1 && remainder.vec[0] == 0) {
                    remainder.vec.pop_back();
                }
                remainder.vec.insert(remainder.vec.begin(), this->vec[i]);
            }
            i--;
        } else if (compare == 0){
            remainder.vec.clear();
            remainder.vec.insert(remainder.vec.begin(), 0);
            subtractCount++;
        } else {
            subtractVec(remainder.vec, b.vec, this->base);
            subtractCount++;
        }
    }
    
    if (quotient.vec.size() == 0) {
        quotient.isPositive = true;
        quotient.vec.push_back(0);
    } else if(quotient.vec.size() == 1 && quotient.vec[0] == 0) {
        quotient.isPositive = true;
    } else {
        quotient.isPositive = this->isPositive == b.isPositive;
    }
    
    if (remainder.vec.size() == 1 && remainder.vec[0] == 0) {
        remainder.isPositive = true;
    } else {
        remainder.isPositive = this->isPositive;
    }
}

bool isOdd(vector<int>& v) {
    return v[0] % 2 == 1;
}

/*
//  Exponentiation assignment function.
//     - Compute a BigInt whose value is a = pow(a,b).
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    if (b.vec.size() == 1 && b.vec[0] == 0) {
        *this = BigInt(1, this->base);
        return *this;
    }
    BigInt p(b);
    BigInt singles(1, this->base);
    BigInt one(1, this->base);
    BigInt two(2, this->base);
    while (p > one) {
        if (isOdd(p.vec)) {
            singles *= *this;
            *this = *this * *this;
            p -= one;
            p /= two;
        } else {
            *this = *this * *this;
            p /= two;
        }
    }
    *this *= singles;
    return *this;
}

/*
//  Modulus Exponentiation assignment function.
//     - Compute a = (a ^ b) % m.
//     - Do NOT compute a^b directly and then % m. 
//         This is too computationally expensive.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    if (b.vec.size() == 1 && b.vec[0] == 0) {
        *this = BigInt(1, this->base);
        return *this;
    }
    *this = *this % m;
    BigInt p(b);
    BigInt singles(1, this->base);
    BigInt one(1, this->base);
    BigInt two(2, this->base);
    while (p > one) {
        if (isOdd(p.vec)) {
            singles = (*this * singles) % m;
            p -= one;
        } else {
            *this = (*this * *this) % m;
            p /= two;
        }
    }
    *this = (*this * singles) % m;
    return *this;
}


//----------------------------------------------------
//* Operator overloading, non-member functions
//----------------------------------------------------


//Call the += function above to compute a BigInt whose value is a + b
BigInt operator + (const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c += b;
    return c;
}
//Call the -= function above to compute a BigInt whose value is a - b
BigInt operator - (const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c -= b;
    return c;
}
//Call the *= function above to compute a BigInt whose value is a * b
BigInt operator * (const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c *= b;
    return c;//for now
}

//Call the /= function above to compute a BigInt whose value is a / b
BigInt operator / (const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c /= b;
    return c;
}

//Call the %= function above to compute a BigInt whose value is a % b
BigInt operator % (const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c %= b;
    return c;
}
//Call the exponentiation function above to compute a BigInt whose value is pow(a,b)
BigInt pow(const  BigInt &a, const BigInt & b){
    BigInt c(a);
    c.exponentiation(b);
    return c;
}

//Call the modulusExp function above to compute a BigInt whose value is (a ^ b) mod c
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    BigInt c(a);
    c.modulusExp(b, m);
    return c;
}

//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){ 
    return a.compare(b) == 0;
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
    return a.compare(b) != 0;
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
    int compare = a.compare(b);
    return compare <= 0;
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
    int compare = a.compare(b);
    return compare >= 0;
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
    return a.compare(b) > 0;
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  return a.compare(b) < 0;
}