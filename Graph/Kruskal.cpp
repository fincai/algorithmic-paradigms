/* 初始为顶点集V, 每次选择不产生环的最小边加入MST的边集 */
/* Kruskal算法适用于求稀疏图的MST */
#include "AGraph.h"
#include <cstring> // memset

struct Edge {
    int u, v, w;
};

Edge E[MAXV];
int s[MAXV]; //并查集

int find(int x) 
{ return s[x] < 0 ? x : s[x] = find(s[x]); }

void Union(int r1, int r2) { // Union by height 根结点为负数，其绝对值代表高度
    if (s[r1] < s[r2]) s[r2] = r1;
    else {
        if (s[r1] == s[r2]) --s[r2];
        s[r1] = r2;
    }
}

void sort(Edge E[ ], int n) {  // insertSort
    int i, j; Edge tmp;
    for (i = 0; i < n; i++)
        printf("%d\n", E[i].w);
    for (i = 1; i < n; i++) {
        tmp = E[i];
        j = i - 1;
        while (j >= 0 && E[j].w > tmp.w) { 
            E[j+1] = E[j]; 
            j--; 
        }
        E[j+1] = tmp;
    }
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d\n", E[i].w);
}

void Kruskal(AGraph* g) {
    int i, j, r1, r2;
    for (i = 0, j = 0; i < g->n; i++) 
       for (ArcNode* e = g->adjlist[i].firstarc; e; e = e->nextarc)
       { E[j].u = i; E[j].v = e->adjvex; E[j++].w = e->weight; }
    memset(s, -1, sizeof s);  //初始化并查集
    sort(E, g->e);
    
    for (i = 0; i < g->e; i++) {
        r1 = find(E[i].u); r2 = find(E[i].v);
        if (r1 != r2) {   //边的两顶点不属于同一连通分支(等价类), 加入边后不会产生环
           Union(r1, r2);  //合并成同一个连通分支
           printf("边(%d, %d): %d\n", E[i].u, E[i].v, E[i].w);
        }
    }
}


int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    Kruskal(g);
    return 0;
}
