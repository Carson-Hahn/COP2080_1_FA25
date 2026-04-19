#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <vector>
#include <string>

// Depth-First Search on the directed graph.
// Uses the custom Stack (SLL). No STL stack.
class DFS {
public:
    static std::vector<std::string> run(const Graph& graph,
                                        const std::string& startCode);
};

#endif // DFS_H
