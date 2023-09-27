#ifndef __POINT_H__
#define __POINT_H__

const int POSMIN = 0;
const int POSMAX = 100;

class Point {
    int m_x = -1; // x-pos: range 0~100
    int m_y = -1; // y-pos: range 0~100

    bool isInRange(int pos);

public:
    // Initializes the point with given x and y coordinates
    bool InitMembers(int xpos, int ypos);

    // Sets the x-coordinate of the point
    bool SetX(int xpos);

    // Sets the y-coordinate of the point
    bool SetY(int ypos);

    // Returns the x-coordinate of the point
    int GetX() const;

    // Returns the y-coordinate of the point
    int GetY() const;
};

#endif // __POINT_H__