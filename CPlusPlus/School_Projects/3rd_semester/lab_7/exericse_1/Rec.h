#ifndef _REC_H_
#define _REC_H_

#include <iostream>
using namespace std;

class Rectangle {
    private:
        double m_width{0};
        double m_height{0};
    public:
        Rectangle() = default;
        Rectangle(double width, double height) : m_width{width}, m_height{height} {}
        Rectangle& setWidth(double width);
        Rectangle& setHeight(double height);
        void Display() const;
};

#endif  // REC_H_