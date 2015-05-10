#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


template <typename T>
int partition(vector<T> & A, int p, int r) {
    srand(time(0));
    T pivot = A[p + rand() % (r - p + 1)];
    int smaller = p, equal = p, larger = r;
    while (equal <= larger) {
        if (A[equal] < pivot)
            swap(A[smaller++], A[equal++]);
        else if (A[equal] == pivot)
            ++equal;
        else
            swap(A[equal], A[larger--]);
    }
    return smaller; 
}

template <typename T>
void quicksort(vector<T> & A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

template <typename T>
void print_array(vector<T> & A) {
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
        if (i && i % 20 == 0)
            cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> A;
    const int N = 1024;
    for (int i = 1; i <= N; ++i)
        A.emplace_back(i);

    srand(time(0));
    for (int i = N-1; i >= 0; --i)
        swap(A[i], A[rand() % (i+1)]);

    print_array(A);
    
    quicksort(A, 0, A.size()-1);
    print_array(A);
    
    return 0;
}
