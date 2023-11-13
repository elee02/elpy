#include <iostream>
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

    Base &rBase = derived;
    cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';

    Base *pBase = &derived;
    cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';

    return 0;
}