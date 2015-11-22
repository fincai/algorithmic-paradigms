#pragma once
template <typename T>
struct BinNode {
    BinNode(const T & e, BinNode<T>* p=0): data(e), parent(p) { }
    BinNode<T>* parent, lchild, rchild;
    T data; 
    int height;
    
    int size() {
        int cnt = 1;
        if (lchild) cnt += lchild->size();
        if (rchild) cnt += rchild->size();
        return cnt;
    }

    BinNode<T>* insertL(const T & e) 
    { return lchild = new BinNode(e, this); }

    BinNode<T>* insertR(const T & e)
    { return rchild = new BinNode(e, this); }

    
};
