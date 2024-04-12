#ifndef EDGE_H
#define EDGE_H
#include "string"
#include <sstream>
// CREATE EDGE CLASS FOR FINAL PROJECT
// ATTRIBUTES:
// std::string origin
// std::string destination
// float cost, distance
class Edge{
    public:
    std::string origin;
    std::string destination;
    int cost, distance;
    Edge(std::string origin="", std::string destination="", int cost=0, int distance=0){
        this->origin = origin;
        this->destination = destination;
        this->cost = cost;
        this->distance = distance;
    }
    bool lessCost(const Edge& other){
        return cost < other.cost;
    }
    bool lessDistance(const Edge& other){
        return cost < other.distance;
    }
    std::string str() const{
        std::stringstream str;
        str << origin<< ' ' << destination<< ' ' << cost<< ' ' << distance;
        return str.str();
    }
    
};

#endif