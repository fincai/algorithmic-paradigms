#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

inline void swap(int & a, int & b) { int temp = a; a = b; b = temp; }

void shuffle(int A[ ], int n) {
    srand(time(0));
    for (int i = n-1; i > 0; i--) 
      swap(A[i], A[rand() % (i+1)]); // swap(A[i], A[0, i])
}
// If stop after k swaps, the first k numbers are a random sample of size k from the N-element set
// Which can be used to generate K non-repeating random integers in specified range[p, q]
// int A[0..p-q] <–– integers in [p, q]
//for (int i = 0; i < (p-q); ++i) 
//	swap(A[i], A[i + rand() % (p-q+1) - i]);
void print(int A[ ], int n) {
    for (int i = 0; i < n; i++) {
      printf("%d ", A[i]);
      if ((i+1) % 10 == 0) 
        printf("\n");
    }
    printf("\n");
}

void checkOrder(int A[], int n) {
    bool sorted = true;
    for (int i = 0; i < (n-1); i++)
        if (A[i] > A[i+1]) {
            sorted = false;
            break;
        }
    if (sorted) 
      printf("The array is sorted.\n");
    else
      printf("Sorting failed.\n");
}
#endif 

