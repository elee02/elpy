#include <iostream>
#define MAX(a, b) (a > b) ? a : b // no colon after the macro
using namespace std;

int main() {
    int a = 5, b = 10;
    int c = MAX(a, b);
    cout << c << endl;
    return 0;
}