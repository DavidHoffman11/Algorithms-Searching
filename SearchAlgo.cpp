#include "SearchAlgo.h"
#include "Graph.h"
#include "Node.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "AStar.h"
#include "BFS.h"
#include "DFS.h"
#include "Dijkstra.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <math.h>

using namespace std;

SearchAlgo::SearchAlgo() {
    adjMatrix = new AdjMatrix();
    adjList = new AdjList();
}

SearchAlgo::~SearchAlgo() {
    delete adjList;
    delete adjMatrix;
}

void SearchAlgo::load(vector<string> files) {
    string file1 = files[0];
    //stores graph.txt
    string file2 = files[1];
    //stores positions.txt
    string file3 = files[2];
    //stores weights.txt

    ifstream file(file1);
    if(!file){
        cout << "Could not load " << file1 << endl;
        perror ( "Stream Failed to open because: " );
        return;
    }  //prints error statement if file can't be loaded in

    else if(file.is_open()) {
        string source, destination, token;
        string delim = ",";
        size_t pos = 0;

        while (getline(file, source, ',')) {
            Node temp(stoi(source));
              //read in source node

            getline(file, destination);
              //gets connected nodes
            while ((pos = destination.find(delim)) != string::npos) {
                token = destination.substr(0, pos);
                temp.setConnections(Node(stoi(token)));
                destination.erase(0, pos + delim.length());
                  //adds connected nodes to connectedNodes vector
            }
            temp.setConnections(Node(stoi(destination)));
            //add last int in list to vector
            adjList->insert(temp);
        }
    }
    file.close();

    file.open(file2);
    if (file.is_open()) {
        string source;
          //holds int value of source node
        string x, y, z;
          //holds position value of source
        while (getline(file, source, ',') && getline(file, x, ',') && getline(file, y, ',') && getline(file, z, '\n')) {
            (*adjList)[stoi(source)].setPosition(stoi(x), stoi(y), stoi(z));
            //add position to source node
            if((*adjList)[stoi(source)].getData() == src.getData()) {
                src.setPosition(stoi(x), stoi(y), stoi(z));
            } else if((*adjList)[stoi(source)].getData() == dest.getData()) {
                dest.setPosition(stoi(x), stoi(y), stoi(z));
            }  //if/else statement sets position of src and dest node once that node is found
        }
    }
    file.close();

    file.open(file3);
    if (file.is_open()) {
        string source, destination, weight;
        //variables hold data
        while (getline(file, source, ',') && getline(file, destination, ',') && getline(file, weight, '\n')) {
            //reads file
            for (int i = 1; i <= (*adjList).size(); i++) {
                //Sets weight if node is found
                if ((*adjList)[i].getData() == stoi(source)) {
                    (*adjList)[stoi(source)].setWeight(stoi(destination), stod(weight));
                    break;
                }
            }  //loop through vector until destination node is found
        }
    }
    file.close();

    for (int i = 0; i < (*adjList).size(); i++) {
        tuple<int, int, int> srcPos = (*adjList)[i + 1].getPosition();
        //makes node and adds data
        Node temp(i + 1);
        temp.setConnections((*adjList)[i + 1].getConnections());
        temp.setPosition(get<0>(srcPos), get<1>(srcPos), get<2>(srcPos));
        adjMatrix->insert(temp);
        //insert node into matrix
    }  //load data int adj matrix
}

void SearchAlgo::execute(int source, int destination) {
    std::chrono::high_resolution_clock::time_point time1, time2;
    time1 = std::chrono::high_resolution_clock::now();
    //captures timing of search

    src.setData(source);
    dest.setData(destination);
      //sets values of source and destination nodes

    //runs search of list
    if(storageType == 1) {
        if (algo == 0 || algo == 1) {
            //runs DFS iterative and recursive
            DFS run;

            if (algo == 0) {
                returnedPath = run.DFSIterative(adjList, src, dest);
            } else {
                returnedPath = run.DFSRecursive(adjList, src, dest);
            }
        } else if (algo == 2 || algo == 3) {
            //runs BFS iterative and recursive
            BFS run;
            if (algo == 2) {
                returnedPath = run.BFSIterative(adjList, src, dest);
            } else {
                returnedPath = run.BFSRecursive(adjList, src, dest);
            }

        } else if (algo == 4) {
            //runs Dijkstra
            Dijkstra run;

            returnedPath = run.dijkstraSearch(adjList, src, dest);
        } else {
            //runs AStar
            AStar run;

            returnedPath = run.aStar(adjList, src, dest);
        }
    }

    //runs search on adj matrix
    else {
        if (algo == 0 || algo == 1) {
            //runs DFS iterative and recursive
            DFS run;

            if (algo == 0) {
                returnedPath = run.DFSIterative(adjMatrix, src, dest);
            } else {
                returnedPath = run.DFSRecursive(adjMatrix, src, dest);
            }
        } else if (algo == 2 || algo == 3) {
            //runs BFS iterative and recursive
            BFS run;

            if (algo == 2) {
                returnedPath = run.BFSIterative(adjMatrix, src, dest);
            } else {
                returnedPath = run.BFSRecursive(adjMatrix, src, dest);
            }
        } else if (algo == 4) {
            //runs Dijkstra
            Dijkstra run;

            returnedPath = run.dijkstraSearch(adjMatrix, src, dest);
        } else {
            //runs AStar
            AStar run;

            returnedPath = run.aStar(adjMatrix, src, dest);
        }
    }

    time2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(time2 - time1);
    time = time_span.count();
    //gets the execution time
}

void SearchAlgo::display() {
    list<Node>::iterator it;

    cout << "Returned Path:";
    for (it = returnedPath.begin(); it != returnedPath.end(); ++it) {
        cout << " -> " << it->getData();
    }  //prints returnedPath

    cout << endl;
}

void SearchAlgo::stats() {
    if (algo == 0) {
        cout << "DFS Iterative" << endl;
    } else if(algo == 1) {
        cout << "DFS Recursive" << endl;
    } else if(algo == 2) {
        cout << "BFS Iterative" << endl;
    } else if(algo == 3) {
        cout << "BFS Recursive" << endl;
    } else if(algo == 4) {
        cout << "Dijkstra" << endl;
    } else if(algo == 5) {
        cout << "AStar" << endl;
    }
    display();
    //displays returnedPath
    cout << "Storage Type: ";
    if(storageType == 1) {
        cout << "Adjacency List" << endl;
    } else {
        cout << "Adjacency Matrix" << endl;
    }

    double distance = getDistance();
    cout << "Number of nodes in returnedPath: " << returnedPath.size() << endl;
    cout << "Total Cost of Search: " << getCost(distance) << endl;
    cout << "Searching Distance: " << distance << endl;
    cout << "Nodes explored: " << returnedPath.size() << endl;
    cout << "Execution time: " << time << endl << endl;
}

void SearchAlgo::select(int x, int y) {
    algo = x;
    storageType = y;
}

void SearchAlgo::save() {
    ofstream output("Output.txt");

    list<Node>::iterator it;

    output << "Path:";
    for (it = returnedPath.begin(); it != returnedPath.end(); ++it) {
        output << " -> " << it->getData();
    }
    output << endl;

    output.close();
}

void SearchAlgo::configure() {
    //implementation will be added later
    //allows for future expandability
}

double SearchAlgo::getCost(double distance) {
    double totalCost = 0;
    double totalWeight = 0;

    list<Node>::iterator it;

    for(it = returnedPath.begin(); it != returnedPath.end(); ++it) {
        double tempWeight;

        Node temp (next(it)->getData());

        tempWeight = it->getWeight(temp);
        totalWeight = totalWeight + tempWeight;
    }

    totalCost = totalWeight*distance;

    return totalCost;
}

double SearchAlgo::getDistance() {
    double totalDistance = 0;
    vector<int> srcPosition;
    vector<int> destPosition;
    tuple<int, int, int> temp;

    list<Node>::iterator it;

    for(it = returnedPath.begin(); it != returnedPath.end(); ++it) {
        double tempDistance;

        temp = it->getPosition();
        srcPosition.push_back(get<0>(temp));
        srcPosition.push_back(get<1>(temp));
        srcPosition.push_back(get<2>(temp));
        //load src position values into vector


        temp.swap(next(it)->getPosition());
        destPosition.push_back(get<0>(temp));
        destPosition.push_back(get<1>(temp));
        destPosition.push_back(get<2>(temp));
        //load dest position values into a vector

        tempDistance = sqrt(((destPosition[0]*destPosition[0])+(destPosition[1]*destPosition[1])+(destPosition[2]*destPosition[2]))-((srcPosition[0]*srcPosition[0])+(srcPosition[1]*srcPosition[1])+(srcPosition[2]*srcPosition[2])));
        //distance equation

        srcPosition.clear();
        destPosition.clear();

        totalDistance = totalDistance + tempDistance;
    }

    return totalDistance;
}