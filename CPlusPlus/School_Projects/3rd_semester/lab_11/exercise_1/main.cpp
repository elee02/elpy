#include <iostream>
#include <ostream>
using namespace std;

class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int num = 0, int denom = 1) : m_numerator{num}, m_denominator{denom} {}
    int getNum() const {
        return m_numerator;
    }
    int getDenom() const {
        return m_denominator;
    }
};

ostream& operator<<(ostream& out, const Fraction& frac) {
    out << frac.getNum() << "/" << frac.getDenom();
    return out;
}

int main() {
    Fraction f1{ 1, 2}, f2{ 3, 4 };
    cout << f1 << ", " << f2 << endl;
    return 0;
}