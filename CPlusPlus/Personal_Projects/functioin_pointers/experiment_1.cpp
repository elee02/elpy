#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a-b;
}

int main() {
    int (&addPtr)(int, int) = add;
    int (&subPtr)(int, int) = sub;

    cout << addPtr(1, 2) << endl;
    cout << subPtr(1, 2) << endl;
    return 0;
}