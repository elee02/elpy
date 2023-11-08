#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class IntArrayHandler;

class IntArray {
private:
    int m_len = 0;
    int *m_data = nullptr;

public:
    IntArray(int len) : m_len(len), m_data(new int[len]) {}
    ~IntArray() {
        if (m_data) delete[] m_data;
    }
    friend class IntArrayHandler;
};

class IntArrayHandler {
    IntArray* m_arr{nullptr};
public:
    IntArrayHandler(IntArray* arr) : m_arr{arr} {}

    void setIntArray(IntArray* set_arr) {
        m_arr = set_arr;
    } 

    void setArray(int* int_ptr, int arr_size) {
        for (int i = 0; i < arr_size; i++) {
            m_arr -> m_data[i] = int_ptr[i];
        }
    }
    void displayArray() {
        for (int i = 0; i < m_arr -> m_len; i++) {
            cout << m_arr -> m_data[i] << endl;
        }
    }

    void stat() {
        cout << "# of elements: " << m_arr -> m_len << endl;

        int sum = 0;
        for (int i = 0; i < m_arr -> m_len; i++) {
            sum += m_arr -> m_data[i];
        }
        cout << "Sum: " << sum << endl;
        double avarage = 1.0 * sum / (m_arr -> m_len);
        cout << "Avarage: " <<  avarage << endl;
    }
};

const int arSize = 20;

int main() {
    int i;
    int data1[arSize], data2[arSize];
    IntArray ar1{arSize}, ar2{arSize};

    srand((unsigned int)time(NULL));

    for (int i = 0; i < arSize; ++i) {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }

    IntArrayHandler handler{&ar1};
    handler.setArray(data1, arSize);

    cout << "== ar1: displayArray ()" << endl;
    handler.displayArray();

    cout << "====== ar1: stat()" << endl;
    handler.stat();

    cout << endl;

    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);

    cout << endl << "== ar2: displayArray ()" << endl;
    handler.displayArray();

    cout << "====== ar2: stat()" << endl;
    handler.stat();

    cout << endl;

    return 0;
}