#include <cstdio>
#define N 2097152 // 2^21

void insertSort(int A[ ], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
      key = A[i];
      j = i-1;
      while (A[j] > key && j >= 0) 
      { A[j+1] = A[j]; j--; }
      A[j+1] = key;
    }
}

int main() {
    int A[N];


      
}
