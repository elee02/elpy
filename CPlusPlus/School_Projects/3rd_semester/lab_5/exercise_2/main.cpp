// Exercise #1 main()

#include<iostream>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

int main() {
    Point pos1;
    if (!pos1.InitMembers(-2, 4))
        cout << "pos1-1: Failure of Init" << endl;
    if (!pos1.InitMembers(2, 20))
        cout << "pos1-2: Failure of Init" << endl;

    Point pos2;
    if (!pos2.InitMembers(5, 9))
        cout << "pos2: Failure of Init" << endl;

    cout << "Enter two points:" << endl;
    int pos[4];
    cin >> pos[0] >> pos[1] >> pos[2] >> pos[3];
    pos1.SetX(pos[0]);
    pos1.SetY(pos[1]);
    pos2.SetX(pos[2]);
    pos2.SetY(pos[3]);

    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1))
        cout << "rec-1: Failure of Init" << endl;
    
    rec.ShowRecInfo();

    if (!rec.InitMembers(pos1, pos2))
        cout << "rec-2: Failure of Init" << endl;
        
    rec.ShowRecInfo();

    return 0;
}