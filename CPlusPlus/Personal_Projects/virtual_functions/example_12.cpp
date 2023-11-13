#include <iostream>
#include <string>
using namespace std;

class A {
public:
    const string getName() const {
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
    const string getName() const {
        return "C";
    }
};

class D : public C {
public:
    const string getName() const {
        return "D";
    }
};

int main() {
    D d;
    B &rBase = d;
    cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}