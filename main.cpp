#include "Algorithm.h"
#include "Search.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    Algorithm *src = new Search();
    int source, destination;
    vector<string> fileType;

    if (argc > 1) {
        //takes in the src and destination
        source = atoi(argv[1]);
        destination = atoi(argv[2]);
    }

    fileType.push_back("Data\\SampleGraph\\graph.txt");
    fileType.push_back("SampleGraph\\positions.txt");
    fileType.push_back("Data\\SampleGraph\\weights.txt");

    src->load(fileType);
     //load only needs to be called once

    for(int i = 0; i < 4; i++) {
        for(int j = 1; j < 3; j++) {
            src->select(i, j);
            src->execute(source, destination);
            src->stats();
        }
    }

    return 0;
}