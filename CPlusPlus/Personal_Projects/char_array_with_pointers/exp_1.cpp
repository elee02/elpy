#include <iostream>
#include <iomanip>
using namespace std;

void randomFill(char[][50], char**);
void printChar(char[][50]);
void printChar(char**);
bool sameName(char[], char[]);
void nameTest(char[][50], char**);

int main() {
    // 2D array
    char names[20][50];
    
    // list of pointers to char arrays
    char* _names_[20];

    for (int i = 0; i < 20; i++) {
        _names_[i] = new char[50];
    }
    randomFill(names, _names_);
    
    string title_1 = "2D Array";
    int line_width = 80;
    int padding = (line_width - title_1.size()) / 2;

    cout << endl;
    cout << setfill('=') << setw(padding) << "" 
         << title_1
         << setw(padding) << "" << endl;
    cout << endl;

    printChar(names);

    cout << endl;
    string title_2 = "List of pointers to char arrays";
    cout << setw(padding) << setfill('=') << ""
         << title_2 << setw(padding) << setfill('=') << "" << endl;
    cout << endl;

    printChar(_names_);

    cout << endl;
    nameTest(names, _names_);

    return 0;
}

void randomFill(char _2d_[][50], char** char_ptr) {
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            char ch(65 + rand() % 58);
            _2d_[i][j] = ch;
            char_ptr[i][j] = ch;
        }
    }
}

void printChar(char _2d_[][50]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            cout << _2d_[i][j];
        }
        cout << endl;
    }
}

void printChar(char** char_ptr) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            cout << char_ptr[i][j];
        }
        cout << endl;
    }
}

bool sameName(char _2d_name[], char char_ptr_name[]) {
    for (int i = 0; i < 50; i++) {
        if (_2d_name[i] != char_ptr_name[i]) return false;
    }
    return true;
}

void nameTest(char _2d_[][50], char** char_ptr) {
    for (int i = 0; i < 20; i++) {
        if (sameName(_2d_[i], char_ptr[i])) {
            cout << "Name " << i << ": SAME" << endl;
        }else {
            cout << "Name " << i << ": DIFFERENT" << endl;
        }
    }
}
