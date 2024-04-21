#include "Edge.h"
#include "Reader.h"
#include "UnEdge.h"
#include "UnGraph.h"
#include "Vertex.h"
#include "Graph.h"
#include <fstream>
int main() {
  Reader r("airports.csv");
  r.printKeys();
  Graph g(r);
  // g.printAirports();
  // g.printFlights();
  UndirectedGraph u(g);
  u.printAirports();
  u.printNumAirports();
  std::vector<int> j = u.adjAirports(5);
  for(int i: j){
    // std::cout << "Airport Index: "<<i << std::endl;
    // u.printAirportIndex(i);
  }
  if(u.isConnected()) std::cout << "is connected" << std::endl;
  else std::cout << "not connected" << std::endl;

}