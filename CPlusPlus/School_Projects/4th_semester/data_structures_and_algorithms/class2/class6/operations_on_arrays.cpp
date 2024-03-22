#include <iostream>
using namespace std;

size_t second_greatest(int *num, size_t s) {
    int prev = 0, cur = num[0];

    for (int i = 1; i < s; i++) {
        if (num[i] > cur) {
            prev = cur;
            cur = num[i];
        }
    }
    return prev;


}

int main() {
    int data[]{72, 15, 35, 84, 62, 94, 45, 25, 65, 18};
    int idx = second_greatest(data, sizeof(data)/sizeof(int));
    cout << "The second greatest element which has the index " << idx << " is " << data[idx] << endl;
    return 0;
}