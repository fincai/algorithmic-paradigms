#include "AGraph.h"
#include <cstdlib>

VSTATUS vstatus[MAXV];
int st[MAXV], top = -1;

void DFS(AGraph* G, int u) {
    int v;
    vstatus[u] = DIS;
    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        v = e->adjvex;
        if (vstatus[v] == UNDIS) DFS(G, v);
        else if (vstatus[v] == DIS) { 
            printf("Input Graph has cycle!\n");
            exit(-1);
        }
    }
    vstatus[u] = VISITED;
    st[++top] = u;  // DFS结束时间越早的顶点在拓扑序中越靠后
}

void topoSort(AGraph* G) {
   for (int i = 0; i < G->n; i++) vstatus[i] = UNDIS;
   for (int i = 0; i < G->n; i++)
      if (vstatus[i] == UNDIS)
          DFS(G, i);
   while (top > -1)
       printf("%d ", st[top--]);
   printf("\n");
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    topoSort(g); // O(V+E)
    return 0;
}
