/* Parity: return 1 if the number of 1 in bit sequence is odd, return 0 otherwise */
/* Computing the parity of a large number of 64-bit nonnegative integer  */
#include <iostream>
using namespace std;

// The time required is proportional to number of bits
short parity1(unsigned long x) {
    short result = 0;
    while (x) {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}

// The time required is proportional to number of 1 in x 
short parity(unsigned long x) {
    short result = 0;
    while (x) {
        x &= (x - 1);  // Drop the least significant bit
        result ^= 1;
    }
    return result;
}

int main() {
    unsigned long x;
    cin >> x;
    cout << "The parity1 of x: " << parity(x) << endl;
    cout << "The parity of x: " << parity(x) << endl;
    return 0;
}
