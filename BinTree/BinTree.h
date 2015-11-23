#ifndef _BINTREE_
#define _BINTREE_ 
#include "BinNode.h"
#include "Stack.h"
#include "Queue.h"

#define height(node) (node ? node->height : -1)

template <typename T>
class BinTree {
    int _size;
    BinNode<T>* _root;
    int updateHeight(BinNode<T>* x) {  //更新结点x的高度
        return x->height = 1 + 
            max(height(x->lchild), height(x->rchild)); 
    }

    int updateHeightAbove(BinNode<T>* x) {  //更新结点x及其历代祖先的高度
        while (x) {
            updateHeight(x);
            x = x->parent;
        }
    }

    template <typename Func>
    void visitAlongLeftChain(BinNode<T>* x, Func visit, Stack<BinNode<T>*> & S) {
        while (x) {
            visit(x->data);
            if (x->rchild) S.push(x->rchild);
            x = x->lchild;
        }
    }

    
    template <typename Func>
    void goAlongLeftChain(BinNode<T>* x, Stack<BinNode<T>*> & S) {
        while (x) { S.push(x); x = x->lchild; }
    }

    
    template <typename Func>
    void goToLeftMostLeaf(Stack<BinNode<T>*> & S) {
        while (BinNode<T>* x = S.top()) 
            if (x->lchild) {
                if (x->rchild) S.push(x->rchild); //右结点先进栈
                else S.push(x->lchild);
            } else  S.push(x->rchild); //叶子结点则空结点入栈, 循环结束
        S.pop(); //弹出栈顶的空结点
    }

public:
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNode<T>* root() { return _root; }
    
    BinNode<T>* insertR(BinNode<T>* x, int & e) {
        _size++; x->insertR(e); 
        updateHeightAbove(x);  // x祖先高度可能增加, 其余结点高度必然不变
        return x->rchild;
    }

    template <typename Func>
    void travPre(BinNode<T>* x, Func visit) {  //前序遍历(根左右) 的递归实现 
        if (!x) return;
        visit(x->data);
        travPre(x->lchild, visit);
        travPre(x->rchild, visit);
    }

    template <typename Func>
    void travPre_I1(BinNode<T>* x, Func visit) {  //前序遍历的迭代实现
        Stack<BinNode<T>*> S; // 辅助栈 
        if (x) S.push(x);  // 根结点入栈
        while (!S.empty()) {
            x = S.pop(); visit(x->data);
            if (x->rchild) S.push(x->rchild);
            if (x->lchild) S.push(x->lchild); //左结点要先访问，所以后进(先出)
        }
    }

    template <typename Func>
    void travPre_I2(BinNode<T>* x, Func visit) {  //前序遍历迭代版2: 先自顶向下访问左侧链, 再自底向上访问用栈保存的右结点
        Stack<BinNode<T>*> S;
        while (1) {
            visitAlongLeftChain(x, visit, S);
            if (S.empty()) break;
            x = S.pop();
        }
    }

    template <typename Func>
    void travIn(BinNode<T>* x, Func visit) {  //中序遍历的递归实现
        if (!x) return;
        if (x->lchild) travIn(x->lchild, visit);
        visit(x->data);
        if (x->rchild) travIn(x->rchild, visit);
    }

    
    template <typename Func>
    void travIn_I1(BinNode<T>* x, Func visit) {  //中序遍历的迭代实现
        Stack<BinNode<T>*> S;
        while (1) {
            goAlongLeftChain(x, S);
            if (S.empty()) break;
            x = S.pop();
            visit(x->data);
            x = x->rchild;
        }
    }

    
    template <typename Func>
    void travPost(BinNode<T>* x, Func visit) {  //后序遍历的递归实现
        if (!x) return;
        if (x->lchild) travPost(x->lchild);
        if (x->rchild) travPost(x->rchild);
        visit(x->data);
    }

    
    template <typename Func>
    void travPost_I(BinNode<T>* x, Func visit) {  //后序遍历的迭代实现
        Stack<BinNode<T>*> S;
        S.push(x);
        while (!S.empty()) {
            if (S.top() != x->parent) //栈顶结点不是当前结点之父(必为右兄)
                goToLeftMostLeaf(S);
            x = S.pop();  //没有右兄则直接访问中间的父结点
            visit(x->data);
        }
    }
    

    
    template <typename Func>
    void travLevel(BinNode<T>* x, Func visit) {  // 二叉树的层次遍历 (队列实现)
        Queue<BinNode<T>*> Q;
        Q.enqueue(x);
        while (!Q.empty()) {
            x = Q.dequeue();
            visit(x->data);
            if (x->lchild) Q.enqueue(x->lchild);
            if (x->rchild) Q.enqueue(x->rchild);
        }
    }


};
#endif
