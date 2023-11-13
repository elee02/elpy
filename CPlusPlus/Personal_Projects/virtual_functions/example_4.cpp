#include <iostream>
#include <string>
using namespace std;

class First {
public:
    virtual void speak() {
        cout << "First::speak()" << endl;
    }
};

class Second : public First {
public:
    virtual void speak() {
        cout << "Second::speak()" << endl;
    }
};

int main() {
    First *ptr = new First{};
    ptr->speak();
    delete ptr;

    ptr = new Second{};
    ptr->speak();
    delete ptr;

    return 0;
}