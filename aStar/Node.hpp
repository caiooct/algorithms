#include <string>
#include <queue>
using namespace std;

class Node{
    pair<int,int> coords;
    vector<Node> neighbors;
    double score;
    char value;
    public:
        pair<int,int> cameFrom;
        Node();
        Node(int x, int y, double score, char value);
        pair<int,int> getCoords();
        double getScore();
        vector<Node> getNeighbors();
        char getValue();
        void addNeighbor(Node no);
        string toString();
};