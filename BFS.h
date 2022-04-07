#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_BFS_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_BFS_H
#include "Node.h"
#include "Graph.h"
#include <list>
#include <iostream>
#include <queue>

using namespace std;

class BFS {
private:
    list<Node> returnedPath;
public:
    list<Node> BFSIterative(Graph*, Node, Node);
    list<Node> BFSRecursive(Graph*, Node, Node);
    list<Node> BFSUtil(Graph*, Node, queue<Node>, vector<bool>);
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_BFS_H
