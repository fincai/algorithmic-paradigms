#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"


bool bracketMatch(const char exp[ ], int lo, int hi) {
    Stack<char> S;
    for (int i = lo; i < hi; i++) {
        if ('(' == exp[i]) S.push('(');
        else if (!S.empty()) S.pop();
        else return false;
    }
    return S.empty();
}

int main() {
    char exp[ ] = "(()())())";
    if (bracketMatch(exp, 0, 8))
        cout << "brackets match!" << endl;
    else
        cout << "brackets doesn't match!" << endl;

    return 0;
}
