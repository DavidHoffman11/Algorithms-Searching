#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_DFS_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_DFS_H
#include "Node.h"
#include "Graph.h"
#include <list>
#include <vector>

class DFS {
private:
    list<Node> returnedPath;
public:
    list<Node> DFSIterative(Graph*, Node, Node);
    list<Node> DFSRecursive(Graph*, Node, Node);
    list<Node> DFSUtil(Graph*, Node, Node, vector<bool>&);
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_DFS_H
