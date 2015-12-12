/* 把顶点集划分成D和V-D两个子集, */ 
/* 每次选择连通两个集合的最小边加入MST (最小边在V-D中的邻接顶点k加入D) */
#include "MGraph.h"

int lowcostTo[MAXV]; //记录当前D连通V-D中每个顶点的最小权值 0元素表示顶点i已加入D
int closestTo[MAXV]; //记录当前最小边在D中的顶点

void Prim(MGraph* g, int v) {
    int min, i, j, k;
    for (i = 0; i < g->n; i++) {
        lowcostTo[i] = g->E[v][i]; 
        closestTo[i] = v;
    }
    
    for (i = 1; i < g->n; i++) {  // n-1次循环, 把剩余n-1个顶点加入D
        min = INFI;                 //找出连通两顶点集的最小边权值和邻接结点k
        for (j = 0; j < g->n; j++)
            if (lowcostTo[j] && lowcostTo[j] < min) {
                min = lowcostTo[j];
                k = j;
            }
        printf("边(%d, %d): %d\n", closestTo[k], k, min); //输出MST的边
        
        lowcostTo[k] = 0;  //顶点k加入D 
        for (j = 0; j < g->n; j++)
            if (g->E[k][j] && g->E[k][j] < lowcostTo[j]) {
                lowcostTo[j] = g->E[k][j];
                closestTo[j] = k;
            }
    }
}


int main() {
    MGraph* g = new MGraph;
    createMGraph(g);
    printMGraph(g);
    Prim(g, 0);
    return 0;
}
