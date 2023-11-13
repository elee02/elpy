#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A() {
        cout << getName();
    }

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
    virtual const string getName() const {
        return "C";
    }
};

class D : public C {
public:
    virtual const string getName() const {
        return "D";
    }
};

int main() {
    D d;
    return 0;
}