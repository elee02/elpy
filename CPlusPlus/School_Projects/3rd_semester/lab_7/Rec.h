#ifndef _REC_H_
#define _REC_H_

#include <iostream>
using namespace std;

class Rectangle {
    private:
        double m_width;
        double m_height;
    public:
        Rectangle() = default;
        Rectangle(const double& width, const double& height) : m_width{width}, m_height{height} {}
        Rectangle& setWidth(const double& width);
        Rectangle& setHeight(const double& height);
        void Display() const;
};

#endif  // REC_H_