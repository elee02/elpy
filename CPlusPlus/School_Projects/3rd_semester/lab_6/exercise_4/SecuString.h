#ifndef _SecuString_H_
#define _SecuString_H_

#include <iostream>
#include <string>
using namespace std;

class SecuString {
private:
    string m_message;
    string m_password;
public:
    SecuString(string const& message, string const& password);
    string GetMessage(string const& password) const;
    bool SetMessage(string const& message, string const& password);
    bool ChangePW(string const& oldPassword, string const& newPassword);
};

#endif