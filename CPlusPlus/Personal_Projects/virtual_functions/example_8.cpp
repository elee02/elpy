#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string m_name;

    Animal(const string &name) : m_name{name} {}

public:
    const string &getName() const {
        return m_name;
    }

    virtual const string speak() const {
        return "???";
    }
};

class Dog : public Animal {
public:
    Dog(const string &name) : Animal{name} {}

    const string speak() const {
        return "Woof";
    }
};

int main() {
    Dog dog{"Benji"};
    Animal &ani = dog;
    cout << ani.speak();

    return 0;
}