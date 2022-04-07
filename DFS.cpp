#include "DFS.h"
#include "Graph.h"
#include "Node.h"
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

list<Node> DFS::DFSIterative(Graph *g, Node src, Node dest) {
    vector<bool> visited((*g).size(), false);
    //initially mark all vertices not visited
    returnedPath.clear();
    stack<Node> stack;
    //create a stack for DFS
    stack.push(src);
    //push source node onto the stack

    while (!stack.empty()) {
        src = stack.top();
        stack.pop();
        //pop vertex from stack
        returnedPath.push_back((*g)[src.getData()]);
        //adds node to path

        if (src == dest) {
            return returnedPath;
        }

        if (!visited[src.getData()]) {
            visited[src.getData()] = true;
            src.setVisit(true);
        }

        for (auto node : (*g)[src.getData()].getConnections()) {
            if (!visited[node.first.getData()]) {
                stack.push(node.first);
            }
        }
    }

    return returnedPath;
}  //implementation based on source code from GeeksforGeeks
//https://www.geeksforgeeks.org/iterative-depth-first-traversal/

list<Node> DFS::DFSRecursive(Graph *g, Node src, Node dest) {
    vector<bool> visited((*g).size(), false);
    returnedPath.clear();

    return DFSUtil(g, src, dest, visited);
}  //implementation based on source code from GeeksforGeeks
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

list<Node> DFS::DFSUtil(Graph *g, Node curr, Node dest, vector<bool> &visited) {
    visited[curr.getData() - 1] = true;
    returnedPath.push_back((*g)[curr.getData()]);

    if (curr == dest) {
        return returnedPath;
    }  //returns the full path once dest is found

    for (auto node : (*g)[curr.getData()].getConnections()) {
        if(curr == dest) {
            break;
        } else if (!visited[node.first.getData() - 1]) {
            return DFSUtil(g, (*g)[node.first.getData()], dest, visited);
        }
    }

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) {
            curr = (*g)[i + 1];
            return DFSUtil(g, curr, dest, visited);
        }
    }

    return returnedPath;
}   //implementation based on source code from GeeksforGeeks
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
