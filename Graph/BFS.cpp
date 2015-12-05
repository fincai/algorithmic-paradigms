#include "AGraph.h"

VSTATUS status[MAXV];

void BFS(AGraph* G, int s) {
    int queue[MAXV]; int front = 0, rear = 0;
    rear = (rear+1) % MAXV; queue[rear] = s;
    while (front != rear) {
        front = (front+1) % MAXV; int v = queue[front]; // dequeue
        printf("%d ", G->adjlist[v].data); // visit
        status[v] = VISITED;
        for (ArcNode* u = G->adjlist[v].firstarc; u; u = u->nextarc) {
            if (status[u->adjvex] == UNDIS) {
                status[u->adjvex] = DIS;
                rear = (rear + 1) % MAXV; queue[rear] = u->adjvex; //enqueue
            }
        }
    }
}

void bfs(AGraph* G, int s) {
    for (int v = 0; v < G->n; v++)
        if (status[v] == UNDIS)
            BFS(G, v);
}
int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    BFS(g, 0);
    return 0;
}
