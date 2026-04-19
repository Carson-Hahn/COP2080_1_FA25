#ifndef KRUSKALMST_H
#define KRUSKALMST_H

#include "graph.h"

// ─── UnionFind ────────────────────────────────────────────────────────────────
// Disjoint Set Union with path compression and union by rank.
// Used internally by Kruskal's to detect cycles.

class UnionFind {
public:
    explicit UnionFind(int n);
    ~UnionFind();

    int  find(int x);
    bool unite(int x, int y);  // returns false if already in same set
    bool connected(int x, int y);

private:
    int* parent;
    int* rank;
    int  n;
};

// ─── KruskalMST ───────────────────────────────────────────────────────────────
// Kruskal's MST algorithm on G_u.
// Time complexity: O(E log E).
// Requires buildUndirectedGraph() to be called first.
// Connected graph    → single MST.
// Disconnected graph → minimum spanning forest.

class KruskalMST {
public:
    static MSTResult run(const Graph& graph);
};

#endif // KRUSKALMST_H
