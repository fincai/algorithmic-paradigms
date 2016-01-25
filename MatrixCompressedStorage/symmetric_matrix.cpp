#include <cstdio>

#define N 4
#define A(i, j) B[( (i) >= (j) ? ((i)*(i+1))/2+j : ((j)*(j+1))/2+i )]


int main() {
    int i, j, e;
    int *B = new int[(N*(N+1))/2];

    printf("请输入对称矩阵(下三角部分即可):\n");
    for (i = 0; i < N; i++) {
      printf("输入第%d行的%d个元素: ", i+1, i+1);
      for (j = 0; j <= i; j++) {
          scanf("%d", &e);
          A(i, j) = e;
      }
    }
    
    //输出对称矩阵
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++)
        printf("%4d", A(i, j));
      printf("\n");
    }
    
    delete B;
}
