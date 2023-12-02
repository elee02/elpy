#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;

    str1 += str2;
    if (str1 == str3) {
        cout << "The strings are the same" << endl;
    } else {
        cout << "The strings are different" << endl;
    }

    string str4;
    cout << "Enter a text: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;
    return 0;
}