/* Take as input a 64-bit integer 
 * and swap the bits and indices i and j */
#include <iostream>
using namespace std;

long swap_bits(long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        x ^= (1L << i) | (1L << j);
    }
    return x;
}


int main() {
    // test cases
    for (long x = 0; x <= 15; ++x) {
        for (int i = 0; i < 4; ++i) 
            for (int j = i+1; j < 4; ++j) {
                cout << "swap " << x << " at indices "
                     << i << " and " << j << ": "
                     << hex << swap_bits(x, i, j) << endl;
            }
    }

    return 0;
}

