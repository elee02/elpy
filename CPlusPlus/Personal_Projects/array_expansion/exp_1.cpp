#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4};

    // checking for the initial elements
    cout << "Initial Array: " << endl; 
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;

    // adding a new element after initialization
    arr[5] = 8;
    cout << endl << "Final Array: " << endl;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;
    cout << arr[5] << endl;
    
    
    return 0;
}