#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "Edge.h"
#include "Reader.h"
class Graph{
    public:
    std::vector<Edge> connectingFlights;
    std::vector<std::string> airports;
    Graph(Reader values);
};

#endif