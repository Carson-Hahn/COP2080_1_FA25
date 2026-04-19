#ifndef PRIMMST_H
#define PRIMMST_H

#include "graph.h"
#include "minHeap.h"

// Prim's MST algorithm on G_u.
// Time complexity: O((V + E) log V).
// Requires buildUndirectedGraph() to be called first.
// Connected graph   → single MST.
// Disconnected graph → returns empty result with isConnected=false.
class PrimMST {
public:
    static MSTResult run(const Graph& graph);
};

#endif // PRIMMST_H
