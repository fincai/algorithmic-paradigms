#ifndef BINARY_HEAP
#define BINARY_HEAP

#define maxsize 32
#define l(i) (2*i)
#define r(i) (2*i+1)
#define parent(i) (i/2)

class UnderflowException { };
class OverflowException { };

template <typename T>
class BinaryHeap {
    T A[maxsize]; int n;

    void heapifyDown(int i) {   //前提: 左右子树已成小根堆
      T temp = A[i];
      for (int min; l(i) <= n; i = min) {
        min = (l(i) < n && A[r(i)] < A[l(i)]) ? r(i) : l(i);
        if (A[min] < temp) 
          A[i] = A[min]; //小的往上填
        else
          break;
      }
      A[i] = temp; //i往下填
    }

    void buildHeap() {
      for (int i = n/2; i >= 1; i--)  // n = n0 + n1 + n2  = 2n2 + 1 + n1  完全二叉树 n1 = 0 或 1
          heapifyDown(i);             // n1 = 0时 #非叶 = (n-1)/2 = n/2  n1 = 1时 n2 = (n - 2)/2 = n/2 - 1
    }                                 // #非叶 = n/2 - 1 + 1 = n/2
public:
    BinaryHeap() { n = 0; }
    BinaryHeap(T a[ ], int size) {
      for (int i = 0; i < size; i++)
        A[i+1] = a[i];
      n = size;
      buildHeap();
    }
    
    int size() { return n; }

    void insert(T x) {
      if (n == maxsize)
        throw OverflowException();
      int i = ++n;
      // Heapify Up
      for (; i > 1 && x < A[parent(i)]; i /= 2)
          A[i] = A[parent(i)]; //小的往下填
      A[i] = x;  //x往上填
    }

    T extractMin() {
      if (n == 0)
          throw UnderflowException();
      T min = A[1];
      A[1] = A[n--];
      heapifyDown(1);
      return min;
    }
};
#endif
