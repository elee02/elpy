#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    int m_value;

public:
    Base(int value) : m_value{value} {}

    const string getName() const {
        return "Base";
    }

    int getValue() const {
        return m_value;
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base{value} {}

    const string getName() const {
        return "Derived";
    }

    int getValueDoubled() const {
        return m_value * 2;
    }
};

int main() {
    Derived derived{5};
    cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Derived &rDerived = derived;
    cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

    Derived *pDerived = &derived;
    cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    return 0;
}