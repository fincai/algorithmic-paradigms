#include <cstdio>
#include <cstdlib>
#include <ctime>
#define maxsize 32
//定义int trimat[maxsize][3];
//trimat[0][0]表示非零元素个数，trimat[0][1]表示矩阵行数，trimat[0][2]表示矩阵列数

void create_trimat(int **A, int m, int n,  int B[][3]) {
    int k = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
          if (A[i][j] != 0) {
              B[k][0] = A[i][j];
              B[k][1] = i;       //三元组按行优先排列
              B[k][2] = j;
              ++k;
          }
      }
    B[0][0] = k-1;
    B[0][1] = m;
    B[0][2] = n;
}

void transpose(int A[][3], int At[][3]) {
    At[0][0] = A[0][0];
    At[0][1] = A[0][2];
    At[0][2] = A[0][1];
    if (A[0][0] > 0) {
        int q = 1;
        for (int col = 0; col < A[0][2]; col++) 
          for (int p = 1; p <= A[0][0]; p++)
            if (A[p][2] == col) {
               At[q][0] = A[p][0];
               At[q][1] = A[p][2];   // 转置矩阵的三元组按原矩阵的列优先方式存放
               At[q][2] = A[p][1];
               ++q;
            }
    }
}

void print(int B[][3]) {
    for (int i = 0; i < B[0][1]; i++) {
      for (int j = 0; j < B[0][2]; j++) {

          int k, non_zero = 0;
          for (k = 1; k <= B[0][0]; k++)
            if (i == B[k][1] && j == B[k][2]) {
                printf("%d ", B[k][0]);
                non_zero = 1; break;
            }
          if (non_zero == 0) printf("0 ");

      }

      printf("\n");
    }
    printf("Triple representation of sparse matrix A:\n");
    for (int k = 1; k <= B[0][0]; k++)
        printf("%4d%4d%4d\n", B[k][1], B[k][2], B[k][0]);
}


int main() {
    int i, j, r;
    int **A = new int*[10];
    for (i = 0; i < 10; i++)
        A[i] = new int[10];
    int B[maxsize][3];

    //初始化稀疏矩阵
    srand(time(0));
    for (i = 0; i < 10; i++)
      for (j = 0; j < 10; j++) {
          r = rand() % 10;
          A[i][j] = (r == 9 ? (rand() % 9)+1 : 0);
      }
    
    create_trimat(A, 10, 10, B);
    
    print(B);
    //求转置矩阵B的三元组表示
    int Bt[maxsize][3];
    transpose(B, Bt);
    printf("转置矩阵:\n");
    print(Bt);
    
    return 0;
}
