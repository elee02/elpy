#include <iostream>
#include "lib.h"
using namespace std;
// Exercise #4 main()
int main() {
    Person ryu = { "Victor Ryu", "male", 30, "IGS2130v1@inha.ac.kr" };
    Person laura = { "Laura Lee", "female", 23, "IGS2130v2@inha.ac.kr" };

    ryu.introduceMyself();
    cout << endl;
    laura.introduceMyself();

    return 0;
}