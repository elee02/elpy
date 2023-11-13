#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Calling ~Base()\n";
    }
};

class Derived : public Base {
private:
    int* m_array;

public:
    Derived(int length)
        : m_array(new int[length]) {}

    virtual ~Derived() {
        cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};