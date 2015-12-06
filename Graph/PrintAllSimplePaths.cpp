/* 输出两顶点间所有的简单路径 (DFS回溯) */
#include "AGraph.h"

bool visited[MAXV];
int path[MAXV];

void printAllSimplePaths(AGraph* G, int u, int v, int d) {
    visited[u] = true;
    path[++d] = u;
    if (u == v) {
        for (int i = 0; i <= d; i++)
            printf("v%d ", path[i]);
        printf("\n");
    }
    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        int x = e->adjvex;
        if (!visited[x]) printAllSimplePaths(G, x, v, d);
    }
    visited[u] = false; //回溯
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    printAllSimplePaths(g, 1, 4, -1);
    return 0;
}
