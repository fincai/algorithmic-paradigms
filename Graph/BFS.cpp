#include "AGraph.h"

VSTATUS status[MAXV];

void BFS(AGraph* G, int s) {
    int queue[MAXV]; int front = 0, rear = 0;
    rear = (rear+1) % MAXV; queue[rear] = s;
    while (front != rear) {
        front = (front+1) % MAXV; int v = queue[front]; // dequeue
        printf("%c ", G->adjlist[v].data); // visit
        status[v] = VISITED;
        for (ArcNode* e = G->adjlist[v].firstarc; e; e = e->nextarc) {
            int u = e->adjvex;
            if (status[u] == UNDIS) {
                status[u] = DIS;
                rear = (rear+1) % MAXV; queue[rear] = u; //enqueue
            }
        }
    }
}

void bfs(AGraph* G, int s) {
    for (int i = 0; i < G->n; i++)
        status[i] = UNDIS;
    int v = s;
    do if (status[v] == UNDIS) BFS(G, v);
    while (s != (v = (v+1) % (G->n)));
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    bfs(g, 0);
    printf("\n");
    return 0;
}
