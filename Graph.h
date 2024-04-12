#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <fstream>
#include "Edge.h"
class Graph{
    public:
    std::vector<Edge> connectingFlights;
    std::vector<std::string> airports;
    Graph(std::string path);
};

#endif