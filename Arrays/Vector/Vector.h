/* Vector  ADT */
typedef int Rank;
#define DEFAULT_CAPACITY 32 //默认初始容量


template <typename T> class Vector {
private:
    Rank size; int capacity; T *elem;
    void expand();  //倍增扩容算法，均摊复制开销为O(1)
    
    Rank bubble(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    
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
    //void traverse(void (*visit)(T&)); //遍历的接口
    template<typename VST> void traverse(VST visit); 
    
    int disordered() const; // 统计逆序数
    
    int uniquify1(); //有序向量的唯一化 O(n^2)
    int uniquify(); //有序向量的唯一化 O(n)!

    void bubbleSort(Rank lo, Rank hi) {    // 改进的起泡排序(稳定), 右侧大量就位元素情况下改进为O(n)
        while (lo < (hi = bubble(lo, hi))) ;
    }

    void mergeSort(Rank lo, Rank hi) {  // 二路归并排序
        if (hi - lo < 2) return;
        Rank mi = (lo + hi) >> 1;
        mergeSort(lo, mi);
        mergeSort(mi, hi);
        merge(lo, mi, hi);
    }
    

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
/*
template <typename T>
void Vector<T>::traverse(void (*visit)(T&)) { 
    for (int i = 0; i < size; i++)  visit(elem[i]); 
}
*/
template <typename T> template <typename VST>
void Vector<T>::traverse(VST visit) {
    for (int i = 0; i < size; i++) visit(elem[i]);
}

template <typename T>
int Vector<T>::disordered() const {
    int n = 0;
    for (int i = 1; i < size; i++)
        n +=  (elem[i-1] > elem[i]);
    return n;
}


template <typename T>
int Vector<T>::uniquify1() {
    int oldSize = size; int i = 1;
    while (i < size) 
        (elem[i-1] == elem[i]) ? remove(i) : i++;
    return oldSize - size;
}


template <typename T> int Vector<T>::uniquify() {
    int i = 0, j;
    for (j = 1; j < size; j++)
        if (elem[i] != elem[j]) elem[++i] = elem[j];
    size = ++i;
    return j - i;
}


template <typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi) {
    Rank last = lo;
    while (++lo < hi) {
        if (elem[lo-1] > elem[lo]) {
            last = lo;                   //记录最右侧逆序对的位置
            swap(elem[lo-1], elem[lo]);
        }
    }
    return last;
}


template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
    T* A = elem + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    for (Rank i = 0; i < lb; i++) B[i] = A[i];
    int lc = hi - mi;
    T* C = elem + mi;
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc) ;) {
        if (j < lb && (lc <= k || B[j] <= C[k])) A[i++] = B[j++];
        if (k < lc && (lb <= j || C[k] < B[j])) {
            if (lb <= j) break;  
            A[i++] = C[k++];
        }
    }
    delete [ ] B;
}
