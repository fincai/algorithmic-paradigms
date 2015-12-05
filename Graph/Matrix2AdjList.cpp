#include "MGraph.h"
#include "AGraph.h"

AGraph* Matrix2AdjList(MGraph* & g) {
    int i, j; 
    AGraph* G = new AGraph;
    G->n = g->n; G->e = g->e;
    for (i = 0; i < G->n; i++)
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < g->n; i++) {
        G->adjlist[i].data = g->V[i].data;
        for (j = (g->n)-1; j >= 0; j--) { //头插法建立边表
            if (g->E[i][j] != 0 && g->E[i][j] != INFI) {
                ArcNode* p = new ArcNode;
                p->adjvex = j; p->weight = g->E[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    delete g; g = NULL;
    return G;
}


MGraph* AdjList2Matrix(AGraph* & g) {
    int i, j;
    MGraph* G = new MGraph;
    G->n = g->n; G->e = g->e;
    
    for (i = 0; i < G->n; i++)        //初始化MGraph
        for (j = 0; j < G->n; j++)
            G->E[i][j] = (i == j) ? 0 : INFI;

    ArcNode* p;
    for (i = 0; i < G->n; i++) {
        G->V[i].data = g->adjlist[i].data;
        p = g->adjlist[i].firstarc;
        while (p) {
           G->E[i][p->adjvex] = p->weight;
           p = p->nextarc;
        }
    }
    delete g; g = NULL;
    return G;
}

int main() {
    MGraph* mg = new MGraph;
    createMGraph(mg);
    printMGraph(mg);
    AGraph* ag = Matrix2AdjList(mg);
    mg = AdjList2Matrix(ag);
    printMGraph(mg);

    return 0;
}

