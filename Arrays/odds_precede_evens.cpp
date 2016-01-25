#include <cstdio>

void rearrange(int A[ ], int n) {
    int i = 0, j = n-1, temp;
    while (i < j) {
        while (A[i] % 2 == 1 && i < j) ++i;
        while (A[j] % 2 == 0 && i < j) --j;
        if (i < j) {
          temp = A[i];
          A[i] = A[j];
          A[j] = temp;
          ++i; --j;
        }
    }
}

int main() {
   int A[10];
   for (int i = 0; i < 10; i++)
       A[i] = i+1;
   rearrange(A, 10);
   
   for (int i = 0; i < 10; i++)
      printf("%d ", A[i]);
   printf("\n");
       
   return 0;
}
