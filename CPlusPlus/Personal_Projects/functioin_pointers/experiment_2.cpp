#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int addPtr(int, int) = add;
    cout << addPtr(1, 2) << endl;
    return 0;
}