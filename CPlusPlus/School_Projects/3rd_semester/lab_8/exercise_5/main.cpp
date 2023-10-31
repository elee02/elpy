#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
class IntArray
{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }
    friend void setArray(IntArray& ar, int* data, int len);
    friend void displayArray(const IntArray& ar);
    ~IntArray() {
        if (m_data) delete[] m_data;
    }
};

void setArray(IntArray& ar, int* data, int len);
void displayArray(const IntArray& ar);

const int arSize = 20;

int main() {
    int i;
    int data[arSize];
    IntArray ar{ arSize };

    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) data[i] = rand() % 100;

    setArray(ar, data, arSize);
    displayArray(ar);

    return 0;
}

void setArray(IntArray& ar, int* data, int len) {
    for (int i = 0; i < len; ++i) {
        ar.m_data[i] = data[i];
    }
}

void displayArray(const IntArray& ar) {
    for (int i = 0; i < ar.m_len; ++i) {
        cout << "[" << i << "]" << ": " << ar.m_data[i] << endl;
    }
    cout << endl;
}