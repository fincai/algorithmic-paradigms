#include <iostream>
using namespace std;

void bubbleSort(int A[ ], int n) {
    for (int i = n-1; i >=1; --i) {
        int flag = 0;
        for (int j = 0; j < i; ++j)
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                flag = 1;
            }
        if (flag == 0) return;
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



