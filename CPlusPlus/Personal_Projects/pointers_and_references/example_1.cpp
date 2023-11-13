#include <iostream>
using namespace std;

class First {
public:
    void FirstFunc(void) const {
        cout << "FirstFunc" << endl;
    }
};

class Second : public First {
public:
    void SecondFunc(void) const {
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second {
public:
    void ThirdFunc(void) const {
        cout << "ThirdFunc" << endl;
    }
};