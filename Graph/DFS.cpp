#include "AGraph.h"
VSTATUS status[MAXV];
ESTATUS estatus[MAXV][MAXV];
int dTime[MAXV], fTime[MAXV], parent[MAXV];
int clock = 0; 


void DFS(AGraph* G, int v) {
    status[v] = DIS;
    dTime[v] = clock++;
    printf("%c ", G->adjlist[v].data); // visit(v)
    for (ArcNode* e = G->adjlist[v].firstarc; e; e = e->nextarc) {
        int u = e->adjvex;
        switch (status[u]) {
            case UNDIS:
                parent[u] = v; estatus[v][u] = TREE; DFS(G, u);
                break;
            case DIS:
                estatus[v][u] = BACKWARD;
                break;
            case VISITED:
                estatus[v][u] = (dTime[v] < dTime[u] ? FORWARD : CROSS);
        }
    }
    status[v] = VISITED;
}


void dfs(AGraph* G, int s) {
    for (int i = 0; i < G->n; i++)
        status[i] = UNDIS;
    int v = s;
    do if (status[v] == UNDIS) DFS(G,v);
    while (s != (v = (v+1) % (G->n)));
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    dfs(g, 0);
    return 0;
}
