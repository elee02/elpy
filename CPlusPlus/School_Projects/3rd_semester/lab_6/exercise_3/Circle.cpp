#include "Point.h"
#include "Circle.h"
#include <cmath>
#include <iostream>
#define PI 3.14159265358979323846
using namespace std;

Point Circle::center() const{
    return m_center;
}
double Circle::radius() const {
    return m_radius;
}
double Circle::area() const {
    return PI * m_radius * m_radius;
}
bool Circle::IsInside(Point const& var_point) const {
    double x, y;
    var_point.get(x, y);
    double distance = sqrt(pow(x - m_center.getx(), 2) + pow(y - m_center.gety(), 2));
    return distance <= m_radius;
}
void Circle::get(Point& var_center, double& var_radius) const {
    var_center = m_center;
    var_radius = m_radius;
}

void Circle::info() const {
    cout << "Center: "; m_center.info();
    cout << ", Radius: " << m_radius << endl;
}