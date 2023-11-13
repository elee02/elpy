#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string m_name;

public:
    Animal(const std::string& name)
        : m_name{name} {}

    const string& getName() const {
        return m_name;
    }

    virtual const char* speak() const = 0;

    virtual ~Animal() = default;
};

class Cow : public Animal {
public:
    Cow(const std::string& name)
        : Animal{name} {}

    virtual const char* speak() const override {
        return "Moo";
    }
};

int main() {
    Cow cow{"Betsy"};
    cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}