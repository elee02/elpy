#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    string m_color{""};
    string m_name{""};

    string& getName() { return m_name;}
    string& getColor() { return m_color;}
};

class Apple: public Fruit {
public:
    Apple(const string& color = "red", const string& name = "Apple")
    : Fruit{color, name} {}
};

class Banana:public Fruit {
public:
    Banana(const string& color = "yellow", const string& name = "Banana") 
    : Fruit{color,name} {}
};

class RedBanana: public Banana {
public:
    RedBanana(): Banana("red", "red banana") {}
};

int main() {
    Apple a{ "red" };
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
