// max profit of Buy-Sell a stock twice  
#include <iostream>
#include <vector>
using namespace std;

double max_pair_profit(vector<double> & A, int low, int high) {
    double min_price = A[low], max_diff = 0;
    for (int i = low+1; i <= high; ++i) {
        max_diff = max(A[i] - min_price, max_diff);
        min_price = min(A[i], min_price);
    }
    return max_diff;
}

// O(n^2)
double max_2_pairs_profit1(vector<double> & A) {
    int n = A.size();
    double max_sum = 0;
    for (int j = 1; j <= n-2; ++j) {
        double p1 = max_pair_profit(A, 0, j);
        double p2 = max_pair_profit(A, j+1, n-1);
        max_sum = max(p1 + p2, max_sum);
    }
    return max_sum;
}

// O(n) time complexity with O(n) additional space
double max_2_pairs_profit(vector<double> & A) {
    int n = A.size();
    vector<double> M(n); // Storing the max pair profit in forward iteration
    double min_price = A[0], max_diff = 0;
    for (int j = 1; j <= n-1; ++j) {
        max_diff = max(A[j] - min_price, max_diff);
        M[j] = max_diff;
        min_price = min(A[j], min_price);
    }
    // reverse iteration
    double max_price = A[n-1]; max_diff = 0;
    double max_profit = 0;
    for (int j = n-2; j >= 2; --j) {
        max_diff = max(max_price - A[j], max_diff);
        max_profit = max(max_diff + M[j-1], max_profit);
        max_price = max(A[j], max_price);
    }
    return max(max_profit, A[n-1]); // return the max profit of buy-sell exactly twice and exactly once
}

int main() {
   vector<double> A = {3.0, 2.0, 0.0, 5.0, 4.0, 9.0, 10.0, 1.0, 4.0, 13.0};
   cout << max_2_pairs_profit1(A) << endl;
   cout << max_2_pairs_profit(A) << endl;
   return 0;
}
