#include <iostream>
using namespace std;

class Base {
public:
    virtual const char* getName() const {
        return "Base";
    }
};

class Derived : public Base {
public:
    virtual const char* getName() const {
        return "Derived";
    }
};

int main() {
    Derived derived;
    const Base& base = derived;

    cout << base.Base::getName() << '\n';

    return 0;
}