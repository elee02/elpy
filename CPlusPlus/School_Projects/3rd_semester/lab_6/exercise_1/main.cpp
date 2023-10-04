#include "Point.h"
#include <iostream>
using namespace std;

int main() {
    double x, y;
    Point p{10.5, 20.99};
    p.info();
    p.get(x,y);

    cout << x << ", " << y << endl;

    return 0;
}