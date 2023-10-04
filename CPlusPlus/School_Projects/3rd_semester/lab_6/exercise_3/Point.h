#ifndef _Poin_H_
#define _Poin_H_

#include <iostream>
using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double const& var_x, double const& var_y) 
        : x{var_x}, y{var_y} {}
        Point(Point const& var_point)
        : x{var_point.x}, y{var_point.y} {}
        Point() : x{0}, y{0} {}
        double getx() const;
        double gety() const;
        void info() const;
        void get(double& x, double& y) const;
};

#endif