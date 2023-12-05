#include <iostream>
#include <cstring>
using namespace std;

class InhaString {
private:
    char* m_txt;
    size_t m_len;
    friend ostream& operator<<(ostream&, const InhaString&);
    friend istream& operator>>(istream&, InhaString&);
public:
    InhaString(const char* txt = "") 
    : m_txt{new char[strlen(txt) + 1]}, m_len{strlen(txt)} 
    {
        strncpy(m_txt, txt, m_len);
        m_txt[m_len] = '\0';
    }
    InhaString(const InhaString& cpy) {
        if (this != &cpy) {
            delete[] m_txt;
            m_len = cpy.m_len;
            m_txt = new char[m_len + 1];
            strncpy(m_txt, cpy.m_txt, m_len);
            m_txt[m_len] = '\0';
        }
    }
    InhaString& operator=(const InhaString& cpy) {
        if (this != &cpy) {
            delete[] m_txt;
            m_len = cpy.m_len;
            m_txt = new char[m_len + 1];
            strncpy(m_txt, cpy.m_txt, m_len);
            m_txt[m_len] = '\0';
        }
        return *this;
    }

    InhaString operator+(const InhaString& nxt_str) {
        int new_str_len = m_len + nxt_str.m_len;
        char new_str[new_str_len + 1];
        for (int i = 0; i < new_str_len; i++) {
            if (i < m_len) {
                new_str[i] = m_txt[i];
            } else {
                new_str[i] = nxt_str.m_txt[i - m_len];
            }
        }
        new_str[new_str_len] = '\0';
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
        *this = *this + nxt_str;
        return *this;
    }
};

ostream& operator<<(ostream& out, const InhaString& nxt_str) {
    out << nxt_str.m_txt;
    return out;
}
// Dynamically handles the size of istream
istream& operator>>(istream& in, InhaString& nxt_str) {
    int capacity = 10;
    delete[] nxt_str.m_txt;
    nxt_str.m_txt = new char[capacity];
    int size = 0;

    char c;
    while (in.get(c) && c != '\n') {
        if (size == (capacity - 1)) {
            capacity *= 2;
            char* temp = new char[capacity];
            strncpy(temp, nxt_str.m_txt, capacity);
            delete[] nxt_str.m_txt;
            nxt_str.m_txt = temp;
        }
        nxt_str.m_txt[size++] = c;
    }
    nxt_str.m_txt[size] = '\0';
    return in;
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