#include "csvReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void CSVReader::trim(string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    size_t b = s.find_last_not_of(" \t\r\n");
    s = (a == string::npos) ? "" : s.substr(a, b-a+1);
}

bool CSVReader::load(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) { cerr << "CSVReader: Cannot open '" << filename << "'\n"; return false; }

    string line;
    getline(file, line); // skip header

    int lineNum = 1;
    while (getline(file, line)) {
        ++lineNum;
        if (line.empty()) continue;
        stringstream ss(line);
        string oCode, dCode, oCity, dCity, distStr, costStr;
        getline(ss, oCode,   ',');
        getline(ss, dCode,   ',');
        getline(ss, oCity,   ',');
        getline(ss, dCity,   ',');
        getline(ss, distStr, ',');
        getline(ss, costStr, ',');

        trim(oCode); trim(dCode); trim(oCity);
        trim(dCity); trim(distStr); trim(costStr);

        if (oCode.empty() || dCode.empty()) {
            cerr << "CSVReader: Skipping malformed row at line " << lineNum << "\n";
            continue;
        }
        double dist = distStr.empty() ? 0.0 : stod(distStr);
        double cost = costStr.empty() ? 0.0 : stod(costStr);
        graph.addAirportAndEdge(oCode, oCity, dCode, dCity, dist, cost);
    }
    file.close();
    return true;
}
