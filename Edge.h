#ifndef EDGE_H
#define EDGE_H
#include "string"
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
    Edge(std::string origin, std::string destination, int cost, int distance){
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
};

#endif