#ifndef _AGRAPH_
#define _AGRAPH_
#include <cstdio>
#ifndef _VINFO_
#define _VINFO_

#define MAXV 5
#define INFI 9999

enum VSTATUS {DIS, UNDIS, VISITED};
enum ESTATUS {TREE, BACKWARD, FORWARD, CROSS};

#endif


struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode* nextarc;
};

struct VNode {
    char data;
    struct ArcNode* firstarc;
};

struct AGraph {
    int n, e;
    VNode adjlist[MAXV];
    ~AGraph() {
        ArcNode *p;
        for (int i = 0; i < n; i++) {
            p = adjlist[i].firstarc;
            while (p) {
                ArcNode *d = p; 
                p = p->nextarc;
                delete d;
            }
        }
    }
};

void createAGraph(AGraph* G) {
    int i, j, k, w;
    printf("请输入顶点数和边数:");
    scanf("%d %d", &(G->n), &(G->e));
    printf("请输入各结点信息:\n");
    for (i = 0; i < G->n; i++)
        scanf(" %c", &(G->adjlist[i].data));
       //初始化各表头结点
    for (i = 0; i < G->n; i++)
        G->adjlist[i].firstarc = NULL;
    printf("请输入i, j, w:\n");
    for (k = 0; k < G->e; k++) {
        scanf(" %d %d %d", &i, &j, &w);
        ArcNode* p = new ArcNode;
        p->adjvex = j; p->weight = w;
        p->nextarc = G->adjlist[i].firstarc;
        G->adjlist[i].firstarc = p;
    }
}
#endif
