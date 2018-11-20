#include "a_star.cpp"



int main(int argc, char const *argv[]){
    char maze[HEIGHT][WIDTH] = {{'S',' ',' ',' ',' ',' '},
                                {' ','X',' ','X',' ',' '},
                                {' ',' ','X','X','X',' '},
                                {'X',' ','X','G',' ','X'},
                                {'X',' ',' ','X',' ',' '},
                                {' ',' ','X',' ',' ','X'}};
    
    pair<int, int> start(0,0);
    pair<int,int> goal(3,3);
    generateNodeGrid(maze, goal);
    aStar(nodes2d[start.first][start.second],nodes2d[goal.first][goal.second]);

    cout << "Maze:" << endl;
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            cout << nodes2d[i][j].getValue() << " ";
        }
        cout << endl;
    }
    
    
    cout << "Path:" << endl;
    cout << goal.first << " " << goal.second;
    cout << nodes2d[goal.first][goal.second].cameFrom.first << " " << nodes2d[goal.first][goal.second].cameFrom.second << endl;
    cout << nodes2d[4][2].cameFrom.first << " " << nodes2d[4][2].cameFrom.second << endl;
    cout << nodes2d[3][1].cameFrom.first << " " << nodes2d[3][1].cameFrom.second << endl;
    cout << nodes2d[2][1].cameFrom.first << " " << nodes2d[2][1].cameFrom.second << endl;
    cout << nodes2d[1][0].cameFrom.first << " " << nodes2d[1][0].cameFrom.second << endl;
    return 0;
}
