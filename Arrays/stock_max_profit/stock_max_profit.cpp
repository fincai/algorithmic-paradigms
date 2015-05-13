#include <iostream>
#include <vector>
using namespace std;

double max_profit1(vector<double> & A) {
    int n = A.size();
    double max_diff = 0;
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j) 
            max_diff = max(A[j] - A[i], max_diff);

    return max_diff;
}

double max3(double p1, double p2, double p3) {
    return max(p1, max(p2, p3));
}

double maximum(vector<double> & A, int low, int high) {
    double max_sf = A[low];
    for (int i = low+1; i <= high; ++i)
        max_sf = max(A[i], max_sf);
    return max_sf;
}

double minimum(vector<double> & A, int low, int high) {
    double min_sf = A[low];
    for (int i = low+1; i <= high; ++i)
        min_sf = min(A[i], min_sf);
    return min_sf;
}

double max_profit2(vector<double> & A, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        double p1 = max_profit2(A, low, mid);
        double p2 = max_profit2(A, mid+1, high);
        double p3 = maximum(A, mid+1, high) - minimum(A, low, mid);
        return max3(p1, p2, p3);
    } else 
        return 0;
}

double max_profit3(vector<double> & A) {
    double min_sf = A[0], maxdiff = 0;
    for (int i = 1; i < A.size(); ++i) {
        maxdiff = max(A[i] - min_sf, maxdiff);
        min_sf = min(A[i], min_sf);
    }
    return maxdiff;
}

int main() {
    vector<double> A = {3.0, 2.0, 0.0, 5.0, 4.0, 9.0, 10.0, 1.0, 4.0, 13.0};
    cout << "O(n^2) max_profit1: " << max_profit1(A) << endl;
    cout << "O(nlgn) max_profit2: " << max_profit2(A, 0, A.size()-1) << endl;
    cout << "O(n) max_profit3: " << max_profit3(A) << endl;
    return 0;
}
