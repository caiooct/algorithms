#include "Node.hpp"

Node::Node(){}

Node::Node(int x, int y, double score, char value){
    coords.first = x;
    coords.second = y;
    this->score = score;
    this->value = value;
}
pair<int,int> Node::getCoords(){
    return coords;
}
double Node::getScore(){
    return score;
}
vector<Node> Node::getNeighbors(){
    return neighbors;
}
char Node::getValue(){
    return value;
}
void Node::addNeighbor(Node no){
    neighbors.push_back(no);
}
string Node::toString(){
            return to_string(coords.first) + " " + to_string(coords.second) + " " + to_string(score);
}
bool operator<( Node no1,  Node no2){
    return (no2.getScore() < no1.getScore());
}
bool operator==(Node no1, Node no2){
    return (no1.getCoords().first == no2.getCoords().first && no1.getCoords().second == no2.getCoords().second);
}