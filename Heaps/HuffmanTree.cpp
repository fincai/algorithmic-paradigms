#include "BinaryHeap.h"
#include <cstdio>
#define N 8
struct HTNode {
  char data;
  float weight;
  int lchild, rchild;
  HTNode() { lchild = rchild = -1; }
  bool operator<(const HTNode & rhs) const
  { return weight < rhs.weight; }
};
//由二叉树性质，叶结点总是比2度结点多1个
//构造出的Huffman树是满二叉树，没有1度结点.故总结点数为N + N2 = 2N - 1 
HTNode node[2*N-1];
int code[N-1];

void constructHuffmanTree(char d[ ], float w[ ]) {
    int i, j = 0;
    for (i = 0; i < N; i++) {
      node[i].data = d[i];
      node[i].weight = w[i];
    }
    BinaryHeap<HTNode> h(node, N);
    for (i = 0; i < N-1; i++) { // 构造Huffman树需要合并的次数等于2度结点数(N-1)
      node[j] = h.extractMin(); 
      node[j+1] = h.extractMin();
      node[j+2].lchild = j;
      node[j+2].rchild = j+1;
      node[j+2].weight = node[j].weight + node[j+1].weight;
      h.insert(node[j+2]);
      j += 2;
    } // node[2*N-2]就是HuffmanTree的root
}

void print(int x, int len, int bit) {
    if (x != -1) {
      if (x != (2*N - 2)) code[++len] = bit;
      print(node[x].lchild, len, 0);
      print(node[x].rchild, len, 1);
      if (node[x].lchild == -1 && node[x].rchild == -1) {
          printf("%c :", node[x].data);
          for (int i = 0; i <= len; i++)
            printf("%d", code[i]);
          printf("\n");
      }
    }
}

void printOptimalCode() 
{ print(2*N-2, -1, 0); }

int main() {
    char data[N] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    float weight[N] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.10};
    constructHuffmanTree(data, weight);
    printOptimalCode();
    return 0;
}
