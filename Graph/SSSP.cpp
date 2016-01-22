#include "MGraph.h"

int s[MAXV], d[MAXV], path[MAXV];

void printPath(MGraph*, int);

void Dijkstra(MGraph* G, int v) {
    int min_d, u, i, j;
    for (i = 0; i < G->n; i++) {
        s[i] = 0;
        d[i] = G->E[v][i];
        path[i] = (d[i] < INFI) ? v : -1;
    }
    s[v] = 1;
    
    for (i = 0; i < G->n; i++) {
        min_d = INFI;
        for (j = 0; j < G->n; j++)
            if (s[j] == 0 && d[j] < min_d) 
            { min_d = d[j];  u = j; }
        s[u] = 1;

        for (j = 0; j < G->n; j++) {
            if (d[u] + G->E[u][j] < d[j]) {
                d[j] = d[u] + G->E[u][j];
                path[j] = u;
            }
        }
    }

    printPath(G, v);
}

void Ppath(int v, int i) {
    if (path[i] == v) return;
    Ppath(v, path[i]);
    printf("%d, ", i);
}

void printPath(MGraph* G, int v) {
    for (int i = 0; i < G->n; i++) {
        if (s[i] == 1) {
           printf("Shortest path distance from %d to %d is %d, \tthe shortest path: ", v, i, d[i]);
           printf("%d, ", v);
           Ppath(v, i);
           printf("%d\n", i);
        }
    }
}

int main() {
    MGraph* g = new MGraph;
    createMGraph(g);
    Dijkstra(g, 0);
    return 0;
}
