#include <iostream>
using namespace std;

char grid[1025][1025];


void pinta(int i, int j, int n, int m){
	grid[i][j] = 'x';
	if(i+1 < n && grid[i+1][j] == '.')
		pinta(i+1,j,n,m);
	if(i-1 >= 0 && grid[i-1][j] == '.')
		pinta(i-1,j,n,m);
	if(j+1 < m && grid[i][j+1] == '.')
		pinta(i,j+1,n,m);
	if(j-1 >= 0 && grid[i][j-1] == '.')
		pinta(i,j-1,n,m);
	
}
int main(int argc, char const *argv[]){
    int n,m, qtd = 0;
	cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
			if(grid[i][j] == '.'){
				pinta(i,j,n,m);
				qtd++;
			}
		}
    }

	cout << qtd << endl;
    return 0;
}