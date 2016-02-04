#include "shuffle.h"
#define N 8000000 
// 左边元素 <= 轴点 <= 右边元素  轴点必然就位, 有序序列每个元素都是轴点
// Hoare的partition过程尝试构造轴点
// 但返回值不一定是轴点的位置
// 只是围绕轴点把数组划分成一小一大两个集合
int partition(int A[ ], int p, int r) { 
    srand(time(0)); swap(A[p], A[p + rand() % (r-p+1)]);
    int pivot = A[p]; //不选A[r]作为轴点候选, j一定会越过r位置，就不可能返回r
    int i = p-1, j = r+1;
    while (1) {
       do { j--; } while (pivot < A[j]);
       do { i++; } while (A[i] < pivot);
       if (i < j) swap(A[i], A[j]);
       else return j;     // 证明: 终止时, A[p..j] <= A[j+1..r]总是成立
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
    
    delete A;
    return 0;    
}
