#include <iostream>
#include <string>
using namespace std;

class A {
public:
    virtual const string getName() const {
        return "A";
    }
};

class B : public A {
public:
    virtual const string getName() const {
        return "B";
    }
};

class C : public B {
public:
    // virtual const string getName() const { return "C"; }
};

class D : public C {
public:
    virtual const string getName() const {
        return "D";
    }
};

int main() {
    C c;
    A &rBase = c;
    cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}