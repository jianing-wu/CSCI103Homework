#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	    cout << "Usage: ./decipher <file>"<<endl;
	    cout << "Examples:" << endl;
	    cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	    cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/
    ifstream inFile(argv[1]);
    if (inFile.is_open()) {
        int base = 0;
        string d;
        string n;
        string secretStr;
        if (inFile >> base >> d >> n) {
            try {
                BigInt dInt(d, base); 
                BigInt nInt(n, base);
                while(inFile >> secretStr ) {
                    BigInt secretInt(secretStr, base);
                    BigInt mod = modPow(secretInt, dInt, nInt);
                    cout << (char)(mod.to_int());
                }
                cout << endl;
            } catch(const exception& e) {
                cout << e.what() << endl;
                return -1;
            }
        }
    }
	return 0;
}
