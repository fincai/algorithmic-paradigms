// Floyd算法思想: 顶点集和边集都固定不变, 逐渐放宽对路径类型的限制
// 定义两顶点间的k路径为: 除起点和终点外，经过的最大顶点编号为k的路径
// Induction Hypothesis: 在k < m的所有k路径中, 任意一对顶点之间的最短路径已知
// Base case: m = 0 (两顶点直接相连)
#include "MGraph.h"

int d[MAXV][MAXV];
int path[MAXV][MAXV];

void Ppath(int i, int j) {
    if (path[i][j] == -1) return;
    Ppath(i, path[i][j]);
    printf("%d, ", path[i][j]);
    Ppath(path[i][j], j);
}

void printPath(MGraph* G) {
    for (int i = 0; i < G->n; i++)
      for (int j = 0; j < G->n; j++)
        if (d[i][j] == INFI)
          printf("There is no path between %d and %d\n", i, j);
        else {
          printf("The shortest path distance from %d to %d is %d, "
                   "A shortest path: ", i, j, d[i][j]);
          printf("%d, ", i);
          Ppath(i, j);
          printf("%d\n", j);
        }
}


void Floyd(MGraph* G) {
    int i, j, k;
    //初始化(base case)
    for (i = 0; i < G->n; i++)
      for (j = 0; j < G->n; j++) {
        d[i][j] = G->E[i][j];
        path[i][j] = -1;
      }
    //归纳法 m = 1, 2, 3... n
    for (k = 0; k < G->n; k++)
      for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
          if (d[i][k] + d[k][j] < d[i][j]) {
            d[i][j] = d[i][k] + d[k][j];
            path[i][j] = k;
          }
    printPath(G);
}

int main() {
    MGraph* g = new MGraph;
    createMGraph(g);
    Floyd(g);
}
