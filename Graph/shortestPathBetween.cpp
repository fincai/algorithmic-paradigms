/* 输出两顶点间最短的逆路径 (BFS) */
#include "AGraph.h"

bool visited[MAXV];
int parent[MAXV];

void printReversePath(int v) {
    while (v != -1) {
        printf("v%d ", v);
        v = parent[v];
    }
    printf("\n");
}

void shortestReversePath(AGraph* G, int u, int v) {
    int queue[MAXV]; int front = 0, rear = 0;
    rear = (rear+1) % MAXV; queue[rear] = u; parent[u] = -1;
    while (front != rear) {
        front = (front+1) % MAXV;
        u = queue[front]; 
        visited[u] = true; 
        if (u == v) { printReversePath(v); break; }
        for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
            int x = e->adjvex;
            if (!visited[x]) {
                parent[x] = u;
                rear = (rear+1) % MAXV;
                queue[rear] = x;
            }
        }
    }
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    shortestReversePath(g, 0, 7);
    return 0;
}
