#include <iostream>
#include <ostream>
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int num = 0, int denom = 1) {
        int commonDiv = gcd(num, denom);
        m_numerator = num / commonDiv;
        m_denominator = denom / commonDiv;
    }

    Fraction operator*(const Fraction& snd_op) {
        Fraction res{m_numerator * snd_op.m_numerator, m_denominator * snd_op.m_denominator};
        res.cancelOut();
        return res;
    }

    void cancelOut() {
        int commonDiv = gcd(m_numerator, m_denominator);
        m_numerator /= commonDiv;
        m_denominator /= commonDiv;
    }

    // Eucilidean Canelletion Algorithm
    int gcd(int a, int b) {
        int max = MAX(a, b);
        int min = MIN(a, b);
        while (min != 0 ) {
            int temp = min;
            min = max % min;
            max = temp;
        }
        return max;
    }

    int getNum() const {
        return m_numerator;
    }
    int getDenom() const {
        return m_denominator;
    }
};

Fraction operator*(int coef, const Fraction& fr) {
    Fraction res{coef * fr.getNum(), fr.getDenom()};
    res.cancelOut();
    return res;
}

ostream& operator<<(ostream& out, const Fraction& frac) {
    out << frac.getNum() << "/" << frac.getDenom();
    return out;
}



int main() {
    Fraction f1{1, 2}, f2{3, 4};
    cout << f1 << "," << f2 << endl;
    cout << f1 * f2 << endl;
    cout << f1 * 2 << endl;
    cout << 3 * f2 << endl;
    cout << 2 * f1 * f2 * 3 << endl;
    return 0;
}