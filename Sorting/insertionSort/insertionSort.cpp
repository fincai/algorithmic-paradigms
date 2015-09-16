/* Most significant advantage:
 * almost linear for almost sorted input 
 * O(n+d) where d is the number of inversions*/
#include <iostream>
using namespace std;

void insertionSort(int A[ ], int n) {
    // Remove A[i], Insert A[i] into A[0:i-1] sorted subarray
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        while (A[j] > key && j >= 0) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
}

int main() {
    int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    insertionSort(A, 8);
    
    for (int i = 0; i < 8; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
