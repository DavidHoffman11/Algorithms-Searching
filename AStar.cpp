#define X_MAX 1000
#define X_STEP 20
#define Y_MAX 500
#define Y_STEP 20
#include "AStar.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cfloat>
#include <list>

using namespace std;
list<Node> AStar::aStar(Graph *, Node, Node) {

    return returnedPath;
}
/*
vector<Node> AStar::aStar(Node player, Node dest) {
    vector<Node> empty;
    if (isValid(dest) == false) {
        cout << "Destination is an obstacle" << endl;
        return empty;
        //Destination is invalid
    }
    if (isDestination(player, dest)) {
        cout << "You are the destination" << endl;
        return empty;
        //You clicked on yourself
    }
    bool closedList[(X_MAX / X_STEP)][(Y_MAX / Y_STEP)];

    //Initialize whole map
    //Node allMap[50][25];
    array<array < Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)> allMap;
    for (int x = 0; x < (X_MAX / X_STEP); x++) {
        for (int y = 0; y < (Y_MAX / Y_STEP); y++) {
            allMap[x][y].fCost = FLT_MAX;
            allMap[x][y].gCost = FLT_MAX;
            allMap[x][y].hCost = FLT_MAX;
            allMap[x][y].parentX = -1;
            allMap[x][y].parentY = -1;
            allMap[x][y].x = x;
            allMap[x][y].y = y;

            closedList[x][y] = false;
        }
    }

    //Initialize our starting list
    int x = player.x;
    int y = player.y;
    allMap[x][y].fCost = 0.0;
    allMap[x][y].gCost = 0.0;
    allMap[x][y].hCost = 0.0;
    allMap[x][y].parentX = x;
    allMap[x][y].parentY = y;

    vector<Node> openList;
    openList.emplace_back(allMap[x][y]);
    bool destinationFound = false;

    while (!openList.empty()&&openList.size()<(X_MAX / X_STEP)*(Y_MAX / Y_STEP)) {
        Node node;
        do {
            //This do-while loop could be replaced with extracting the first
            //element from a set, but you'd have to make the openList a set.
            //To be completely honest, I don't remember the reason why I do
            //it with a vector, but for now it's still an option, although
            //not as good as a set performance wise.
            float temp = FLT_MAX;
            vector<Node>::iterator itNode;
            for (vector<Node>::iterator it = openList.begin();
                 it != openList.end(); it = next(it)) {
                Node n = *it;
                if (n.fCost < temp) {
                    temp = n.fCost;
                    itNode = it;
                }
            }
            node = *itNode;
            openList.erase(itNode);
        } while (isValid(node.x, node.y) == false);

        x = node.x;
        y = node.y;
        closedList[x][y] = true;

        //For each neighbour starting from North-West to South-East
        for (int newX = -1; newX <= 1; newX++) {
            for (int newY = -1; newY <= 1; newY++) {
                double gNew, hNew, fNew;
                if (isValid(x + newX, y + newY)) {
                    if (isDestination(x + newX, y + newY, dest))
                    {
                        //Destination found - make path
                        allMap[x + newX][y + newY].parentX = x;
                        allMap[x + newX][y + newY].parentY = y;
                        destinationFound = true;
                        return makePath(allMap, dest);
                    }
                    else if (closedList[x + newX][y + newY] == false)
                    {
                        gNew = node.gCost + 1.0;
                        hNew = calculateH(x + newX, y + newY, dest);
                        fNew = gNew + hNew;
                        // Check if this path is better than the one already present
                        if (allMap[x + newX][y + newY].fCost == FLT_MAX ||
                            allMap[x + newX][y + newY].fCost > fNew)
                        {
                            // Update the details of this neighbour node
                            allMap[x + newX][y + newY].fCost = fNew;
                            allMap[x + newX][y + newY].gCost = gNew;
                            allMap[x + newX][y + newY].hCost = hNew;
                            allMap[x + newX][y + newY].parentX = x;
                            allMap[x + newX][y + newY].parentY = y;
                            openList.emplace_back(allMap[x + newX][y + newY]);
                        }
                    }
                }
            }
        }
    }
    if (destinationFound == false) {
        cout << "Destination not found" << endl;
        return empty;
    }
}

bool AStar::isValid(int x, int y) { //If our Node is an obstacle it is not valid
    int id = x + y * (X_MAX / X_STEP);
    if (world.obstacles.count(id) == 0) {
        if (x < 0 || y < 0 || x >= (X_MAX / X_STEP) || y >= (Y_MAX / Y_STEP)) {
            return false;
        }
        return true;
    }
    return false;
}

double AStar::calculateH(int x, int y, Node dest) {
    double H = (sqrt((x - dest.x)*(x - dest.x)
                     + (y - dest.y)*(y - dest.y)));
    return H;
}

bool AStar::isDestination(int x, int y, Node dest) {
    if (x == dest.x && y == dest.y) {
        return true;
    }
    return false;
}
*/