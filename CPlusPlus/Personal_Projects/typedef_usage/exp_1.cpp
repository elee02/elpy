/*
Typedef with classes
*/
#include <iostream>
using namespace std;

typedef class One {
    int m_one;
public:
    One() : m_one(1) {}
    int get() const{
        return m_one;
    }
} ONE;

int main() {
    ONE _1;
    cout << _1.get() << endl;
    return 0;
}