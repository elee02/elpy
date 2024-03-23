/*Unlike first_pattern_matching_algo.cpp
I used string object in lieu of char arrays*/
#include <iostream>
using namespace std;

int main() {
    
    // Problem 3.5
    string S = "WE THE PEOPLE";
    string T = "OF THE UNITED STATES";

    cout << "3.5 Find the length of S and T:" << endl;
    cout << "   The size of S: " << S.length() << endl;
    // both methods (.length() and .size() ) return the same results
    cout << "   The size of T: " << T.size() << endl;

    // Problem 3.6
    cout << "3.6 Find (a) SUBSTRING(S, 4, 8) and (b) SUBSTRING(T, 10, 5):" << endl;
    cout << "   (a) " << S.substr(4, 8) << endl;
    cout << "   (b) " << T.substr(10, 5) << endl;

    // Problem 3.7
    cout << "3.7 Find (a) INDEX(S, 'P'), (b) INDEX(S, 'E'), (c) INDEX(S, 'THE'),\n(d) INDEX(T, 'THE'), (e) INDEX(T, 'THEN') and (f) INDEX(T, 'TE'):" << endl;
    cout << "   (a) " << S.find('P') << endl;
    cout << "   (b) " << S.find('E') << endl;
    cout << "   (c) " << S.find("THE") << endl;
    cout << "   (d) " << T.find("THE") << endl;
    cout << "   (e) " << T.find("THEN") << endl;
    cout << "   (f) " << T.find("TE") << endl;

    // Problem 3.8
    cout << "3.8 Using S_1//S_2 to stand for the concatination of S_1 and S_2,\nfind (a) 'NO'//'EXIT', (b) 'NO'//' '//'EXIT' and\n(c) SUBSTRING(S, 4, 10)//' ARE '//SUBSTRING(T, 8, 6):";
    cout << "   (a)" << "NO" + "EXIT"
    return 0;
}