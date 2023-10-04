#include "Point.h"
#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::get(Point& var_center, double& var_radius) const {
    var_center = m_center;
    var_radius = m_radius;
}

void Circle::info() const {
    cout << "Center: "; m_center.info();
    cout << ", Radius: " << m_radius << endl;
}