#include "lib.h"
#include <iostream>

using namespace std;

void print(void* data, int size) {
    if (size == 1) {
        cout << *(char*)data << endl;
    } else if (size == 2) {
        cout << *(short*)data << endl;
    } else if (size == 4) {
        cout << *(int*)data << endl;
    } else if (size == 8) {
        cout << *(long*)data << endl;
    } else {
        cout << "Invalid size" << endl;
    }
}