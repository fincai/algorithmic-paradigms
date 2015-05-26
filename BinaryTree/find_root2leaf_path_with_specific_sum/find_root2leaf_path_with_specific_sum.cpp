#include <iostream>
using namespace std;

struct Node {
    Node(int x): data(x), left(nullptr), right(nullptr) { }
    int data;
    Node* left;
    Node* right;
};

void make_empty(Node* & t) {
    if (t != nullptr) {
        make_empty(t->left);
        make_empty(t->right);
        delete t;        
    }
    t = nullptr;
}


bool is_leaf(Node* node) {
    return !node->left && !node->right;
}

bool has_path_sum(Node* root, int sum) {
    if (!root) return false;
    if (is_leaf(root) && (sum - root->data) == 0)
        return true;
    return has_path_sum(root->left, sum - root->data) 
        || has_path_sum(root->right, sum - root->data);
}

int main() {
    /* Constructed binary tree is
     *             10
     *            /   \
     *          8      2
     *         /  \    /
     *        3     5  2
     *        
     *  21 = 10 + 8 + 3
     *  23 = 10 + 8 + 5
     *  14 = 10 + 2 + 2
     */
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    cout << (has_path_sum(root, 21) ? "true":"false") << endl;
    cout << (has_path_sum(root, 23) ? "true":"false") << endl;
    cout << (has_path_sum(root, 14) ? "true":"false") << endl;
    cout << (has_path_sum(root, 12) ? "true":"false") << endl;
    
    make_empty(root);

    return 0;
}


