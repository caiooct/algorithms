#include "a_star.hpp"

bool contains(vector<Node> v, Node node){
    for(vector<Node>::iterator it = v.begin(); it != v.end(); ++it){
        if(node == *it)
            return true;
    }
    return false;
}
void remove(vector<Node> &v, Node node){
    for(vector<Node>::iterator it = v.begin(); it != v.end(); ++it){
        if(node == *it){
            v.erase(it);
            return;
        }
    }
}
double heuristic(int x0, int y0, int x1, int y1){
    // Manhattan distance on a square grid
    return abs(x0 - x1) + abs(y0 - y1); 
}
void generateNodeGrid(char maze[][WIDTH], pair<int,int> goal){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            Node aux(i,j,heuristic(i,j,goal.first,goal.second),maze[i][j]);
            nodes2d[i][j] = aux;
        }
    }
    //add the neighbors
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(i+1 < HEIGHT)
                nodes2d[i][j].addNeighbor(nodes2d[i+1][j]);
            if(i-1 >= 0)
                nodes2d[i][j].addNeighbor(nodes2d[i-1][j]);
            if(j+1 < WIDTH)
                nodes2d[i][j].addNeighbor(nodes2d[i][j+1]);
            if(j-1 >= 0)
                nodes2d[i][j].addNeighbor(nodes2d[i][j-1]);
            if(i+1 < HEIGHT && j+1 < WIDTH)
                nodes2d[i][j].addNeighbor(nodes2d[i+1][j+1]);
            if(i+1 < HEIGHT && j-1 >= 0)
                nodes2d[i][j].addNeighbor(nodes2d[i+1][j-1]);
            if(i-1 >= 0 && j-1 >= 0)
                nodes2d[i][j].addNeighbor(nodes2d[i-1][j-1]);
            if(i-1 >= 0 && j+1 < WIDTH)
                nodes2d[i][j].addNeighbor(nodes2d[i-1][j+1]); 
        }
    }
}


void aStar(Node start, Node goal){
    priority_queue<Node>  q;
    vector<Node> closedNodes;
    vector<Node> openNodes;
    q.push(start); openNodes.push_back(start);
    
    while(!q.empty()){
        Node current = q.top();
        q.pop();
        remove(openNodes, current);
        closedNodes.push_back(current);
        
        if(current == goal){
            return;
        }
        
        for(int i = 0; i < current.getNeighbors().size(); i++){
            Node next = current.getNeighbors()[i];
            if(!contains(closedNodes, next) && next.getValue() != 'X' && !contains(openNodes, next)){
                nodes2d[next.getCoords().first][next.getCoords().second].cameFrom = current.getCoords();
                q.push(nodes2d[next.getCoords().first][next.getCoords().second]);
                openNodes.push_back(nodes2d[next.getCoords().first][next.getCoords().second]);
            }
        }        
        
    }
}
void printPath(){
    //TO DO
}