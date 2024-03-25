// Second Pattern matching algorithm using graphs/tables
#include <iostream>
using namespace std;

int F(int, int);

// Graph for the pattern: 'aabbaa'
int states[6][3] = {
    1, 0, 0,
    2, 0, 0,
    2, 3, 0,
    1, 4, 0,
    5, 0, 0,
    -1, 0, 0
};

int main() {
    char T[80] = "ffjjsjjdaaaeedcvvvcrreaavvbbabbaabaabbbaaabbaabbbfss";
    char P[80] = "aabbaa";
    int K = 0, S = 0, I = 0, INDEX = -1;

    while ((S != -1) && (K <= sizeof(T) - 1)) {
        if (T[K] == 'a') {
            I = 0;
        } else if (T[K] == 'b') {
            I = 1;
        } else {
            I = 2;
        }
        S = F(S, I);
        K =+ 1; // exists with S_K+1
    }

    if (S == -1) {
        INDEX = (K - sizeof(P) + 1); // sizeof() => N+1
    // Plus, indexing starts with 0;
    } else {
        INDEX = -1;
    }

    if (INDEX != -1) {
        cout << "The index of the pattern '" << P << "' is " << INDEX << endl;
    } else {
        cout << "The pattern does not exist.";
    }

    return 0;
}

int F(int SK, int TK) {
    return states[SK][TK];
}