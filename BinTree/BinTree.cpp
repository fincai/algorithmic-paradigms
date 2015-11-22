#include "BinNode.h"
#include "Stack.h"

#define height(node) (node ? node->height : -1)

class BinTree {
    int _size;
    BinNode* _root;
    int updateHeight(BinNode* x) {  //更新结点x的高度
        return x->height = 1 + 
            max(height(x->lchild), height(x->rchild)); 
    }

    int updateHeightAbove(BinNode* x) {  //更新结点x及其历代祖先的高度
        while (x) {
            updateHeight(x);
            x = x->parent;
        }
    }

    template <typename Func>
    void visitAlongLeftChain(BinNode* x, Func visit, Stack<BinNode*> & S) {
        while (x) {
            visit(x->data);
            if (x->rchild) S.push(x->rchild);
            x = x->lchild;
        }
    }

    
    template <typename Func>
    void goAlongLeftChain(BinNode* x, Stack<BinNode*> & S) {
        while (x) { S.push(x); x = x->lchild; }
    }

public:
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNode* root() { return _root; }
    
    BinNode* insertR(BinNode* x, int & e) {
        _size++; x->insertR(e); 
        updateHeightAbove(x);  // x祖先高度可能增加, 其余结点高度必然不变
        return x->rchild;
    }

    template <typename Func>
    void travPre(BinNode* x, Func visit) {  //前序遍历(根左右) 的递归实现 
        if (!x) return;
        visit(x->data);
        travPre(x->lchild, visit);
        travPre(x->rchild, visit);
    }

    template <typename Func>
    void travPre_I1(BinNode* x, Func visit) {  //前序遍历的迭代实现
        Stack<BinNode*> S; // 辅助栈 
        if (x) S.push(x);  // 根结点入栈
        while (!S.empty()) {
            x = S.pop(); visit(x->data);
            if (x->rchild) S.push(x->rchild);
            if (x->lchild) S.push(x->lchild); //左结点要先访问，所以后进(先出)
        }
    }

    template <typename Func>
    void travPre_I2(BinNode* x, Func visit) {  //前序遍历迭代版2: 先自顶向下访问左侧链, 再自底向上访问用栈保存的右结点
        Stack<BinNode*> S;
        while (1) {
            visitAlongLeftChain(x, visit, S);
            if (S.empty()) break;
            x = S.pop();
        }
    }

    template <typename Func>
    void travIn(BinNode* x, Func visit) {  //中序遍历的递归实现
        if (!x) return;
        if (x->lchild) travIn(l->lchild, visit);
        visit(x->data);
        if (x->rchild) travIn(r->rchild, visit);
    }

    
    template <typename Func>
    void travIn_I1(BinNode* x, Func visit) {
        Stack<BinNode*> S;
        while (1) {
            goAlongLeftChain(x, S);
            if (S.empty()) break;
            x = S.pop();
            visit(x->data);
            x = x->rchild;
        }
    }


    

    

};
