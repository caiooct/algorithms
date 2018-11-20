#include <iostream>
#include <queue>
#include <string>
#include "Node.cpp"

#define HEIGHT 6
#define WIDTH 6

using namespace std;

//node grid
Node nodes2d[HEIGHT][WIDTH];



bool contains(vector<Node> v, Node node);
void remove(vector<Node> &v, Node node);
double heuristic(int x0, int y0, int x1, int y1);
void generateNodeGrid(char maze[HEIGHT][WIDTH]);
void aStar(Node start, Node goal);
void printPath();
