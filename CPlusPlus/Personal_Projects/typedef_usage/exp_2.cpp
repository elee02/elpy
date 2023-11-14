#include <iostream>

using namespace std;

typedef int INT32;
typedef unsigned int UINT32;

typedef struct point {
    int x;
    int y;
} POINT;

typedef struct complex {
    double real;
    double imag;
} COMPLEX;

typedef char* STRING_PTR;
typedef enum { FALSE, TRUE } BOOL;
typedef char field[50];

int main(){
    INT32 i; // same as int i;
    UINT32 k; // same as unsigned int k;
    POINT p, q;
    COMPLEX x, y;
    BOOL condition;
    STRING_PTR r; // char *p;
    field s; // char [50]

    return 0;
}