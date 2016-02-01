#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <cstdlib>
#include <ctime>

void shuffle(int A[ ], int n) {
    int i, r, temp;
    srand(time(0));
    for (i = n-1; i > 0; i--) {
        r = rand() % (i+1); // r: [0, i]
        temp = A[i];
        A[i] = A[r];
        A[r] = temp;
    }
}
// If stop after k swaps, the first k numbers are a random sample of size k from the N-element set
// Which can be used to generate K non-repeating random integers in specified range[p, q]
// int A[0..p-q] <–– integers in [p, q]
//for (int i = 0; i < (p-q); ++i) 
//	swap(A[i], A[i + rand() % (p-q+1) - i]);
#endif 

