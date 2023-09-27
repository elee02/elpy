// Exercise #1 main()

#include<iostream>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

int main() {
    Point pos1;
    if (!pos1.InitMembers(-2, 4))
        cout << "pos1-1: Failure of Init" << endl;
    if (!pos1.InitMembers(2, 4))
        cout << "pos1-2: Failure of Init" << endl;

    Point pos2;
    if (!pos2.InitMembers(5, 9))
        cout << "pos2: Failure of Init" << endl;

    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1))
        cout << "rec-1: Failure of Init" << endl;
    if (!rec.InitMembers(pos1, pos2))
        cout << "rec-2: Failure of Init” << endl;

    rec.ShowRecInfo();

    return 0;
}


// Exercise #3 main()
Point pos3;
pos3.InitMembers(3, 6);
cout << "pos3: [" << pos3.GetX() << ", " << pos3.GetY() << "]" << endl;
if (rec.IsInside(pos3))
    cout << "The pos3 is inside the rectangle." << endl;
else
    cout << "The pos3 is outside the rectangle." << endl;

// Exercise #4 main()
int main() {
    Person ryu = { "Victor Ryu", "male", 30, "IGS2130v1@inha.ac.kr" };
    Person laura = { "Laura Lee", "female", 23, "IGS2130v2@inha.ac.kr" };

    ryu.introduceMyself();
    cout << endl;
    laura.introduceMyself();

    return 0;
}


// Exercise #5 main()
int main(void) {
    Number n1, n2;
    n1.setValue(0.0);
    cout << "n1 : " << n1.getValue() << endl;
    cout << "n1 += 10.5 : " << n1.add(10.5) << endl;
    cout << "n1 -= 1.5 : " << n1.sub(1.5) << endl;
    cout << "n1 *= 3.0 : " << n1.mul(3.0) << endl;
    cout << "n1 /= 9.0 : " << n1.div(9.0) << endl;
    cout << "n2 = n1 : " << n2.setValue(n1.getValue());

    return 0;
}
