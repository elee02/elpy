// Pattern matching implemented in C++

#include <iostream>
#include <cstring>
using namespace std;

// The first pattern matching algorithm's implementation
// Since I am using char arrays instead of string
// object, the INDEX() function takes additional
// "txt_s" - text size, and "ptrn_s" - pattern size arguments
int INDEX(char* text, int txt_s, char* pattern, int ptr_s) {
    int index = -1;

    int k = 0, max = txt_s - ptr_s;
    while (k <= max) {
        for (int i = 0; i < ptr_s; i++) {
            if (pattern[i] != text[k + i]) break;
            if (i == ptr_s - 1) {
                index = k;
                break;
            }
        }
        k += 1;
    }
    return index;
}
// Structre is defined as a means of
// receiving data from readStr() function
// as it should return two types of data 
// types at once
typedef struct {
    char* text;
    size_t size;
} INFO;

// this function dynamically handles string input
// of any size through char arrays
INFO readinStr(char* txt) {
    INFO cred;
    txt = new char[10];
    int currentSize = 10;
    size_t cnt = 0;

    while (cin.get(txt[cnt])) {
        if (txt[cnt] == '\0') break;
        else if (txt[cnt] == '\n') {
            txt[cnt] = 0;
            break;
        }

        cnt++;
        if (cnt == currentSize - 1) {
            currentSize *= 1.5;
            char* temp = new char[currentSize];
            strncpy(temp, txt, currentSize);
            delete txt;
            txt = temp;
        }
    }
    cred.text = txt;
    cred.size = cnt;

    return cred;
}

int main() {

    while(true) {
    int yesno;
    cout << "Exit?" << endl;
    cin >> yesno;
    if (yesno == 1) break;
    cin.ignore();

    char *txt = nullptr, *ptrn = nullptr;
    cout << "Enter the text: " << endl;
    INFO info_txt = readinStr(txt); cout << endl;

    cout << "Enter the pattern : " << endl;
    INFO info_ptrn = readinStr(ptrn);

    cout << "Index of '" << info_ptrn.text 
    << "' in '" << info_txt.text << "' is " 
    << INDEX(info_txt.text, info_txt.size,  info_ptrn.text, info_ptrn.size) << endl;
    }

    return 0;
}