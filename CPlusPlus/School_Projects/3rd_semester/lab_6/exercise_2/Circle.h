#ifndef _Circle_H_
#define _Circle_H_

#include <iostream>
#include "Point.h"
using namespace std;

class Circle {
    private:
        Point m_center;
        double m_radius;
    public:
        Circle(Point const& var_center, double const& var_radius) 
        : m_center{var_center}, m_radius{var_radius} {}
        Circle(double const& var_x, double const& var_y, double const& var_radius)
        : m_center{var_x, var_y}, m_radius{var_radius} {}
        Circle()
        : m_center{Point()}, m_radius{0} {}
        void info() const;
        void get(Point& center, double& radius) const;
        ~Circle() {
            cout << "Destruction of a class instance" << endl;
            info();
        }
};

#endif