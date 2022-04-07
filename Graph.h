#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_GRAPH_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_GRAPH_H
#include "Node.h"

using namespace std;

class Graph {
public:
    virtual ~Graph(){}
    virtual void insert(Node&) = 0;
    virtual int size() = 0;
    virtual Node& operator[] (int) = 0;
};

#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_GRAPH_H
