#include <iostream>
using namespace std;
#include "Stack.h"

bool BracketsMatch(const char exp[ ], int lo, int hi) {
    Stack<char> S;
    for (int i = lo; i < hi; i++) {
        switch (exp[i]) {
            case '(': case '[': case '{': S.push(exp[i]); break;
            case ')': if (S.empty() || S.pop() != '(') return false; break;
            case ']': if (S.empty() || S.pop() != '[') return false; break;
            case '}': if (S.empty() || S.pop() != '{') return false; break;
        }
    }
    return S.empty();
}

int main() {
    char exp[ ] = "{()[()][]}";
    if (BracketsMatch(exp, 0, 10))
        cout << "Brackets match!" << endl;
    else
        cout << "Brackets don't match!" << endl;
    return 0;
}
