#ifndef CSVREADER_H
#define CSVREADER_H

#include "graph.h"
#include <string>

// Reads airports.csv and populates a Graph.
// Expected columns: Origin_airport, Destination_airport,
//                   Origin_city, Destination_city, Distance, Cost
class CSVReader {
public:
    static bool load(const std::string& filename, Graph& graph);
private:
    static void trim(std::string& s);
};

#endif // CSVREADER_H
