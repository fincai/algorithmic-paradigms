struct BinNode {
    BinNode(int & e, BinNode* p=NULL): data(e), parent(p) { }
    BinNode* parent, lchild, rchild;
    int data; 
    int height;
    
    int size() {
        int cnt = 1;
        if (lchild) cnt += lchild->size();
        if (rchild) cnt += rchild->size();
        return cnt;
    }

    BinNode* insertL(int & e) 
    { return lchild = new BinNode(e, this); }

    BinNode* insertR(int & r)
    { return rchild = new BinNode(e, this); }

    BinNode* succ(); //当前节点的直接后继(中序遍历意义下)
    void travLevel(BinNode* t);
    void travPre(BinNode* t);
    void travIn(BinNode* t);
    void travPost(BinNode* t);
    
};
