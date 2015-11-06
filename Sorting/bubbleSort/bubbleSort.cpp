#include <iostream>
using namespace std;

void bubbleSort(int A[ ], int n) {
    for (int sorted = 0; (sorted = !sorted); n--)
        for (int i = 1; i < n; i++)
            if (A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                sorted = 0;
            }
}

int main() {
    int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    bubbleSort(A, 8);
    for (int i = 0; i < 8; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}



