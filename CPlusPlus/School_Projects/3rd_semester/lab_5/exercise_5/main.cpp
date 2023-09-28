#include <iostream>
using namespace std;

class Number {
    private:
        double value;
    public:
        double getValue() const {
            return value;
        }
        double setValue(double v) {
            value = v;
            return value;
        }
        double add(double v) {
            value += v;
            return value;
        }
        double sub(double v) {
            value -= v;
            return value;
        }
        double mul(double v) {
            value *= v;
            return value;
        }
        double div(double v) {
            value /= v;
            return value;
        }
};
// Exercise #5 main()
int main(void) {
    Number n1, n2;
    n1.setValue(0.0);
    cout << "n1 : " << n1.getValue() << endl;
    cout << "n1 += 10.5 : " << n1.add(10.5) << endl;
    cout << "n1 -= 1.5 : " << n1.sub(1.5) << endl;
    cout << "n1 *= 3.0 : " << n1.mul(3.0) << endl;
    cout << "n1 /= 9.0 : " << n1.div(9.0) << endl;
    cout << "n2 = n1 : " << n2.setValue(n1.getValue()) << endl;

    return 0;
}
