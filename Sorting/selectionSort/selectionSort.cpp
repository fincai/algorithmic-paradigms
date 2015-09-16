/* Most significant advantage: O(n) swap
 * Suitable when swapping is expensive (swap between large data chunks)
 * */
#include <iostream>
using namespace std;

void selectionSort(int A[ ], int n) {
// Find the smallest element in A[i:n] subarray and swap to A[i]
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j) 
            if (A[j] < A[min])
                min = j;
        swap(A[i], A[min]);   // O(n) swaps
    }
}

int main() {
   int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
   selectionSort(A, 8);
   
   for (int i = 0; i < 8; ++i)
       cout << A[i] << " ";
   cout << endl;
   
   return 0;
}
