#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point& point_1, const Point& point_2) {
    if (point_1.GetX() < point_2.GetX() && point_1.GetY() > point_2.GetY()) {
        return InitUpperLeftLowerRight(point_1, point_2);
    } else if (point_1.GetX() < point_2.GetX() && point_1.GetY() < point_2.GetY()) {
        return InitLowerLeftUpperRight(point_1, point_2);
    } else if (point_1.GetX() > point_2.GetX() && point_1.GetY() > point_2.GetY()) {
        return InitUpperRightLowerLeft(point_1, point_2);
    } else {
        return InitLowerRightUpperLeft(point_1, point_2);
    }
}

bool Rectangle::InitUpperLeftLowerRight(const Point& point_1, const Point& point_2) {
    m_upLeft = point_1;
    m_lowRight = point_2;
    return true;
}

bool Rectangle::InitLowerLeftUpperRight(const Point& point_1, const Point& point_2) {
    m_lowLeft = point_1;
    m_upRight = point_2;
    return true;
}

bool Rectangle::InitUpperRightLowerLeft(const Point& point_1, const Point& point_2) {
    m_upRight = point_1;
    m_lowLeft = point_2;
    return true;
}

bool Rectangle::InitLowerRightUpperLeft(const Point& point_1, const Point& point_2) {
    m_lowRight = point_1;
    m_upLeft = point_2;
    return true;
}

void Rectangle::ShowRecInfo() const {
    if (tl.has_value() && br.has_value()) {
        cout << "Top-Left: [" << m_upLeft.GetX() << ", ";
        cout << m_upLeft.GetY() << "]" << endl;
        cout << "Bottom-Right: [" << m_lowRight.GetX() << ", ";
        cout << m_lowRight.GetY() << "]" << endl;
    } else if (bl.has_value() && tr.has_value()) {
        cout << "Bottom-Left: [" << m_lowLeft.GetX() << ", ";
        cout << m_lowLeft.GetY() << "]" << endl;
        cout << "Top-Right: [" << m_upRight.GetX() << ", ";
        cout << m_upRight.GetY() << "]" << endl;
    } else {
        cout << "No info found!" << endl;
    }
}