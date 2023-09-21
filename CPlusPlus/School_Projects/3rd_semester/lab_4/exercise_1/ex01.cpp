#include <iostream>
using namespace std;

void sort3(double&, double&, double&, bool(*)(double&, double&));
void print3(const double&, const double&, const double&);
void swap2(double&, double&);
bool ascending(double&, double&);
bool descending(double&, double&);

int main() {

    double na1 = 10.3, na2 = -2.1, na3 = 8.0;
    double nd1 = 10.3, nd2 = -2.1, nd3 = 8.0;

    cout << "Befere sort: "; print3(na1, na2, na3);

    sort3(na1, na2, na3, ascending);
    sort3(nd1, nd2, nd3, descending);

    cout << "After sort(ascending): "; print3(na1, na2, na3);
    cout << "After sort(descending): "; print3(nd1, nd2, nd3);

    return 0;
}

void sort3(double& line_1, double& line_2, double& line_3, bool (*swapper)(double&, double&)) {
    if (swapper == &ascending) {
        if (descending(line_1, line_2)) {
            swap2(line_1, line_2);
        } if (descending(line_2, line_3)) {
            swap2(line_2, line_3);
        }
    } else if (swapper == &descending) {
        if (ascending(line_1, line_2)) {
            swap2(line_1, line_2);
        } if (ascending(line_2, line_3)) {
            swap2(line_2, line_3);
        }
    } else {
        cout << "Unknown Function!" << endl;
    }
}
void swap2(double& arg_1, double& arg_2) {
    double help = arg_1;
    arg_1 = arg_2;
    arg_2 = help;
}
bool ascending(double& first, double& second) {
    if (first > second) return false;
    else if (second > first) return true;
    return 0;
}
bool descending(double& first, double& second) {
    if (first > second) return true;
    else if (second > first) return false;
    return 0;
}

void print3(const double& line_1, const double& line_2, const double& line_3) {
    cout << line_1 << " " << line_2 << " " << line_3 << endl;
}