#ifndef LAB_2_SEARCHING_DAVIDHOFFMAN11_SORTALGO_H
#define LAB_2_SEARCHING_DAVIDHOFFMAN11_SORTALGO_H
#include <vector>
#include <iostream>

using namespace std;

class SortAlgo {
public:
    void load(string);
    void execute();
    void display();
    void stats();
    void select(int);
    void save();
    void configure();
    void bubbleSort(vector<int>&, int);
    void swap(int*, int*);
    void mergeSort(vector<int>&, int, int);
    void merge(vector<int>, int, int, int);
    //used for mergeSort implementation
    void insertionSort(vector<int>&, int);

private:
    vector<int> array;
    int selection;
    string algo;
    double time;
};


#endif //LAB_2_SEARCHING_DAVIDHOFFMAN11_SORTALGO_H
