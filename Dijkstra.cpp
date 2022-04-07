#include "Dijkstra.h"
#include "Node.h"
#include "Graph.h"
#include <iostream>
#include <list>
#include <queue>
#include <tuple>
#include <math.h>

using namespace std;

list<Node> Dijkstra::dijkstraSearch(Graph* g, Node src, Node dest) {
    priority_queue<Node> priorityQueue;
    vector<bool> visited((*g).size(), false);

    return returnedPath;
}

double Dijkstra::getDistance(Node src, Node dest) {
    double distance;
    vector<int> srcPosition;
    vector<int> destPosition;
    tuple<int, int, int> temp;

    temp = src.getPosition();
    srcPosition.push_back(get<0>(temp));
    srcPosition.push_back(get<1>(temp));
    srcPosition.push_back(get<2>(temp));
      //load src position values into vector

    temp.swap(dest.getPosition());
    destPosition.push_back(get<0>(temp));
    destPosition.push_back(get<1>(temp));
    destPosition.push_back(get<2>(temp));
      //load dest position values into a vector

    distance = sqrt(((destPosition[0]*destPosition[0])+(destPosition[1]*destPosition[1])+(destPosition[2]*destPosition[2]))-((srcPosition[0]*srcPosition[0])+(srcPosition[1]*srcPosition[1])+(srcPosition[2]*srcPosition[2])));
      //distance equation

    return distance;
}

double Dijkstra::getCost(double distance, Node src, Node dest) {
    double cost;

    cost = distance * src.getWeight(dest);

    return cost;
}