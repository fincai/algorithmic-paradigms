/* 判断两个顶点之间是否存在简单路径 (除源点和终点之外不重复) */
/* 两顶点间存在简单路径 等价于 两顶点分别是同一颗DFS树的祖先和后代 */
/* 即 从源点出发DFS必能遍历到终点 */
#include "AGraph.h"


bool visited[MAXV]; 

bool exist(AGraph* G, int u, int v) {
    visited[u] = true;
    if (u == v)
        return true;
    for (ArcNode* e = G->adjlist[u].firstarc; e; e = e->nextarc) {
        int x = e->adjvex;
        if (!visited[x]) 
            if (exist(G, x, v)) 
                return true;
    }
    return false;
}

bool existSimplePath(AGraph* G, int u, int v) {
   for (int i = 0; i < G->n; i++)
       visited[i] = false;
   return exist(G, u, v);
}

int main() {
    AGraph* g = new AGraph;
    createAGraph(g);
    if (existSimplePath(g, 1, 0))
        printf("存在简单路径!\n");
    else
        printf("不存在简单路径!\n");
    return 0;
}


