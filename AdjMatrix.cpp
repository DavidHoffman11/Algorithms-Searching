#include "AdjMatrix.h"
#include "Node.h"
#include <iostream>
#include <map>

using namespace std;

AdjMatrix::AdjMatrix() {

}

void AdjMatrix::insert(Node &x) {
    adjMatrix.insert(pair<int, Node>(x.getData(), x));
}

int AdjMatrix::size() {
    return adjMatrix.size();
}

Node& AdjMatrix::operator[](int x) {
    return adjMatrix[x];
}
