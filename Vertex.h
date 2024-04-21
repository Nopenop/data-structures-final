#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>
#include <iostream>
// VERTEX CLASS
/*
ATTRIBUTES:
std::string airportName
std::string cityName
std::string stateName

METHODS:
Vertex(): Creates empty vertex
Vertex(const std::string & airportName, const std::string & cityName, const
std::string & stateName): Creates Vertex with airportName, cityName, and
stateName

CREATES VERTEX USING Reader object with keys airport and Origin_city
strings(indeces 0 and 2) Vertex(const std::string & airportName,std::string
cityStateName):

*/
class Vertex {
public:
  std::string airportName;
  std::string cityName;
  std::string stateName;
  // visited
  bool visited;

  Vertex() {
    airportName = "";
    cityName = "";
    stateName = "";
    visited = false;
  }
  Vertex(const std::string &airportName, const std::string &cityName,
         const std::string &stateName) {
    this->airportName = airportName;
    this->cityName = cityName;
    this->stateName = stateName;
    visited = false;
  }
  Vertex(const std::string &airportName, const std::string &cityStateName) {
    this->airportName = airportName;
    std::string curString = "";
    for (int i = 0; i < cityStateName.size(); i++) {
      if (cityStateName[i] == ',') {
        this->cityName = curString;
        curString = "";
        i++;
      }
      if (cityStateName[i] == ' ')
        i++;
      curString += cityStateName[i];
    }
    this->stateName = curString;
    visited = false;
  }
  // == OPERATOR OVERLOAD
  // returns true if both verteces have the same values
  bool operator==(const Vertex &other) const {
    return other.airportName == airportName && other.cityName == cityName &&
           other.airportName == airportName;
  }
  // Print Function
  void print() const{
    std::cout << "Airport: "<<airportName<<
    " City: " << cityName <<
    " State: " << stateName <<std::endl;
  }
  // Kiera added get functions
  const std::string &getairportName() const { return airportName; }
  const std::string &getcityName() const { return cityName; }
  const std::string &getstateName() const { return stateName; }
  bool getVisited() const { return visited; }
  void setVisited(bool v) { visited = v; }
};

#endif