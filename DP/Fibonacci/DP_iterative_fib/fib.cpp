#include <iostream>
using namespace std;
// n            0  1  2  3  4  5  6
//fib(n)        0  1  1  2  3  5  8
//              f  g
//After 1 loop     f  g  
//After 2 loop        f  g

int fib(unsigned n) {
    int f = 0, g = 1;  // fib(0) fib(1)
    while (n--) {
        g = f + g;   // After n Loop: g = fib(n+1)
        f = g - f;    // f = fib(n)
    }
    return f;
}
// O(n) time and O(1) space !


int main() {
    int n; cin >> n;
    cout << "fib(" << n << ") = ";
    cout << fib(n) << endl;
    return 0;
}
