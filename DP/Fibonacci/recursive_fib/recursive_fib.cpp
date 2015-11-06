#include <iostream>
using namespace std;

// Exponential time complexity 
// require about 10^10 secs(3 centries) to compute fib(92)!
int fib(int n) {
    return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int main() {
    int n; cin >> n;
    cout << "fib(" << n << ") = ";
    cout << fib(n) << endl;
    return 0;
}
