/* k-shot strategy: max profit in k buy-sell tractions
 * Time complexity: O(kn)  Addtional space: O(k) 
 */
#include <iostream>
#include <vector>
using namespace std;

// input k <= n/2
template <typename T>
T max_k_pair_profit(const vector<T> & A, const int & k) {
    vector<T> k_sum(k << 1, numeric_limits<T>::min());
    for (int i = 0; i < A.size(); ++i) {
        vector<T> pre_k_sum(k_sum);
        for (int j = 0, sign = -1; j < k_sum.size() && j < i; ++j, sign *= -1) {
            T diff = sign * A[i] + (j == 0 ? 0 : pre_k_sum[j-1]);  // j = 0 indicates the first buy
            k_sum[j] = max(diff, pre_k_sum[j]);
        }
    }
    return k_sum.back();
}


int main() {
    vector<double> A = {3.0, 2.0, 0.0, 5.0, 4.0, 9.0, 10.0, 1.0, 4.0, 13.0};
    cout << max_k_pair_profit(A, 4) << endl;
    cout << max_any_k_pair_profit(A) << endl;
    return 0;
}
