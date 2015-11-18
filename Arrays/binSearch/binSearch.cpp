#include <iostream>
using namespace std;

typedef int Rank;

template <typename T>
static Rank binSearch(T* A, const T & e, Rank lo, Rank hi) {
    while (lo < hi) {
        Rank mi = (lo + hi) >> 1;
        if (e < A[mi]) hi = mi;
        else if (A[mi] < e) lo = mi + 1;
        else return mi;
    }
    return -1;
}

int main() {
    int A[7] = {2, 2, 3, 4, 5, 9, 10};
    Rank r = binSearch(A, 5, 0, 7);
    if (r < 0) 
        cout << "Not found." << endl;
    else
        cout << "Found at rank " << r << endl;
    return 0;
}
