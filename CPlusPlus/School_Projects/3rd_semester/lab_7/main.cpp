#include <iostream>
#include "Rec.h"

using namespace std;

int main() {
    Rectangle rect;
    rect.Display();
    rect.setWidth(10.0).setHeight(20.0).Display();

    return 0;    
}