#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_DIJKSTRA_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_DIJKSTRA_H
#include "Node.h"
#include "Graph.h"
#include <list>
#include <vector>

using namespace std;

class Dijkstra {
private:
    list<Node> returnedPath;
    vector<pair<Node, int>> connectedNodes;
public:
    list<Node> dijkstraSearch(Graph*, Node, Node);
    double getDistance(Node, Node);
    double getCost(double, Node, Node);
};

#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_DIJKSTRA_H
