#include "shuffle.h"
#define N 40000000

int partition(int A[ ], int p, int r) {
    srand(time(0)); 
    int x = p + (rand() % (r-p));  //不选A[r]作为轴点, j就不可能返回r
    //for (int i = p; i <= r; i++)
     //   printf("%d ", A[i]);
    //printf("\np = %d r = %d pivot index: %d\n", p, r, x);
    int pivot = A[x];
    int i = p-1, j = r+1;
    while (1) {
       do { j--; } while (pivot < A[j]);
       do { i++; } while (A[i] < pivot);
       if (i < j) swap(A[i], A[j]);
       else return j;     // 证明: 终止时, A[p..j] <= A[j+1..r]总是成立, 即A[j]一定就位
    }
}

void quicksort(int A[ ], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // A[r]作轴且A[p..r-1] < pivot时, i = j = r,  会产生无穷递归
        quicksort(A, p, q);  
        quicksort(A, q+1, r);
    }
}

int main() {
    int *A = new int[N];
    for (int i = 0; i < N; i++)
      A[i] = N-i;
    shuffle(A, N);
    
    clock_t t1 = clock();
    quicksort(A, 0, N-1);
    clock_t t2 = clock();
    
    //print(A, N);
    checkOrder(A, N);
    printf("size of input: %d.\n", N);
    printf("running time: %f secs.\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;    
}
