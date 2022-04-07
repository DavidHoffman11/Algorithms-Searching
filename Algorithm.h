#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_ALGORITHM_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_ALGORITHM_H
#include <string>
#include <vector>

using namespace std;

class Algorithm {
public:
    //virtual void load(string) = 0;
    virtual void load(vector<string>) = 0;
    virtual void execute(int, int) = 0;
    virtual void display() = 0;
    virtual void stats() = 0;
    virtual void select(int, int) = 0;
    virtual void save() = 0;
    virtual void configure() = 0;
};

#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_ALGORITHM_H
