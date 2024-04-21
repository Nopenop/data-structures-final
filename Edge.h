#ifndef EDGE_H
#define EDGE_H
#include <string>

class Edge {
public:
  // constructor
  Edge(int s = 0, int dest = 0, int c = 0, int dist = 0)
      : src(s), dest(dest), cost(c), distance(dist) {}

  // EDGE CONSTRUCTOR USING STRINGS FOR THE COST AND DISTANCE
  /*
  Use this for inputting directly from Reader object when creating graph from
  reader object
  */
  Edge(int src, int dest, std::string distance, std::string cost) {
    this->src = src;
    this->dest = dest;
    this->cost = std::stoi(cost);
    this->distance = std::stoi(distance);
  }
  // GETFUNCTIONS FOR OBJECT ATTRIBUTES
  int getSrc() const { return src; }
  int getDest() const { return dest; }
  int getCost() const { return cost; }
  int getDistance() const { return distance; }
  // COST COMPARISON FUNCTION
  /*
  returns true if this edge has a smaller cost
  PARAMETERS: const Edge& other
  RETURNS: bool
  */
  bool hasLowerCost(const Edge &other) { return this->cost < other.cost; }
  // DISTANCE COMPARISON FUNCTION
  /*
  returns true if this edge has a smaller distance
  PARAMETERS: const Edge& other
  RETURNS: bool
  */
  bool hasLowerDistance(const Edge &other) {
    return this->distance < other.distance;
  }
  // == OPERATOR OVERLOAD
  // returns whether two edges have same
  bool operator==(const Edge &other) const {
    return other.getSrc() == src && other.getDest() == dest &&
           other.getCost() == cost && other.getDistance() == distance;
  }

  int src;      // source index
  int dest;     // destination index
  int cost;     // cost weight
  int distance; // distance weight
};

#endif