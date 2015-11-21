#include "BinNode.h"

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

public:
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNode* root() { return _root; }
    
    BinNode* insertR(BinNode* x, int & e) {
        _size++; x->insertR(e); 
        updateHeightAbove(x);  // x祖先高度可能增加, 其余结点高度必然不变
        return x->rchild;
    }

};
