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
        if (denom < 0) {
            denom = abs(denom);
            num = -num;
        }

        int commonDiv = gcd(num, denom);
        m_numerator = num / commonDiv;
        m_denominator = denom / commonDiv;

    }

    Fraction operator*(const Fraction& snd_op) {
        Fraction res{m_numerator * snd_op.m_numerator, m_denominator * snd_op.m_denominator};
        res.cancelOut();
        return res;
    }

    // Eucilidean Canelletion Algorithm
    void cancelOut() {
        int commonDiv = gcd(m_numerator, m_denominator);
        m_numerator /= commonDiv;
        m_denominator /= commonDiv;
    }

    int gcd(int a, int b) {
        if (a != 0 && b != 0) {
            int max = MAX(abs(a), abs(b));
            int min = MIN(abs(a), abs(b));
            while (min != 0 ) {
                int temp = min;
                min = max % min;
                max = temp;
            }
            return max;
        }
        cout << "Numbers of GCD should be non-zero!";
        return 0;
    }

    int lcm(int a, int b) {
        if (a != 0 && b != 0) {
            int commonDiv = gcd(a, b);
            int leastMul = a * b / commonDiv;
            return leastMul;
        }
        cout << "Numbers of LCM should be non-zero!";
        return 0;
    }

    Fraction operator+(const Fraction& fr) {
        int leastMul = lcm(m_denominator, fr.m_denominator);
        int fac1 = leastMul / m_denominator;
        int fac2 = leastMul / fr.m_denominator;
        Fraction res{m_numerator * fac1 + fr.m_numerator * fac2, leastMul};
        res.cancelOut();
        return res;
    }

    Fraction operator-(const Fraction& fr) {
        int leastMul = lcm(m_denominator, fr.m_denominator);
        int fac1 = leastMul / m_denominator;
        int fac2 = leastMul / fr.m_denominator;
        Fraction res{m_numerator * fac1 - fr.m_numerator * fac2, leastMul};
        res.cancelOut();
        return res;
    }

    Fraction operator-() {
        return {-m_numerator, m_denominator};
    }

    int getNum() const {
        return m_numerator;
    }
    int getDenom() const {
        return m_denominator;
    }
};

Fraction operator+(int const_, const Fraction& fr) {
    return {const_ * fr.getDenom() + fr.getNum(), fr.getDenom()};
}

Fraction operator-(int const_, const Fraction& fr) {
    return {const_ * fr.getDenom() - fr.getNum(), fr.getDenom()};

}

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
    cout << -f1 << "," << -f2 << endl;
    cout << -(-f1) << endl;
    
    return 0;
}