#include "shuffle.h"

#define N 10000000
#define l(i) (2*i+1)
#define r(i) (2*i+2)

void maxHeapify(int A[ ], int size, int i) {
    int temp = A[i];
    for (int max; l(i) < size; i = max) {
      max = (l(i) < (size-1) && A[r(i)] > A[l(i)]) ? r(i) : l(i);
      if (A[max] > temp) A[i] = A[max];
      else break;
    }
    A[i] = temp; // 大孩子A[max] <= 目标，填上空闲位
}

void buildHeap(int A[ ], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
      maxHeapify(A, n, i);
}

void heapSort(int A[ ], int n) {
    int size = n;
    buildHeap(A, n);
    for (int i = n-1; i > 0; i--) {
      swap(A[0], A[i]);
      --size;
      maxHeapify(A, size, 0);
    }
}

int main() {
    int *A = new int[N];
    for (int i = 0; i < N; i++)
      A[i] = N - i;
    shuffle(A, N);

    clock_t t1 = clock();
    heapSort(A, N);
    clock_t t2 = clock();

    checkOrder(A, N);
    printf("size of input: %d.\n", N);
    printf("running time: %f secs.\n", double(t2-t1) / CLOCKS_PER_SEC);

    delete A;
    return 0;
}
