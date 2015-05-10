#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_array(const vector<T> & A) {
    for (int i = 0; i < A.size(); ++i)
        cout << A[i] << " ";
    cout << endl;
}

/**
 * Keep the following invariants during partitioning
 * bottom group: A[0 : smaller - 1]
 * middle group: A[smaller : equal - 1]
 * unclassified group: A[equal : larger]
 * top group: A[larger + 1 : A.size() - 1]
 */

template <typename T>
void dutch_flag_partition(vector<T> & A, int pivot_index) {
    T pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = A.size() - 1;
    while (equal <= larger) {
        if (A[equal] < pivot) 
            swap(A[smaller++], A[equal++]);
        else if (A[equal] == pivot)
            ++equal;
        else // A[equal] > pivot
            swap(A[equal], A[larger--]);
        print_array(A);
    }
    cout << smaller << endl;
}


int main() {
    vector<int> A = {2, 8, 7, 4, 3, 5, 6, 4};
    dutch_flag_partition(A, 3);
    print_array(A);
    return 0;
}
