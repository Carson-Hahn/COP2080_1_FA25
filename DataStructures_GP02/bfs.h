#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <vector>
#include <string>

// Breadth-First Search on the directed graph.
// Uses the custom Queue (SLL). No STL queue.
class BFS {
public:
    static std::vector<std::string> run(const Graph& graph,
                                        const std::string& startCode);
};

#endif // BFS_H
