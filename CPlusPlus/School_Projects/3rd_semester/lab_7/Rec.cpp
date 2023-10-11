#include "Rec.h"
#include <iostream>
using namespace std;

Rectangle& Rectangle::setWidth(const double& width) {
    m_width = width;
    return *this;
}

Rectangle& Rectangle::setHeight(const double& height) {
    m_height = height;
    return *this;
}

void Rectangle::Display() const {
            cout << "Width: " << m_width;
            cout << ", Height: " << m_height << endl;
        }