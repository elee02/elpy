#include <iostream>
using namespace std;

class A {
public:
    virtual const char* getName1(int x) {
        return "A";
    }

    virtual const char* getName2(int x) {
        return "A";
    }
};

class B : public A {
public:
    virtual const char* getName1(short int x) {
        return "B";
    }

    virtual const char* getName2(int x) const {
        return "B";
    }
};

int main() {
    B b;
    A &rBase = b;
    cout << rBase.getName1(1) << endl;
    cout << rBase.getName2(2) << endl;

    return 0;
}