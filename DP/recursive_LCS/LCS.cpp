#include <iostream>
#include <vector>
using namespace std;

int LCS(char A[ ], int n, char B[ ], int m) {
    
    
}

int find(int A[ ], int e, int lo, int hi) {
    while ((lo < hi--) && (e != A[hi])) cout << hi << endl;
    return hi;
}

int main() {
    //int A[2] = {0, 2};
    //int idx = find(A, 1, 0, 2);
    //cout << "idx = " << idx << endl;
    int i = 1, j = 2, k;
    k = i+++j;
    cout << k << endl;
    cout << i << endl;
    cout << j << endl;
    return 0;
    
}
