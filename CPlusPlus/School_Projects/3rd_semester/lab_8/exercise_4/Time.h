#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>
using namespace std;

class Time {
    mutable char period[3] = "AM";
    int m_hour{0};
    int m_minute{0};
    int m_second{0};
public:
    Time() = default;
    Time(int h, int m, int s) : m_hour{h}, m_minute{m}, m_second{s} {
        if (m_hour < 0 || m_hour > 23 || m_minute < 0 || m_minute > 59 || m_second < 0 || m_second > 59) {
            cout << "Invalid time - setting to 00:00:00" << endl;
            m_hour = m_minute = m_second = 0;
        }
    }
    Time(const Time& tt) : m_hour{tt.m_hour}, m_minute{tt.m_minute}, m_second{tt.m_second} {
        if (m_hour < 0 || m_hour > 23 || m_minute < 0 || m_minute > 59 || m_second < 0 || m_second > 59) {
            cout << "Invalid time - setting to 00:00:00" << endl;
            m_hour = m_minute = m_second = 0;
        }
    }

    void printTime();
    void printTime() const;
};

#endif