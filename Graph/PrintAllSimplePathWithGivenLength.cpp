/* 输出两顶点间所有给定长度的简单路径 (DFS回溯, 长度为k时再输出即可) */
#include "AGraph.h"

bool visited[MAXV];
int path[MAXV];

void printAllKSimplePaths(AGraph* G, int u, int v, int k, int d) {
    visited[u] = true;
    path[++d] = u;
    if (u == v && d == k) {
        for (int i = 0; i <= d; i++)
            printf("v%d ", path[i]);
        printf("\n");
    }
    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        int x = e->adjvex;
        if (!visited[x]) printAllKSimplePaths(G, x, v, k, d);
    }
    visited[u] = false; //回溯
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    printAllKSimplePaths(g, 1, 0, 3, -1);
    return 0;
}
