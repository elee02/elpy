#include <iostream>
#include <cstring>
using namespace std;

class Friend {
protected:
    char* m_name;
    int name_n;
    int m_age;
    int m_fnum;
public:
    Friend(const char* name, int age, int fnum)
    : m_name{nullptr}, m_age{age}, m_fnum{fnum} {
        name_n = strlen(name);
        m_name = new char[name_n + 1];
        strncpy(m_name, name, name_n + 1); 
    }

    void printChar(char* text) {
        for (int i = 0; i < strlen(text); i++) {
            cout << text[i];
        }
    }

    virtual void ShowInfo() {
        cout << "Name: ";
        this -> printChar(m_name); cout << endl;
        cout << "Age: " << m_age << endl;
        cout << "Number of friends: " << m_fnum << endl;

    }
    virtual ~Friend() {
        delete m_name;
    }
};

class UnivFriend : public Friend {
protected:
    double m_ielts;
public:
    UnivFriend(const char* name, int age, int fnum, double ielts)
    : Friend(name, age, fnum), m_ielts{ielts} {}

    void ShowInfo() override {
        cout << "Name: ";
        this -> printChar(m_name); cout << endl;
        cout << "Age: " << m_age << endl;
        cout << "Number of friends: " << m_fnum << endl;
        cout << "IELTS Score: " << m_ielts << endl;
    }

};

class SchFriend : public Friend {
protected:
    char* m_job;
    int m_job_n;
public:
    SchFriend(const char* name, int age, int fnum = 0, const char* job = "N/A")
    : Friend(name, age, fnum), m_job{nullptr} {
        m_job_n = strlen(job);
        m_job = new char[m_job_n + 1];
        strncpy(m_job, job, m_job_n + 1);
    }

    void ShowInfo() override {
        cout << "Name: ";
        this -> printChar(m_name); cout << endl;
        cout << "Age: " << m_age << endl;
        cout << "Number of friends: " << m_fnum << endl;
        cout << "His/Her Job: ";
        this -> printChar(m_job); cout << endl;
    }
    ~SchFriend() {
        delete m_job;
    }
};

int main() {
    Friend* friend1 = new UnivFriend("Soxib", 18, 10, 7.0);
    Friend* friend2 = new SchFriend("Qamariddin", 23, 12, "Optician");
    Friend* friend3 = new Friend("Lochin", 22, 20);

    friend1 -> ShowInfo();
    friend2 -> ShowInfo();
    friend3 -> ShowInfo();

    return 0;
}