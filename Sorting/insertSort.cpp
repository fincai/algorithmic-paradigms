#include "shuffle.h"
#define N 2000000


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
    for (int i = 0; i < N; i++)
      A[i] = i+1;
    shuffle(A, 10000);
    //print(A, N);

    clock_t t1 = clock();  
    insertSort(A, N);
    clock_t t2 = clock();

    checkOrder(A, N);
    printf("size of input: %d.\n", N);
    printf("running time: %f secs.\n", double(t2-t1) / CLOCKS_PER_SEC);

    return 0;
}
