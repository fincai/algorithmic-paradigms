#include <cstdio>
#include <cstdlib>
#include <ctime>

struct Node {
    int row, col;
    Node *right, *down;
    int val;
};

struct CrossList {
    Node *rhead, *chead; //指向行列头结点数组
    int m, n, k; //矩阵行数，列数，非零元素个数
};


void createCrossListMat(int **A, int m, int n, CrossList & M) {
    if (M.rhead) delete M.rhead;
    if (M.chead) delete M.chead;
    M.m = m; M.n = n;
    M.rhead = new Node[m];
    M.chead = new Node[n];
    //行列头结点数组的right和down置空
    int i, j, k = 0;
    for (i = 0; i < m; i++)
      M.rhead[i].right = M.rhead[i].down = NULL;
    for (i = 0; i < n; i++)
      M.chead[i].right = M.chead[i].down = NULL;
    Node **temp_chead = new Node*[n]; //临时列头结点的地址
    for (j = 0; j < n; j++) temp_chead[j] = &(M.chead[j]); 

    for (i = 0; i < m; i++) {
      Node *r = &(M.rhead[i]); //临时行头结点的地址
      for (j = 0; j < n; j++) {
          if (A[i][j] != 0) {
             ++k;
             Node *d = new Node;
             d->row = i; d->col = j; d->val = A[i][j];
             d->right = d->down = NULL;

             r->right = d; r = d;
             temp_chead[j]->down = d;
             temp_chead[j] = d;
          }
      }
    }
    delete temp_chead;
}

void print(CrossList & M) {
    for (int i = 0; i < M.m; i++) {
        Node *d = M.rhead[i].right;
        int prev_col = -1;
        while (d != NULL) {
          for (int j = 1; j < (d->col - prev_col); j++) //输出中间的零元素
              printf("0 ");
          printf("%d ", d->val);
          prev_col = d->col;
          d = d->right; 
        }
        for (int j = 0; j < (M.n - prev_col - 1); j++) //输出行尾的零
            printf("0 ");
        printf("\n");
    }
}

int main() {
    int i, j, r;
    int **A = new int*[10];
    for (i = 0; i < 10; i++)
      A[i] = new int[10];
    srand(time(0));
    for (i = 0; i < 10; i++)
      for (j = 0; j < 10; j++) {
          r = rand() % 10;
          A[i][j] = (r == 9 ? (rand() % 9)+1 : 0);
      }

    CrossList M;
    createCrossListMat(A, 10, 10, M);
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++)
        printf("%d ", A[i][j]);
      printf("\n");
    }
    printf("\n");
    print(M);
    return 0;
}
