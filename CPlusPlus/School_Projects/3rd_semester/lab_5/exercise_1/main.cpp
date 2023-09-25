#include <iostream>
#include "lib.h"
using namespace std;

int main() {
    char c = 'a';
    short s = 3000;
    int i = 100000;
    long l = 100000000;
    print(&c, sizeof(c));
    print(&s, sizeof(s));
    print(&i, sizeof(i));
    print(&l, sizeof(l));
    return 0; 
}
