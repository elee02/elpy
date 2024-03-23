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
    cout << "   The size of T: " << T.size() << endl << endl;

    // Problem 3.6
    cout << "3.6 Find (a) SUBSTRING(S, 4, 8) and (b) SUBSTRING(T, 10, 5):" << endl;
    cout << "   (a) " << S.substr(4, 8) << endl;
    cout << "   (b) " << T.substr(10, 5) << endl << endl;

    // Problem 3.7
    cout << "3.7 Find (a) INDEX(S, 'P'), (b) INDEX(S, 'E'), (c) INDEX(S, 'THE'),\n(d) INDEX(T, 'THE'), (e) INDEX(T, 'THEN') and (f) INDEX(T, 'TE'):" << endl;
    cout << "   (a) " << S.find('P') << endl;
    cout << "   (b) " << S.find('E') << endl;
    cout << "   (c) " << S.find("THE") << endl;
    cout << "   (d) " << T.find("THE") << endl;
    cout << "   (e) " << T.find("THEN") << endl;
    cout << "   (f) " << T.find("TE") << endl << endl;

    // Problem 3.8
    cout << "3.8 Using S_1//S_2 to stand for the concatination of S_1 and S_2,\nfind (a) 'NO'//'EXIT', (b) 'NO'//' '//'EXIT' and\n(c) SUBSTRING(S, 4, 10)//' ARE '//SUBSTRING(T, 8, 6):";
    cout << "   (a) " << (string)"NO" + "EXIT" << endl;
    cout << "   (b) " << (string)"NO" + " " + "EXIT" << endl;
    cout << "   (c) " << S.substr(4, 10) + " ARE " + T.substr(8, 6) << endl << endl;

    // Problem 3.9
    cout << "3.9 Find (a) DELETE('AAABBB', 3, 3), (b) DELETE('AAABBB', 1, 4),\n(c) DELETE(S, 1, 3) and (d) DELETE(T, 1, 7):" << endl;
    cout << "   (a) " << string("AAABBB").erase(2, 3) << endl;
    cout << "   (b) " << string("AAABBB").erase(0, 4) << endl;
    cout << "   (c) " << S.erase(0, 3) << endl;
    cout << "   (d) " << T.erase(0, 7) << endl;

    // Problem 3.10
    cout << "3.10 Find (a) REPLACE('ABABAB', 'B', 'BAB'), (b) REPLACE(S, 'WE', 'ALL') and\n(c) REPLACE(T, 'THE', 'THESE'):" << endl;
    string t1 = "ABABAB";
    cout << "   (a) " << t1.replace(t1.find('B'), 1, "BAB") << endl;
    cout << "   (b) " << S.replace(S.find("WE"), 2, "ALL") << endl;
    cout << "   (c) " << T.replace(T.find("THE"), 3, "THESE") << endl;
    
    return 0;
}