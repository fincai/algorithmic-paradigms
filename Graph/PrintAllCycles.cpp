/* 输出过某点的所有回路 (即源点和终点相同的简单路径) */
#include "AGraph.h"

bool visited[MAXV];
int path[MAXV];

void printAllCycles(AGraph* G, int u, int v, int d) {
    visited[u] = true;
    path[++d] = u;
    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        int x = e->adjvex;
        if (x == v) {
            for (int i = 0; i <= d; i++)
                printf("v%d ", path[i]);
            printf("v%d\n", v);
        }
        if (!visited[x]) printAllCycles(G, x, v, d);
    }
    visited[u] = false;
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    printAllCycles(g, 0, 0, -1);
    return 0;
}
