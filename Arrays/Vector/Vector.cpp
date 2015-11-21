#include <iostream>
using namespace std;
#include "Vector.h"


//函数对象
template <typename T>
struct Print {
    void operator()(T & e) { cout << e << " "; }
};


template <typename T>
void print(Vector<T> & V) {
    V.traverse(Print<T>());
    cout << endl;
}

int main() {
    Vector<int> A;
    /*
    A.insert(0, 3);
    A.insert(1, 4);
    A.insert(2, 4);
    A.insert(3, 6);
    A.insert(4, 7);
    A.insert(5, 7);
    A.insert(6, 9);
    print(A);
    A.uniquify();
    print(A);
    */
    srand(time(0));
    for (int i = 0; i < 100; i++)
        A.insert(i, rand() % 100);
    print(A);
    A.mergeSort(0, 100);
    print(A);
    
    return 0;
}
