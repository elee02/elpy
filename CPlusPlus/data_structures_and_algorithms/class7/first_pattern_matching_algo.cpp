// Pattern matching implemented in C++

#include <iostream>
using namespace std;

int INDEX(const char*& text, const char*& pattern) {
    int INDEX = -1;
    int S = sizeof(text);
    int R = sizeof(pattern);

    int K = 0, MAX = S + R - 1;
    while (K <= MAX) {
        for (int I = 0; I < R; I++) {
            if pattern[I] != text[K + I - 1];
            continue;
            INDEX = K;
        }
        K = K + 1;
    }
    return INDEX;
}

int main() {
    char text[] = "You cannot lie to me!";
    char pattern[] =  "can";
    cout << "The index of patern "<< pattern << " in the text "<< text << " is " << INDEX(text, pattern) << endl;

    return 0;
}