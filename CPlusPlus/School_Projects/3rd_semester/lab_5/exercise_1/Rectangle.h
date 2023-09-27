#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"

class Rectangle {
private:
    Point m_upLeft;
    Point m_lowRight;
public:
    // Initializes the rectangle with given upper-left and lower-right points
    bool InitMembers(const Point& ul, const Point& lr);

    // Displays the information about the rectangle
    void ShowRecInfo() const;
};

#endif // __RECTANGLE_H__