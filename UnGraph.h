#ifndef UNGRAPH_H
#define UNGRAPH_H
#include "Graph.h"
#include "UnEdge.h"
#include "Vertex.h"
#include <vector>
#include "Queue.h"
class UndirectedGraph{
    std::vector<UndirectedEdge> flights;
    std::vector<Vertex> airports;
    void insert(const Edge& other){
        UndirectedEdge toInsert(other);
        for(int i = 0; i < flights.size(); i++){
            if(toInsert == flights[i]){
                if(toInsert < flights[i]) flights[i] = toInsert;
                return;
            }
        }
        flights.push_back(toInsert);
    }
    void clearVisited() {
        for(Vertex& e: airports){
            e.setVisited(false);
        }
    }
    void testVisited()const{
        for(const Vertex& e: airports){
            if(e.getVisited()) std::cout << "Uh oh" << std::endl;
        }
    }
    public:
    UndirectedGraph(const Graph& other){
        airports = other.airports;
        for(int i = 0; i < other.flights.size(); i++){
            insert(other.flights[i]);
        }
    }
    std::vector<int> adjFlights(int airportIndex){
        std::vector<int> retvet;
        for(int i = 0; i < flights.size(); i++){
            if(flights[i].airportsIn(airportIndex)){
                retvet.push_back(i);
            }
        }
        return retvet;
    }
    std::vector<int> adjAirports(int airportIndex){
        std::vector<int> cur_flights = adjFlights(airportIndex);
        std::vector<int> retvet;
        for(int i = 0; i < cur_flights.size(); i++){
            if(flights[cur_flights[i]].getAirports()[0] == airportIndex) retvet.push_back(flights[cur_flights[i]].getAirports()[1]);
            else retvet.push_back(flights[cur_flights[i]].getAirports()[0]);
        }
        return retvet;
    }
    bool isConnected(){
        clearVisited();
        int counter = 0;
        Queue<int> cur_airports;
        int start = 5;
        cur_airports.pushBack(start);
        while(!cur_airports.empty()){
            if(!airports[cur_airports.top()].getVisited()){
                std::vector<int> adjacentAirports = adjAirports(cur_airports.top());
                for(int i: adjacentAirports){
                    cur_airports.pushBack(i);
                }
                counter ++;
                airports[cur_airports.top()].setVisited(true);
            }
            cur_airports.pop();
        }
        clearVisited();
        std::cout <<"Airports Visited: "<< counter << std::endl;
        return counter == airports.size();
    }
    void printFlights() const{
        for(int i = 0; i < flights.size(); i++){
            flights[i].print();
        }
    }
    void printNumFlights() const{
        std::cout <<"Num of flights UnGraph: "<< flights.size() << std::endl;
    }
    void printAirports() const{
        for(int i = 0; i< airports.size(); i++){
            airports[i].print();
        }
    }
    void printNumAirports() const{
        std::cout <<"Num of Airports UnGraph: "<< airports.size() << std::endl;
    }
    void printAirportIndex(int i) const{
        airports[i].print();
    }
    


    
};

#endif