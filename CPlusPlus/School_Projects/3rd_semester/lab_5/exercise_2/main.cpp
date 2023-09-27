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

    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1))
        cout << "rec-1: Failure of Init" << endl;
    if (!rec.InitMembers(pos1, pos2))
        cout << "rec-2: Failure of Init" << endl;

    rec.ShowRecInfo();

    return 0;
}