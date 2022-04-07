#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCH_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCH_H
#include "Algorithm.h"
#include "SearchAlgo.h"
#include <string>
#include <vector>


class Search: public Algorithm {
public:
    ~Search() {}
    void load(vector<string>);
    void execute(int, int);
    void display();
    void stats();
    void select(int, int);
    void save();
    void configure();

private:
    SearchAlgo s;
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_SEARCH_H
