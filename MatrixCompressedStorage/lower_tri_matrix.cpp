#include <cstdio>

#define A(i, j) B[( (i) >= (j) ? ((i)*(i+1))/2+j : (N*(N+1))/2 )]
#define N 4

int main() {
    int i, j, e;
    int *B = new int[(N*(N+1))/2 + 1];
    printf("请输入下三角矩阵(下三角部分):\n");
    for (i = 0; i < N; i++) {
      printf("输入第%d行的%d个元素: ", i+1, i+1);
      for (j = 0; j <= i; j++) {
        scanf("%d", &e);
        A(i, j) = e;
      }
    }
    printf("请输入下三角矩阵的常数部分: ");
    scanf("%d", &e); A(0, 1) = e;
    
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++)
          printf("%4d", A(i, j));
      printf("\n");
    }

    delete B;
    return 0;
}
