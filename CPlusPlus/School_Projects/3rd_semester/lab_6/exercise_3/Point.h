#ifndef _Point_H_
#define _Point_H_

#include <iostream>
using namespace std;

class Point {
    private:
        double x, y;
        double get_x(void) const;
        double get_y(void) const;
        
    public:
        Point(double const& var_x, double const& var_y) 
        : x{var_x}, y{var_y} {}

        Point(Point const& var_point)
        : x{var_point.x}, y{var_point.y} {}

        Point() : x{}, y{} {}

        void info(void) const;

        void get(double& var_x, double& var_y) const;
};

#endif