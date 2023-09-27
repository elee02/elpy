#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
    // Check if the upper-left point is actually upper-left
    if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY()))
        return false;

    m_upLeft = ul;
    m_lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const {
    cout << "LeftTop: " << '[' << m_upLeft.GetX() << ", ";
    cout << m_upLeft.GetY() << ']' << endl;
    cout << "RightBottom: " << '[' << m_lowRight.GetX() << ", ";
    cout << m_lowRight.GetY() << ']' << endl << endl;
}