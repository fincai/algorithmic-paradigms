/* Computing the parity of a large number of 64-bit nonnegative integer  */
#include <iostream>
using namespace std;

short parity(unsigned long x) {
    short result = 0;
    while (x) {
        x &= (x - 1);
        result ^= 1;
    }
    return result;
}

int main() {
    unsigned long x;
    cin >> x;
    cout << "The parity of x: " << parity(x) << endl;
    return 0;
}
