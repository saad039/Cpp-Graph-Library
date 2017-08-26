//Min Chang
//Github: Minyc510

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <vector>
#include <utility>
#include <tuple>

class Graph {

private:
  std::unordered_map<std::string, Node*> nodeMap;
  bool directed = true;

public:
  Graph(); //Default: directed
  Graph(bool directed);

  ~Graph();

  //Trivial Functions
  bool addNode(int data, std::string name);
  bool addNode(std::string name); //Default data-value '1'
  void addNodes(std::vector<std::string> nodes);
  void addNodes(std::vector<std::pair<int, std::string>> nodes);
  bool addEdge(std::string fromNode, std::string toNode, int weight);
  bool addEdge(std::string fromNode, std::string toNode); //Default weight '1'
  bool deleteNode(std::string targetNode);
  bool deleteEdge(std::string fromNode, std::string toNode, int weight);
  bool deleteEdge(std::string fromNode, std::string toNode); //Default weight '1'

  //Neighbor Functions
  std::vector<std::string> neighborNames(std::string name);
  std::vector<std::pair<std::string, int>> neighborDistMin(std::string name);
  std::vector<std::pair<std::string, int>> neighborDistMax(std::string name);
  bool deleteNeighbors(std::string name);

  //Explore: What Nodes are reachable from targetNode?
  std::set<std::string> explore(std::string name);
  void exploreHelper(std::set<std::string> &visited, std::string name);
  std::vector<std::string> reachableNames(std::string name); //Returns a list of Nodes that are reachable from the target

  //Breadth First Search: Vector of pairs: <reachableNode, distance>
  std::vector<std::pair<std::string, int>> BFS(std::string name);

  //Djiktras
  std::vector<std::pair<std::string, int>> Dijktras(std::string name);

  //About Graph
  std::string getInfo(); //Temporary Function, useful for debugging.
};

#endif // GRAPH_H