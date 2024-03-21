// Pattern matching implemented in C++

#include <iostream>
#include <string.h>
using namespace std;

int INDEX(const string& text, const string& pattern) {
    int index = -1;

    size_t s = text.length();
    size_t r = pattern.length();

    cout << s << endl;
    cout << r << endl;

    int k = 0, max = s - r;
    while (k <= max) {
        for (int i = 0; i < r; i++) {
            if (pattern[i] != text[k + i]) break;
            if (i == r - 1) {
                index = k;
                break;
            }
        }
        k += 1;
    }
    return index;
}

int main() {
    string txt = "You cannot lie to me!";
    string ptr = "can";
    cout << "Index of '" << txt 
    << "' in '" << ptr << "' is " 
    << INDEX(txt, ptr) << endl;

    return 0;
}