#include "AdjList.h"
#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

AdjList::AdjList() {

}

void AdjList::insert(Node &x) {
    adjList.push_back(x);
}

int AdjList::size() {
    return adjList.size();
}

Node& AdjList::operator[](int x) {
    return adjList[x-1];
}
