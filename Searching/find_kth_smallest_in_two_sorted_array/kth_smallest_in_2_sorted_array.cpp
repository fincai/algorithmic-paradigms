#include <iostream>
#include <vector>
using namespace std;

// O(m+n) time complexity with additional O(m+n) space 
// Merge two sorted array, access kth element
int kth_smallest1(vector<int> & A, vector<int> & B, int k) {
    int m = A.size(), n = B.size();
    vector<int> C(m+n); 
    A.push_back(numeric_limits<int>::max());
    B.push_back(numeric_limits<int>::max());
    int i = 0, j = 0;
    for (int x = 0; x < m+n; ++x) {
        if (A[i] <= B[j]) 
            C[x] = A[i++];
        else
            C[x] = B[j++];
    }
    return C[k-1];
}

// O(k) time complexity without additional space
int kth_smallest2(vector<int> & A, vector<int> & B, int k) {    
    int i = 0, j = 0, cnt = 0;
    while (++cnt < k) {
        if (A[i] <= B[j]) 
            ++i;
        else
            ++j;
    } // Decided k-1 smallest element, one before recently moved pointer
    return min(A[i], B[j]);
}

int main() {
    vector<int> A = {1, 3, 5};
    vector<int> B = {2, 4, 8, 10};
    cout << kth_smallest1(A, B, 3) << endl;
    cout << kth_smallest2(A, B, 3) << endl;
    return 0;
}

