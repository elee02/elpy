#include <string>
#include <iostream>

using namespace std;

extern "C" {
    void minion_game(char* s, int len) {
        string str(s, len);
        string consonant = "bcdfghjklmnpqrstvwxyz";
        string vowel = "aeiou";
        long long numStuart = 0;
        long long numKevin = 0;
        for (int i = 0; i < len; i++) {
            if (consonant.find(str[i]) != string::npos) {
                numStuart += len - i;
            }
            if (vowel.find(str[i]) != string::npos) {
                numKevin += len - i;
            }
        }
        if (numStuart > numKevin) {
            cout << "Stuart " << numStuart << endl;
        }
        else if (numKevin > numStuart) {
            cout << "Kevin " << numKevin << endl;
        }
        else {
            cout << "Draw" << endl;
        }
    }
}