#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJMATRIX_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJMATRIX_H
#include "Graph.h"
#include "Node.h"
#include <map>

class AdjMatrix: public Graph {
private:
    map<int, Node> adjMatrix;
public:
    AdjMatrix();
    ~AdjMatrix() {}
    void insert(Node&);
    int size();
    Node& operator[] (int);
};

#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_ADJMATRIX_H
