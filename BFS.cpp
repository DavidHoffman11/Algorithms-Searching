#include "BFS.h"
#include "Node.h"
#include "Graph.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

list<Node> BFS::BFSIterative(Graph* g, Node src, Node dest) {
    vector<bool> visited((*g).size(), false);
      //initially mark all vertices not visited
    returnedPath.clear();
    list<Node> queue;
      //create queue for BFS
    visited[src.getData()] = true;
    queue.push_back(src.getData());

    while(!queue.empty()) {
        src = queue.front();
        returnedPath.push_back((*g)[src.getData()]);
        //adds node to path
        queue.pop_front();

        //if destination is found
        if(src.getData() == dest.getData()){
            list<Node> tempList;
            Node tempNode = returnedPath.back();
            tempList.push_back(tempNode);
            Node backNode = tempList.back();
              //fixes path
            returnedPath.pop_back();

            while(returnedPath.size() > 0) {
                tempNode = returnedPath.back();
                for(auto node : backNode.getConnections()){
                    if(tempNode.getData() == node.first.getData()){
                        tempList.push_back(tempNode);
                        break;
                    }
                }
                backNode = tempList.back();
                returnedPath.pop_back();

            }
            std::reverse(tempList.begin(),tempList.end());
              //fixes path order
            return tempList;
        }

        //gets connected Nodes
        for(auto node : (*g)[src.getData()].getConnections()) {
            if(!visited[node.first.getData()]) {
                visited[node.first.getData() - 1] = true;
                queue.push_back(node.first);
            }
        }

        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                queue.push_back((*g)[i+1]);
            }
        }
    }

    list<Node> tempList;
    Node tempNode = returnedPath.back();
    tempList.push_back(tempNode);
    Node backNode = tempList.back();
    returnedPath.pop_back();

    while(returnedPath.size() > 0) {
        tempNode = returnedPath.back();
        for(auto node : backNode.getConnections()){
            if(tempNode.getData() == node.first.getData()){
                tempList.push_back(tempNode);
                break;
            }
        }
        backNode = tempList.back();
        returnedPath.pop_back();
    }
    reverse(tempList.begin(),tempList.end());
      //fixes path order and returns the correct path
    return tempList;
}  //implementation based on source code from GeeksforGeeks
   //https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

list<Node> BFS::BFSRecursive(Graph* g, Node src, Node dest) {
    vector<bool> visited((*g).size(), false);
    //initially mark all vertices not visited
    queue<Node> q;

    q.push((*g)[src.getData()]);
    BFSUtil(g, dest, q, visited);

    list<Node> tempList;

    Node tempNode = returnedPath.back();
    tempList.push_back(tempNode);
    Node backNode = tempList.back();

    returnedPath.pop_back();
    while(returnedPath.size() > 0){

        tempNode = returnedPath.back();
        for(auto node : backNode.getConnections()){
            if(tempNode.getData() == node.first.getData()){
                tempList.push_back(tempNode);
                break;
            }
        }
        backNode = tempList.back();
        returnedPath.pop_back();
    }
    reverse(tempList.begin(),tempList.end());
    return tempList;
}

list<Node> BFS::BFSUtil(Graph* g, Node dest, queue<Node> q, vector<bool> visited){
    if (q.empty()) {
        return returnedPath;
    }  //returns path if queue is empty

    Node temp = (*g)[q.front().getData()];
    q.pop();
    returnedPath.push_back(temp);
      //node is pushed onto the queue

    if (temp == dest) {
        return returnedPath;
    } //if temp equals destination, path is returned

    //connected nodes that haven't been visited are added to queue
    for (auto node : temp.getConnections()) {
        if (!visited[node.first.getData() - 1]){
            visited[node.first.getData() - 1] = true;
            q.push((*g)[node.first.getData()]);
        }
    }

    return BFSUtil(g, dest, q, visited);
}