#ifndef _QUEUE_
#define _QUEUE_

#include "List.h"

template <typename T>
class Queue : public List<T> {
public:
    void enqueue(const T & e) { insertAsLast(e); }
    T dequeue() { return remove(List<T>::first()); }
    bool empty() { return List<T>::size() == 0; }
    T front() { return List<T>::first()->data; }
    T rear() { return List<T>::last()->data; }
        
};

#endif
