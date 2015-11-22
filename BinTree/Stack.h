#ifndef _STACK_ 
#define _STACK_

#include "Vector.h"

template <typename T> 
class Stack : public Vector<T> {
public:
    void push(const T & e) { Vector<T>::insert(Vector<T>::length(), e); }
    T pop() { return Vector<T>::remove(Vector<T>::length()-1); }
    T & top() { return (*this)[Vector<T>::length()-1];}
};



#endif
