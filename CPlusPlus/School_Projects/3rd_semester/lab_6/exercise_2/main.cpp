#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

int main() {
    Circle c1;
    Circle c2{};

    Point p{ 10.5, 20.5 };
    Circle c3{ p, 20.0 };
    Circle c4{ 20.5, 10.5, 10.0 };

    cout << "c1.info: "; c1.info();
    cout << "c2.info: "; c2.info();
    cout << "c3.info: "; c3.info();
    cout << "c4.info: "; c4.info();
    return 0;
}