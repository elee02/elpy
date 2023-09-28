#ifndef _LIB_H
#define _LIB_H

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string sex;
    int age;
    string email;
    void introduceMyself(void);
};

#endif