#include <iostream>
#include "lib.h"
using namespace std;

void Person::introduceMyself(void) {
    cout << "My name is " << name << "." << endl;
    cout << "I am " << sex << ", and " << age << " years old." << endl;
    cout << "My email address is " << email << "." << endl;
}