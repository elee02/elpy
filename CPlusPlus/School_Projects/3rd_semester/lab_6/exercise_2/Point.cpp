#include "Point.h"
#include <iostream>

using namespace std;

double Point::get_x() const {
    return x;
}
double Point::get_y() const {
    return y;
}
void Point::info() const {
    cout << "[" << x << ", " << y << "]";
}
void Point::get(double& var_x, double& var_y) const {
    var_x = Point::get_x();
    var_y = Point::get_y();
}