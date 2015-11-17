#include <iostream>
using namespace std;
#include "Vector.h"

void print(int & e) { 
    cout << e << " ";
}

int main() {
    Vector<int> A;
    A.insert(0, 3);
    A.insert(1, 4);
    A.insert(2, 4);
    A.insert(3, 6);
    A.insert(4, 7);
    A.insert(5, 7);
    A.insert(6, 9);
    A.traverse(print); cout << endl;
    A.deduplicate();
    A.traverse(print); cout << endl;
    
    
    return 0;
}
