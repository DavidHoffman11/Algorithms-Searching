#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_ASTAR_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_ASTAR_H
#include "Node.h"
#include "Graph.h"
#include <iostream>
#include <list>

using namespace std;

class AStar {
private:
    list<Node> returnedPath;
public:
    list<Node> aStar(Graph*, Node, Node);
    bool isValid(int x, int y);
    double calculateH(int, int, Node);
    bool isDestination(int, int, Node);
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_ASTAR_H
