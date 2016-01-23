#include "AGraph.h"
#include <cstring>

int indegree[MAXV];

void topoSort(AGraph* G) {
    memset(indegree, 0, sizeof indegree);
    for (int i = 0; i < G->n; i++)     //计算各顶点的入度
      for (ArcNode* e = G->adjlist[i].firstarc; e; e = e->nextarc)
          ++indegree[e->adjvex];
    
    int st[MAXV], top = -1;
    for (int i = 0; i < G->n; i++)   //入度为0的顶点入栈
      if (indegree[i] == 0) 
        st[++top] = i;
    
    int u, v;
    while (top > -1) {
      u = st[top--]; 
      printf("%d ", u);
      for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        v = e->adjvex;
        if (--indegree[v] == 0)   //所有邻接顶点的入度减1
            st[++top] = v;
      }
    }
    printf("\n");
}


int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    topoSort(g);  // O(V+E) complexity
    return 0;
}

