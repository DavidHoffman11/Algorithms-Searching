#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_SORT_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_SORT_H
#include "Algorithm.h"
#include "SortAlgo.h"

class Sort: public Algorithm {
public:
    ~Sort() {}
    void load(string);
    void execute();
    void display();
    void stats();
    void select(int);
    void save();
    void configure();

private:
    SortAlgo s;
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_SORT_H
