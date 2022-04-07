#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCHALGO_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCHALGO_H
#include "Node.h"
#include "Graph.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

class SearchAlgo {
public:
    SearchAlgo();
    ~SearchAlgo();
    void load(vector<string>);
    void execute(int, int);
    void display();
    void stats();
    void select(int, int);
    void save();
    void configure();
    double getCost(double);
    double getDistance();
private:
    Graph* adjList;
    Graph* adjMatrix;
    list<Node> returnedPath;
    double time;
    Node src, dest;
    int algo, storageType;
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCHALGO_H
