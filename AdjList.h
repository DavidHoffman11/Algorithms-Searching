#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJLIST_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJLIST_H
#include "Graph.h"
#include "Node.h"
#include <vector>

class AdjList: public Graph {
private:
    vector<Node> adjList;
public:
    AdjList();
    ~AdjList() {}
    void insert(Node&);
    int size();
    Node& operator[] (int);
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJLIST_H
