#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual int getValue() const {
        return 5;
    }
};

class Derived : public Base {
public:
    // different return type
    virtual double getValue() const {
        return 6.78;
    }
};

int main() {
    Derived derived{};
    Base *pbase = &derived;
    cout << pbase->getValue();

    return 0;
}