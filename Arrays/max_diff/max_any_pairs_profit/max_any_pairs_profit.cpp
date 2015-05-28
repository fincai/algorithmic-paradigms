/* Maximum profit can be made by buying and selling a share any number of times 
 * over a day range*/
#include <iostream>
#include <vector>
using namespace std;

// Just harvest every increase in the price plot
double max_profit(const vector<double> & A) {
    double profit = 0;
    for (int i = 1; i < A.size(); ++i) {
        double delta = A[i] - A[i-1];
        if (delta > 0)
            profit += delta;
    }
    return profit;
}

int main() {
   vector<double> A= {3.0, 2.0, 0.0, 5.0, 4.0, 9.0, 10.0, 1.0, 4.0, 13.0};
   cout << max_profit(A) << endl;
   return 0;
}
