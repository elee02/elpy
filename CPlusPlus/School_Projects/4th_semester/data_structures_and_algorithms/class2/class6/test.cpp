#include <iostream>
using namespace std;

int main() {
    string S = "WE THE PEOPLE";
    cout << "   (b) " << S.replace(S.find("WE"), 2, "ALL") << endl;
    return 0;
}