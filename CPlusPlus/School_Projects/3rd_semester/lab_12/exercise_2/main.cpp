#include <iostream>
#include <cstring>
using namespace std;

class InhaString {
private:
    char* m_txt;
    int m_len;
    friend ostream& operator<<(ostream&, const InhaString&);
public:
    InhaString(const char* txt = "") 
    : m_txt{new char[strlen(txt)]}, m_len{strlen(txt)} 
    {
        strncpy(m_txt, txt, m_len);
    }
    InhaString(const InhaString& cpy) {
        delete[] m_txt;
        m_len = cpy.m_len;
        m_txt = new char[m_len];
        strncpy(m_txt, cpy.m_txt, cpy.m_len);
    }
    InhaString& operator=(const InhaString& cpy) {
        delete[] m_txt;
        m_len = cpy.m_len;
        m_txt = new char[m_len];
        strncpy(m_txt, cpy.m_txt, cpy.m_len);
    }

    InhaString operator+(const InhaString& nxt_str) {
        int new_str_len = m_len + nxt_str.m_len;
        char new_str[new_str_len];
        for (int i = 0; i < new_str_len; i++) {
            if (i < m_len) {
                new_str[i] = m_txt[i];
            } else {
                new_str[i] = nxt_str.m_txt[i - m_len];
            }
        }
        return {new_str};
    }


};

ostream& operator<<(ostream& out, const InhaString& nxt_str) {
    out << nxt_str.m_txt;
    return out;
}