#include <iostream>

using namespace std;

enum class week { 
    Sunday, 
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday,
    Saturday 
};

int main(){
    week today;
    today = week::Wednesday;

    if (today == week::Wednesday)
        cout << "Today is Wednesday." << endl;

    cout << int(today) << endl; 

    return 0;
}