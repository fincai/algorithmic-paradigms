#ifndef _LIST_
#define _LIST_
typedef int Rank 

template <typename T>
struct ListNode {
    T data;
    ListNode<T>* prev;
    ListNode<T>* next;
    ListNode() { } //用于头尾结点
    ListNode(const T & e, ListNode<T>* p = NULL, ListNode<T>* n = NULL)
        : data(e), prev(p), next(n) { }
    ListNode<T>* insertAsPred(int & e) {
        return prev = prev->next = new ListNode(e, prev, this);
    }
    ListNode<T>* insertAsSucc(int & e) {
        return next = next->prev = new ListNode(e, this, next);
    }
};

template <typename T>
class List {  //双链表实现
    T size;
    ListNode<T>* header, trailer;
    
    void init() {
        header = new ListNode(); 
        trailer = new ListNode();
        header->next = trailer;
        trailer->prev = header;
        header->prev = tailer->next = NULL;
        size = 0;
    }

public:
    List() { init(); }

    ListNode<T>* first() const { return header->next; }   // 首元素
    ListNode<T>* last() const { return trailer->prev; }   // 末元素
    bool valid(ListNode<T>* p) { return p && (p != header) && (p != trailer); }

    T operator[ ](Rank r) const {  //模仿向量的循秩访问，但效率低下O(r)
        ListNode<T>* p = first();
        while (r--) p = p->next;
        return p->data;
    }
    // find(e, n, p) 在结点p(可能是trailer）的n个前驱中，找到等于e的最后者
    // 可以重载另一接口find(e, p, n) 表示在p的n个后继中的查找
    ListNode<T>* find(const T & e, int n, ListNode<T>* p) {
        while (0 < n--) {
            p = p->prev;
            if (p->data == e) return p;
        }
        return NULL;
    }

    ListNode<T>* insertBefore(ListNode<T>* p, const T & e) 
    { return p->insertAsPred(e); }

    ListNode<T>* insertAfter(ListNode<T>* p, const T & e)
    { return p->insertAsSucc(e); }

    ListNode<T>* insertAsFirst(const T & e) //头插(逆序)
    { return header->insertAsSucc(e); }

    ListNode<T>* insertAsLast(const T & e)  //尾插
    { return trailer->insertAsPred(e); }

    void copyNodes(ListNode<T>* p, int n) { 
       init();
       while (n--) // Append n nodes to the empty list
       { insertAsLast(p->data); p = p->next; }
    }

    //删除p处结点，并返回其数据
    T remove(ListNode<T>* p) {
        T e = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p; size--;
        return e;
    }
};



#endif
