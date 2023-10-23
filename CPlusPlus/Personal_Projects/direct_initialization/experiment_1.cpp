#include <iostream>
using namespace std;

class A {
    int m_a;
    public:
        A() { cout << "A constructor" << endl; }
        A(int a) : m_a(a) { cout << "A constructor with a = " << a << endl; }
};

int main() {
    A a(5);
    A b{a}; // direct initialization
    return 0;
}