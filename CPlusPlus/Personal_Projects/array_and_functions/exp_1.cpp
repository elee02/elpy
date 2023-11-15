#include <iostream>
#include <ctime>
#define SIZE 5
using namespace std;

void randomArray(int*, int); // int arr[] is also ok

int main() {
    int the_arr[SIZE];
    randomArray(the_arr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << the_arr[i] << endl;
    }
    return 0;
}

void randomArray(int* arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

}