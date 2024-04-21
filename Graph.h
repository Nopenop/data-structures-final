#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include "Reader.h"
#include "Vertex.h"

class Graph {
public:
  std::vector<Edge> flights;
  std::vector<Vertex> airports;
  Graph(const Reader &r) {
    try {
      for (int i = 0; i < r.columns[0].size(); i++) {
        Vertex src = Vertex(r.columns[0][i], r.columns[2][i]);
        Vertex dest = Vertex(r.columns[1][i], r.columns[3][i]);
        insertAirport(src);
        insertAirport(dest);
        int srcIndex = airportIndex(src.airportName);
        int destIndex = airportIndex(dest.airportName);
        if (srcIndex == -1 || destIndex == -1)
          throw std::string("Error: Graph: Graph: airport does not exist");
        insertFlight(
            Edge(srcIndex, destIndex, r.columns[4][i], r.columns[5][i]));
      }
    } catch (std::string e) {
      std::cout << e << std::endl;
    }
  }
  // INSERT FLIGHT INTO FLIGHTS VECTOR(EDGES)
  /*
  Checks if the flight has already been recorded
  If it has, flight is not put in
  */
  void insertFlight(const Edge &flight) {
    for (const Edge &e : flights) {
      if (e == flight) {
        return;
      }
    }
    flights.push_back(flight);
  }
  // INSERT AIRPORT INTO AIRPORTS VECTOR(VERTEX)
  /*
  Checks if airport has already been inserted into airports.
  If it has, airport is not put in.
  */
  void insertAirport(const Vertex &airport) {
    for (const Vertex &e : airports) {
      if (e == airport) {
        return;
      }
    }
    airports.push_back(airport);
  }
  // FINDS ONE AIRPORT'S INDEX ON AIRPORTNAME
  /*
  PARAMETERS: const std::string& airportName
  RETURNS: if found - index of airport, otherwise -1
  */
  int airportIndex(const std::string &airportName) {
    for (int i = 0; i < airports.size(); i++) {
      if (airports[i].airportName == airportName)
        return i;
    }
    // No airport found
    return -1;
  }
  // RETURNS INT VECTOR CONTAINI\NG THE AIRPORT INDECES FROM A GIVEN STATE
  /*
  PARAMETERS: const std::string& stateName
  RETURNS: std::vector<int> containing all indeces with statename(empty if none
  exists)
  */
  std::vector<int> airportsInState(const std::string &stateName) {
    std::vector<int> retVector;
    for (int i = 0; i < airports.size(); i++) {
      if (airports[i].stateName == stateName)
        retVector.push_back(i);
    }
    return retVector;
  }

  // RETURNS INT VECTOR CONTAINING ALL ADJACENT AIRPORTS FROM AIRPORT
  /*
  PARAMETERS: int airportIndex
  RETURNS: std::vector<int> containing all adjecent airports from airportIndex
  */
  std::vector<int> adjAirportsFrom(int airportIndex) {
    std::vector<int> retVector;
    for (int i = 0; i < flights.size(); i++) {
      if (flights[i].getSrc() == airportIndex)
        retVector.push_back(flights[i].getDest());
    }
    return retVector;
  }
  // RETURNS INT VECTOR CONTAINING ALL ADJACENT AIRPORTS TO AIRPORT
  /*
  PARAMETERS: int airportIndex
  RETURNS: std::vector<int> containing all adjecent airports to airportIndex
  */
  std::vector<int> adjAirportsTo(int airportIndex) {
    std::vector<int> retVector;
    for (int i = 0; i < flights.size(); i++) {
      if (flights[i].getDest() == airportIndex)
        retVector.push_back(flights[i].getSrc());
    }
    return retVector;
  }
  // RETURNS INT VECTOR CONTAINING ALL ADJACENT FLIGHTS FROM AIRPORT
  /*
  PARAMETERS: int airportIndex
  RETURNS: std::vector<int> containing all adjecent flights from airportIndex
  */
  std::vector<int> adjFlightsFrom(int airportIndex) {
    std::vector<int> retVector;
    for (int i = 0; i < flights.size(); i++) {
      if (flights[i].getSrc() == airportIndex)
        retVector.push_back(i);
    }
    return retVector;
  }
  // RETURNS INT VECTOR CONTAINING ALL ADJACENT FLIGHTS TO AIRPORT
  /*
  PARAMETERS: int airportIndex
  RETURNS: std::vector<int> containing all adjecent flights to airportIndex
  */
  std::vector<int> adjFlightsTo(int airportIndex) {
    std::vector<int> retVector;
    for (int i = 0; i < flights.size(); i++) {
      if (flights[i].getDest() == airportIndex)
        retVector.push_back(i);
    }
    return retVector;
  }
  // PRINTS ALL AIRPORT'S AIRPORTNAME, CITYNAME, STATENAME
  void printAirports() const {
    std::cout << airports.size() << std::endl;
    for (const Vertex &e : airports) {
      std::cout << "Airport: " << e.airportName << " City: " << e.cityName
                << " State: " << e.stateName << std::endl;
    }
  }
  // PRINTS ALL FLIGHTS'S SOURCE, DESTINATION, DISTANCE, COST
  void printFlights() const {
    std::cout << flights.size() << std::endl;
    for (const Edge &e : flights) {
      std::cout << "Src: " << e.getSrc() << " Dest: " << e.getDest()
                << " distance: " << e.getDistance() << " cost: " << e.getCost()
                << std::endl;
    }
  }
  void printNumFlights() const{
    std::cout << "Number of flights Graph: " << flights.size() << std::endl;
  }
};

#endif