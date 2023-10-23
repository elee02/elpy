#include <iostream>
using namespace std;

void printHello() {
    cout << "Hello, World!\n";
}

int main() {
    void (*ptr)() = printHello;
    ptr();
    return 0;
}