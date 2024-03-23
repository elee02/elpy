#include <iostream>
using namespace std;

void bubble(int *arr, size_t s) {
    int temp = 0;
    for (int i = 0; i < s; i++) {
        for (int j = i; j < s - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int *num, size_t s) {
    for (int i = 0; i < s; i++) {
        cout << num[i] << " ";
    }
}

int main() {
    int data[]{54, 23, 67, 73, -23, 234, 363, 2, 6734, -254};
    cout << "Initial array: " << endl;
    printArray(data, sizeof(data)/sizeof(int));

    bubble(data, sizeof(data)/sizeof(int));
    cout << endl << endl << "After sort: " << endl;
    printArray(data, sizeof(data)/sizeof(int));
    return 0;
}