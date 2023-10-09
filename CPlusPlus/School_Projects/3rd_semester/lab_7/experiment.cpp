#include <iostream>
using namespace std;

class Date {
    private:
        int day, month, year;
    public:
        Date(int d, int m, int y) : day{d}, month{m}, year{y} {}
        void display() {
            cout << day << "/" << month << "/" << year << endl;
        }
};

int main() {
    Date d{1, 1, 2000};
    return 0;
}