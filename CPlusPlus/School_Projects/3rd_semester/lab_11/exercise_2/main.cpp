#include <iostream>
#include <ostream>
#define MAX(a, b) ((a > b) ? a : b)
using namespace std;

class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int num = 0, int denum = 1) : m_numerator{num}, m_denominator{denum} {
    int range = MAX(num, denum);
    
    for (int i = 0; i < range; i++) {
        int rem1 = num % i;
        int rem2 = denum % i;

        if (rem1 == rem2 == 0) {
            num /= i;
            denum /= i;
        }
    }

    Fraction operator*(const Fraction& snd_op) {
        Fraction res{m_numerator * snd_op.m_numerator, m_denominator * snd_op.m_denominator};
        return cancelOut(res);
    }


    Fraction& cancelOut(Fraction& frac) {
        int range = MAX(frac.getNum(), frac.getDenum());
        int div = range;
        
        for (int i = range; i > 1; i--) {
            int rem1 = frac.getNum() % i;
            int rem2 = frac.getDenum() % i;

            if (rem1 == 0 && rem2 == 0) {
                frac.setNum(frac.getNum() / i);
                frac.setDenum(frac.getDenum() / i);
            }
        }     

    int getNum() const {
        return m_numerator;
    }
    int getDenum() const {
        return m_denominator;
    }

    void setNum(int new_num) {
        m_numerator = new_num;
    }
    void setDenum(int new_denum){ 
        m_denominator = new_denum;
    }
};

ostream& operator<<(ostream& out, const Fraction& frac) {
    out << frac.getNum() << "/" << frac.getDenum();
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