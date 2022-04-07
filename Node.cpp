#include "Node.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

Node::Node(int x){
    data = x;
    isVisited = false;
}

Node::Node(int val, int x, int y, int z){
    data = val;
    position = make_tuple(x, y, z);
    isVisited = false;
}

void Node::setData(int x){
    data = x;
}

int Node::getData(){
    return data;
}

void Node::setVisit(bool x) {
    isVisited = x;
}

bool Node::getVisit() {
    return isVisited;
}

void Node::setPosition(int x, int y, int z){
    position = make_tuple(x, y, z);
}

tuple<int, int, int>& Node::getPosition(){
    return this->position;
}

void Node::setWeight(int dest, double weight) {
    for(int i = 0; i < connectedNodes.size(); i++) {
        if(connectedNodes[i].first.getData() == dest) {
            connectedNodes[i].second = weight;
        }
    }
}

double Node::getWeight(Node n) {
    for(int i = 0; i < connectedNodes.size(); i++) {
        if(connectedNodes[i].first == n) {
            return connectedNodes[i].second;
        }
    }

    return 0;
}

vector<double> Node::getWeights() {
    vector <double> weights;

    for(int i = 0; i < connectedNodes.size(); i++) {
        weights.push_back(connectedNodes[i].second);
    }

    return weights;
}

void Node::setConnections(Node x) {
    connectedNodes.push_back(make_pair(x, 0.0));
}

void Node::setConnections(vector<pair<Node,double>> x) {
    connectedNodes = x;
}

vector<pair<Node,double>> Node::getConnections() {
    return connectedNodes;
}

int Node::size(){
    return connectedNodes.size();
}

bool Node::operator== (const Node &x) const{
    return (this->data == x.data);
}

bool Node::operator!= (const Node &x) const{
    return (this->data != x.data);
}

Node& Node::operator[] (const int x){
    return connectedNodes[x].first;
}

bool Node::operator> (const Node &x) const{
    return (this->data > x.data);
}

bool Node::operator< (const Node &x) const{
    return (this->data < x.data);
}

bool Node::operator>= (const Node &x) const{
    return (this->data >= x.data);
}

bool Node::operator<= (const Node &x) const{
    return (this->data <= x.data);
}

Node& Node::operator= (const Node &x){
    if (this != &x){
        position = x.position;
        connectedNodes = x.connectedNodes;
        data = x.data;
    }

    return *this;
}
