#include <cstdint>
#include <iostream>

using namespace std;

union ip_address {
    uint32_t laddr;
    unsigned char saddr[4];
};

int main() {
    ip_address addr;
    addr.saddr[0] = 11;
    addr.saddr[1] = 22;
    addr.saddr[2] = 33;
    addr.saddr[3] = 44;

    cout << hex << addr.laddr << endl;

    return 0;
}