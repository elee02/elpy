#include <iostream>
#include <cstring>
using namespace std;

class InhaString {
private:
    char* m_txt;
    int m_len;
    friend ostream& operator<<(ostream&, const InhaString&);
    friend istream& operator>>(istream&, const InhaString&);
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
                new_str[i] = nxt_str.m_txt[i - m_len + 1];
            }
        }
        return {new_str};
    }
    bool operator==(const InhaString& nxt_str) const {
        if (m_len != nxt_str.m_len) return false;
        for (int i = 0; i < m_len; i++) {
            if (m_txt[i] != nxt_str.m_txt[i])
                return false;
        }
        return true;
    }

    const InhaString& operator+=(const InhaString& nxt_str) {
        int new_str_len = m_len + nxt_str.m_len;
        char* new_str = new char[new_str_len];
        for (int i = 0; i < new_str_len; i++) {
            if (i < m_len) {
                new_str[i] = m_txt[i];
            } else {
                new_str[i] = nxt_str.m_txt[i - m_len + 1];
            }
        }
        delete[] m_txt;
        m_txt = new_str;
        return *this;
    }
};

ostream& operator<<(ostream& out, const InhaString& nxt_str) {
    out << nxt_str.m_txt;
    return out;
}
istream& operator>>(istream& in, const InhaString& nxt_str) {
    
}
int main() {
    InhaString str1 = "I like ";
    InhaString str2 = "string class";
    InhaString str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3) {
        cout << "Two strings are identical" << endl;
    } else {
        cout << "Two strings are different" << endl;
    }

    InhaString str4;
    cout << "Enter a text: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;
    return 0;
}