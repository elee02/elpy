#include "SecuString.h"
#include <iostream>
#include <string>
using namespace std;

SecuString::SecuString(string const& message = "", string const& password = "")
    : m_message{message}, m_password{password} {
        if (message == "" || password == "") {
            cout << "Error: Empty string" << endl;
            exit(1);
        }
    }

string SecuString::GetMessage(string const& password) const {
    if (password == m_password) {
        return m_message;
    }
    else {
        return "Invalid Password!";
    }
}

bool SecuString::SetMessage(const string &message, const string &password) {
    if (password == m_password) {
        m_message = message;
        return true;
    }
    else {
        return false;
    }
}

bool SecuString::ChangePW(const string &oldPassword, const string &newPassword) {
    if (oldPassword == m_password) {
        m_password = newPassword;
        return true;
    }
    else {
        return false;
    }
}