#include <iostream>
using namespace std;

void reverse(int A[ ], int lo, int hi) {
    /*
    for (int i = p, j = q; i < j; ++i, --j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    */
    while (lo < hi) swap(A[lo++], A[hi--]);
}

void rotate_left(int A[ ], int n, int p) {
    if (p <= 0 || p >= n) {
        cout << "input error" << endl;
        exit(1);
    }
    reverse(A, 0, p-1);
    reverse(A, p, n-1);
    reverse(A, 0, n-1);
}



int main() {
    int A[10];
    for (int i = 0; i < 10; ++i) A[i] = i+1;

    cout << "input array:" << endl;
    for (int i = 0; i < 10; ++i) 
        cout << A[i] << " ";
    cout << endl;
    
    rotate_left(A, 10, 4);
    
    cout << "after rotate:" << endl;
    for (int i = 0; i < 10; ++i) 
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}
