#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"
#include <optional>

class Rectangle {
private:
    Point m_upLeft;
    Point m_upRight;
    Point m_lowLeft;
    Point m_lowRight;
    optional<int> tl = m_upLeft.GetX();
    optional<int> bl = m_lowLeft.GetX();
    optional<int> tr = m_upRight.GetX();
    optional<int> br = m_lowRight.GetX();
    bool InitUpperLeftLowerRight(const Point& point_1, const Point& point_2);
    bool InitLowerLeftUpperRight(const Point& point_1, const Point& point_2);
    bool InitUpperRightLowerLeft(const Point& point_1, const Point& point_2);
    bool InitLowerRightUpperLeft(const Point& point_1, const Point& point_2);
public:
    // Initializes the rectangle with given upper-left and lower-right points
    bool InitMembers(const Point& ul, const Point& lr);

    // Displays the information about the rectangle
    void ShowRecInfo() const;
};

#endif // __RECTANGLE_H__