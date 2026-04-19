#include "graph.h"
#include "csvReader.h"
#include "dfs.h"
#include "bfs.h"
#include "primMST.h"
#include "kruskalMST.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// ─── Print helpers ────────────────────────────────────────────────────────────

static void sep(const string& title) {
    cout << "\n" << string(60, '=') << "\n";
    cout << "  " << title << "\n";
    cout << string(60, '=') << "\n";
}

static void printPath(const PathResult& pr,
                      const string& origin, const string& dest) {
    if (!pr.found) {
        cout << "  No path found: " << origin << " -> " << dest << "\n";
        return;
    }
    cout << "  Route: ";
    for (int i = 0; i < (int)pr.path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << pr.path[i];
    }
    cout << fixed << setprecision(2)
         << "  |  Distance: " << pr.distance
         << " mi  |  Cost: $"  << pr.cost << "\n";
}

static void printTraversal(const vector<string>& order, const string& label) {
    cout << "  " << label << ": ";
    for (int i = 0; i < (int)order.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << order[i];
    }
    cout << "\n";
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    Graph graph;
    if (!CSVReader::load("airports.csv", graph)) return 1;
    cout << "Loaded " << graph.getVertexCount() << " airports, "
         << graph.getEdgeCount() << " flights.\n";

    cout << "Testing Task 2...\n";
    // ── Task 2: Shortest path between two airports ────────────────────────────
    sep("TASK 2 — Shortest Path Between Two Airports");
    printPath(graph.shortestPath("ATL", "LAX"), "ATL", "LAX");
    printPath(graph.shortestPath("MIA", "ORD"), "MIA", "ORD");
    printPath(graph.shortestPath("JFK", "SFO"), "JFK", "SFO");

    cout << "Task 2 done.\n";
    // ── Task 3: Shortest paths to all airports in a state ────────────────────
    sep("TASK 3 — Shortest Paths from ATL to all FL airports");
    {
        auto results = graph.shortestPathsToState("ATL", "FL");
        if (results.empty()) cout << "  No paths found.\n";
        for (const auto& pr : results) printPath(pr, "ATL", pr.path.empty()?"?":pr.path.back());
    }
    sep("TASK 3 — Shortest Paths from ORD to all TX airports");
    {
        auto results = graph.shortestPathsToState("ORD", "TX");
        if (results.empty()) cout << "  No paths found.\n";
        for (const auto& pr : results) printPath(pr, "ORD", pr.path.empty()?"?":pr.path.back());
    }

    cout << "Task 3 done.\n";
    // ── Task 4: Shortest path with exact number of stops ─────────────────────
    sep("TASK 4 — Shortest Path with Exact Stops");
    printPath(graph.shortestPathWithStops("ATL", "LAX", 1), "ATL", "LAX (1 stop)");
    printPath(graph.shortestPathWithStops("MIA", "SEA", 2), "MIA", "SEA (2 stops)");
    printPath(graph.shortestPathWithStops("JFK", "DFW", 1), "JFK", "DFW (1 stop)");

    cout << "Task 4 done.\n";
    // ── Task 5: Connection counts ─────────────────────────────────────────────
    sep("TASK 5 — Top 10 Airports by Total Connections");
    auto conns = graph.getConnectionCounts();
    cout << left << setw(10) << "Airport"
                 << setw(10) << "Inbound"
                 << setw(10) << "Outbound"
                 << setw(10) << "Total" << "\n";
    cout << string(40, '-') << "\n";
    int limit = (int)conns.size() < 10 ? (int)conns.size() : 10;
    for (int i = 0; i < limit; ++i)
        cout << setw(10) << conns[i].code
             << setw(10) << conns[i].inbound
             << setw(10) << conns[i].outbound
             << setw(10) << conns[i].total << "\n";

    // ── Task 6 + 7 + 8: Build G_u then run Prim's and Kruskal's ─────────────
    sep("TASK 6 — Building Undirected Graph G_u");
    graph.buildUndirectedGraph();
    cout << "  G_u built. Connected: " << (graph.isConnected() ? "Yes" : "No") << "\n";

    sep("TASK 7 — Prim's MST (first 10 edges shown)");
    {
        MSTResult mst = PrimMST::run(graph);
        if (!mst.isConnected) { cout << "  Graph is disconnected.\n"; }
        else {
            int show = (int)mst.edges.size() < 10 ? (int)mst.edges.size() : 10;
            for (int i = 0; i < show; ++i)
                cout << "    " << mst.edges[i].from << " - " << mst.edges[i].to
                     << "  $" << fixed << setprecision(2) << mst.edges[i].cost << "\n";
            cout << "  ... (" << mst.edges.size() << " edges total)\n";
            cout << "  Total MST Cost: $" << fixed << setprecision(2) << mst.totalCost << "\n";
        }
    }

    sep("TASK 8 — Kruskal's MST (first 10 edges shown)");
    {
        MSTResult mst = KruskalMST::run(graph);
        if (!mst.isConnected) cout << "  (Spanning forest — graph is disconnected)\n";
        int show = (int)mst.edges.size() < 10 ? (int)mst.edges.size() : 10;
        for (int i = 0; i < show; ++i)
            cout << "    " << mst.edges[i].from << " - " << mst.edges[i].to
                 << "  $" << fixed << setprecision(2) << mst.edges[i].cost << "\n";
        cout << "  ... (" << mst.edges.size() << " edges total)\n";
        cout << "  Total MST Cost: $" << fixed << setprecision(2) << mst.totalCost << "\n";
    }

    // ── DFS examples ─────────────────────────────────────────────────────────
    sep("DFS Traversal");
    printTraversal(DFS::run(graph, "ATL"), "DFS from ATL");
    printTraversal(DFS::run(graph, "MIA"), "DFS from MIA");
    printTraversal(DFS::run(graph, "ORD"), "DFS from ORD");

    // ── BFS examples ─────────────────────────────────────────────────────────
    sep("BFS Traversal");
    printTraversal(BFS::run(graph, "ATL"), "BFS from ATL");
    printTraversal(BFS::run(graph, "MIA"), "BFS from MIA");
    printTraversal(BFS::run(graph, "ORD"), "BFS from ORD");

    return 0;
}