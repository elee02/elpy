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

    const string speak() const {
        return "???";
    }
};

class Cat : public Animal {
public:
    Cat(const string &name) : Animal{name} {}

    const string speak() const {
        return "Meow";
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
    Cat fred{"Fred"};
    Cat misty{"Misty"};
    Cat zeke{"Zeke"};

    Dog garbo{"Garbo"};
    Dog pooky{"Pooky"};
    Dog truffle{"Truffle"};

    Animal *animals[] = {&fred, &garbo, &misty, &pooky, &truffle, &zeke};

    for (int i = 0; i < 6; i++)
        cout << animals[i]->getName() << " says " << animals[i]->speak() << '\n';

    return 0;
}