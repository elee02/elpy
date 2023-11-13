#include <iostream>
using namespace std;

class A {
public:
    virtual const char* getName1(int x) {
        return "A";
    }

    virtual const char* getName2(int x) {
        return "A";
    }

    virtual const char* getName3(int x) {
        return "A";
    }
};

class B : public A {
public:
    virtual const char* getName1(short int x) override {
        return "B"; // illegal
    }

    virtual const char* getName2(int x) const override {
        return "B"; // illegal
    }

    virtual const char* getName3(int x) override {
        return "B"; // okay
    }
};

int main() {
    return 0;
}