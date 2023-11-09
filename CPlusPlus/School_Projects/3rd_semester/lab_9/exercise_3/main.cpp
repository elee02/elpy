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

int main() {
    Apple a{ "red" };
    Banana b;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;    return 0;
}
