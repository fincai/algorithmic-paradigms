#ifndef BIANRY_HEAP
#define BINARY_HEAP

#define masize 32
#define l(i) (2*i)
#define r(i) (2*i+1)
#define parent(i) (i/2)

class UnderflowException { };
class OverflowException { };

class BinaryHeap {
    int A[maxsize];

    void heapifyDown(int i) {
      for (int min, temp = A[i]; l(i) <= n; i = min) {
        min = (l(i) < n && A[r(i)] < A[l(i)]) ? r(i) : l(i);
        if (A[min] < temp) 
          A[i] = A[min]; //小的往上填
        else
          break;
      }
      A[i] = temp; //i往下填
    }

    void buildHeap() {
      for (int i = 1; i <= n; i++)
          heapifyDown(i);
    }
public:
    BinaryHeap() { A[0] = 0; }
    BinaryHeap(int a[ ], int n) {
      for (int i = 0; i < n; i++)
        A[i+1] = a[i];
      A[0] = n;
      buildHeap();
    }
    
    int size() { return A[0]; }

    void insert(int x) {
      if (A[0] == maxsize)
        throw OverflowException();
      int i = ++A[0];
      // Heapify Up
      for (; i > 1 && x < A[parent(i)]; i /= 2)
          A[i] = A[parent(i)]; //小的往下填
      A[i] = x;  //x往上填
    }

    int extractMin() {
      if (A[0] == 0)
          throw UnderflowException();
      min = A[1];
      A[1] = A[A[0]--];
      heapifyDown(1);
      return min;
    }
};
#endif
