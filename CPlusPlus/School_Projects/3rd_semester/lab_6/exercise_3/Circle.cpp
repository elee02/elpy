#include "Point.h"
#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::get(Point& var_center, double& var_radius) const {
    var_center = center;
    var_radius = radius;
}

void Circle::info(void) const {
    cout << "Center: "; center.info();
    cout << ", Radius: " << radius << endl;
}