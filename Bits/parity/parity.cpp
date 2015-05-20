/* Parity: return 1 if the number of 1 in bit sequence is odd, return 0 otherwise */
/* Computing the parity of a large number of 64-bit nonnegative integer  */
#include <iostream>
#include <unordered_map>
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

short parity2(unsigned long x, unordered_map<unsigned long, short> & precomputed_parity) {
    return precomputed_parity[x >> 48] ^
           precomputed_parity[(x >> 32) & 0xFFFF] ^
           precomputed_parity[(x >> 16) & 0xFFFF] ^
           precomputed_parity[x & 0xFFFF];
}

int main() {
    unsigned long x;
    cin >> x;
    cout << "The parity1 of x: " << parity1(x) << endl;
    cout << "The parity of x: " << parity(x) << endl;
    cout << numeric_limits<unsigned short>::min() << endl;
    cout << numeric_limits<unsigned short>::max() << endl;
    // Precompute parity of 16-bit sequences
    unordered_map<unsigned long, short> precomputed_parity;
    for (unsigned long i = 0; i <= numeric_limits<unsigned short>::max(); ++i)
        precomputed_parity[i] = parity(i);

    cout << "The precomputed parity of x: " 
         << parity2(x, precomputed_parity)
         << endl;
    
    return 0;
}
