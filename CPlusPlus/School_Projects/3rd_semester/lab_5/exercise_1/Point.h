#ifndef __POINT_H__
#define __POINT_H__

const int POSMIN = 0;
const int POSMAX = 100;

class Point {
    int m_x; // x-pos: range 0~100
    int m_y; // y-pos: range 0~100

    bool isInRange(int pos);

public:
    bool InitMembers(int xpos, int ypos);
    bool SetX(int xpos);
    bool SetY(int ypos);
    int GetX() const;
    int GetY() const;
};

#endif // __POINT_H__
