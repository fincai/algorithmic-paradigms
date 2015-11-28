#include "MGraph.h"

int main() {
    MGraph* g = new MGraph;
    createMGraph(g);
    printMGraph(g);
    delete g;
}
