/* 找到两顶点间任意一条简单路径并打印*/
#include "AGraph.h"

bool visited[MAXV];

int path[MAXV]; //记录路径上的结点，下标为源点到该结点的路径长度(对应递归深度)

void printASimplePath(AGraph* G, int u, int v, int d) {
    visited[u] = true;
    path[++d] = u;
    if (u == v) {
        for (int i = 0; i <= d; i++)
            printf("v%d ", path[i]);
        printf("\n");
    }

    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        int x = e->adjvex;
        if (!visited[x]) 
            printASimplePath(G, x, v, d);
    }
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    printASimplePath(g, 1, 4, -1);
    return 0;
}


