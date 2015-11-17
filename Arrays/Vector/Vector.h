/* Vector  ADT */
typedef int Rank;
#define DEFAULT_CAPACITY 32 //默认初始容量


template <typename T> class Vector {
private:
    Rank size; int capacity; T *elem;
    void expand();  //倍增扩容算法，均摊复制开销为O(1)
    
public:
    Vector(int c = DEFAULT_CAPACITY) 
    { elem = new T[capacity = c]; size = 0; }
    
    ~Vector() { delete [ ] elem; }
    
    T & operator[ ](Rank r) const { return elem[r]; }  //重载实现下标访问

    Rank insert(Rank r, const T & e);
    int remove(Rank lo, Rank hi); //区间删除[lo, hi) 返回删除的个数
    T remove(Rank r); //利用区间删除算法删除单个元素
    Rank find(const T & e, Rank lo, Rank hi); // 查找, 命中多个时返回秩最大者
    int deduplicate(); //唯一化
    void traverse(void (*visit)(T&)); //遍历的接口

};

template <typename T> 
void Vector<T>::expand() {
    if (size < capacity) return;
    capacity = max(capacity, DEFAULT_CAPACITY);
    T *oldElem = elem; elem = new T[capacity <<= 1];
    for (int i = 0; i < size; i++)
        elem[i] = oldElem[i];
    delete [ ] oldElem;
}

template <typename T> 
Rank Vector<T>::insert(Rank r, const T & e) {
    expand();      // expand if full
    for (int i = size; i > r; i--)
        elem[i] = elem[i-1];
    elem[r] = e; size++;
    return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    while (hi < size)  elem[lo++] = elem[hi++]; //
    size = lo;
    return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r) {
    T e = elem[r];
    remove(r, r+1);  // 区间删除的特例 [r, r+1)
    return e;
}


template <typename T>
Rank Vector<T>::find(const T & e, Rank lo, Rank hi) {
    while ((lo < hi--) && e != elem[hi]) ;
    return hi;  // hi < lo意味着查找失败
}


template <typename T>
int Vector<T>::deduplicate() {   // O(n^2)
    Rank oldSize = size;
    Rank i = 1;
    while (i < size) 
        (find(elem[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - size;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&)) { 
    for (int i = 0; i < size; i++)  visit(elem[i]); 
}
