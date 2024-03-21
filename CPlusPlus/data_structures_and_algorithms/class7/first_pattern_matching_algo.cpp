// Pattern matching implemented in C++

#include <iostream>
using namespace std;

int INDEX(const char* text, const char* pattern) {
    int INDEX = -1;
    int S = sizeof(text) - 1; // because \0 is also counted
    int R = sizeof(pattern) - 1;

    cout << S << endl;
    cout << R << endl;

    int K = 0, MAX = S - R;
    while (K <= MAX) {
        for (int I = 0; I < R; I++) {
            if (pattern[I] != text[K + I]) break;
            if (I == R - 1) {
                INDEX = K;
                break;
            }
        }
        K += 1;
    }
    return INDEX;
}

int main() {
    char text[] = "You cannot lie to me!";
    char pattern[] =  "can";
    cout << "Index of '" << pattern << "' in '" << text << "' is " << INDEX(text, pattern) << endl;

    return 0;
}