#include "Search.h"
#include <string>
#include <vector>

using namespace std;

void Search::load(vector<string> x) {
    return s.load(x);
}

void Search::execute(int src, int dest) {
 return s.execute(src, dest);
}

void Search::display() {
    return s.display();
}

void Search::stats() {
    return s.stats();
}

void Search::select(int x, int y) {
    return s.select(x, y);
}

void Search::save() {
    return s.save();
}

void Search::configure() {
    return s.configure();
}
