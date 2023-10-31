#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

void Time::printTime() {
    cout << " ";
    cout << setfill('0') << setw(2) << m_hour;
    cout << ":";
    cout << setfill('0') << setw(2) << m_minute;
    cout << ":";
    cout << setfill('0') << setw(2) << m_second;
    cout << endl;
}
void Time::printTime() const {
    if (m_hour >= 12) {
        period[0] = 'P';
        period[1] = 'M';
    } else {
        period[0] = 'A';
        period[1] = 'M';
    }
    cout << " ";
    cout << setfill('0') << setw(2) << m_hour % 12;
    cout << ":";
    cout << setfill('0') << setw(2) << m_minute;
    cout << ":";
    cout << setfill('0') << setw(2) << m_second;
    cout << " " << period << endl;
}