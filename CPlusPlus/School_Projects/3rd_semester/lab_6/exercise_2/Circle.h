#ifndef _Circle_H_
#define _Circle_H_

#include <iostream>
#include "Point.h"
using namespace std;

class Circle {
    private:
        Point center;
        double radius;
    public:
        Circle(Point const& var_center, double const& var_radius) 
        : center{var_center}, radius{var_radius} {}
        Circle(double const& var_x, double const& var_y, double const& var_radius)
        : center{Point(var_x, var_y)}, radius{var_radius} {}
        Circle()
        : center{Point()}, radius{0} {}
        void info() const;
        void get(Point& center, double& radius) const;
        ~Circle() {
            cout << "Destruction of a class instance" << endl;
            info();
        }
};

#endif