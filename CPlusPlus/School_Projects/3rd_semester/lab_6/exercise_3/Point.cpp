#include "Point.h"
#include <iostream>

using namespace std;

double Point::get_x(void) const {
    return x;
}
double Point::get_y(void) const {
    return y;
}
void Point::info(void) const {
    cout << "[" << x << ", " << y << "]";
}
void Point::get(double& var_x, double& var_y) const {
    var_x = x;
    var_y = y;
}