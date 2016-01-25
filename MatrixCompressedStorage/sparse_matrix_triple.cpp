#include <cstdio>
#include <cstdlib>
#include <ctime>
#define maxsize 32

/*
int A[10][10] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 5, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 6, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 7, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 8, 0, 0,
                  8, 0, 0, 0, 0, 0, 0, 0, 9, 0,
                  8, 0, 0, 0, 0, 0, 0, 0, 0, 10 };
*/
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
          A[i][j] = (r == 9 ? (rand() % 10)+1 : 0);
      }
    
    create_trimat(A, 10, 10, B);
    
    print(B);
    return 0;
}
