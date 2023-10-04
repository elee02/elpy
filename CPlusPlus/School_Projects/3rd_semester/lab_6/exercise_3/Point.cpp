#include "Point.h"
#include <iostream>

using namespace std;

double Point::getx() const {
    return x;
}
double Point::gety() const {
    return y;
}
void Point::info() const {
    cout << "[" << Point::getx() << ", " << Point::gety() << "]";
}
void Point::get(double& var_x, double& var_y) const {
    var_x = Point::getx();
    var_y = Point::gety();
}