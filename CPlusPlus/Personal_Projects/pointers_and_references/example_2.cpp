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
    Cat cat{"Simba"};
    cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    Dog dog{"Benji"};
    cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    Animal *pAnimal = &cat;
    cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    return 0;
}