#ifndef UNEDGE_H
#define UNEDGE_H
#include "Edge.h"
#include <iostream>
class UndirectedEdge{
    int airports[2], cost;
    public:
    UndirectedEdge(const Edge& other){
        airports[0] = other.getSrc();
        airports[1] = other.getDest();
        cost = other.getCost();
    }
    void print() const{
        std::cout << "airport 1: " << airports[0] <<
        " airport 2: " << airports[1] <<
        " cost: " << cost << std::endl;
    }
    int* getAirports() const{
        int* temp = new int[2];
        temp[0] = airports[0];
        temp[1] = airports[1];
        return temp;
    }
    int getCost() const{
        return cost;
    }
    bool operator ==(const UndirectedEdge& other)const{
        int *i = other.getAirports();
        // std::cout << "Other a1: " << i[0]
        // << "Other a2: " << i[1] << std::endl;
        return (i[0] == airports[0] && i[1] == airports[1]) || 
        (i[1] == airports[0] && i[0] == airports[1]);
    }
    bool operator <(const UndirectedEdge& other) const{
        return cost < other.cost;
    }
    bool operator >(const UndirectedEdge& other) const{
        return cost > other.cost;
    }
    bool airportsIn(int i) const{
        return i == airports[0] || i == airports[1];
    }
};

#endif