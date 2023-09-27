#include <iostream>
#include "Point.h"
using namespace std;

bool Point::isInRange(int pos) {
    if (pos >= POSMIN && pos <= POSMAX) return true;
    if (pos == -1) return true;

    return false;
}

bool Point::InitMembers(int xpos, int ypos) {
    if (!SetX(xpos) || !SetY(ypos))
        return false;
    return true;
}

int Point::GetX() const {
    return m_x;
}

int Point::GetY() const {
    return m_y;
}

bool Point::SetX(int xpos) {
    if (!isInRange(xpos))
        return false;

    m_x = xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if (!isInRange(ypos))
        return false;

    m_y = ypos;
    return true;
}
