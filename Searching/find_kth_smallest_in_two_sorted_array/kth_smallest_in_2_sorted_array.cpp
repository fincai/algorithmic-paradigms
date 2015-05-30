// Assuming no duplicated elements
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


int kth_smallest(vector<int> & A, vector<int> & B, int k) {    
    int m = A.size(), n = B.size();
    int b = max(0, k - n);
    int t = min(k, m);
    while (b < t) {
        int x = (b + t) / 2;
        int A_x_1 =  x <= 0 ? numeric_limits<int>::min() : A[x-1];
        int A_x =  x >= m ? numeric_limits<int>::max() : A[x];
        int B_k_x_1 =  k - x - 1 < 0 ? numeric_limits<int>::min() : B[k-x-1];
        int B_k_x =  k - x >= n ? numeric_limits<int>::max() : B[k-x];

        if (A_x < B_k_x_1)
            b = x + 1;
        else if (A_x_1 > B_k_x)
            t = x - 1;
        else 
            return max(A_x_1, B_k_x_1);
    }
    
    int A_b_1 = b - 1 < 0 ? numeric_limits<int>::min() : A[b - 1];
    int B_k_b_1 = k - b - 1 < 0 ? numeric_limits<int>::min() : B[k - b - 1];
    return max(A_b_1, B_k_b_1);
}
    
int main() {
    vector<int> A = {1};
    vector<int> B = {2, 3, 4, 6, 8, 10, 11, 12};
    for (int k = 1; k <= 9; ++k)
        cout << kth_smallest(A, B, k) << endl;
    return 0;
}
