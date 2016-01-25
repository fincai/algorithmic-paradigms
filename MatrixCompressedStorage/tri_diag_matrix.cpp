#include <cstdio>
#include <cstdlib>
// 半带宽为b的对角矩阵中, |i - j| <= b 的元素是非零元素
#define A(i, j) B[( (abs((i)-(j)) <= 1) ? 2*(i) + (j) : 3*N-2 )]
#define N 6 


int main() {
    int i, j, e;
    int *B = new int[3*N - 2 + 1]; B[3*N-2] = 0;
    printf("请输入主对角线的元素: "); // 1 2 3 4 5 6
    for (i = 0; i < N; i++) {
        scanf("%d", &e);
        A(i, i) = e;
    }
    printf("请输入主对角线上方对角线的元素: ");  // 2 4 6 8 10
    for (i = 0; i < N-1; i++) {
        scanf("%d", &e);
        A(i, i+1) = e;
    }
    printf("请输入主对角线下方对角线的元素: "); // 1 3 5 7 9
    for (i = 1; i < N; i++) {
        scanf("%d", &e);
        A(i, i-1) = e;
    }

    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++)
          printf("%d ", A(i, j));
      printf("\n");
    }
        
    delete B;
    return 0;
}
