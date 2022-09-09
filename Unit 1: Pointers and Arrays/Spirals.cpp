#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int start, end;
    cin >> start >> end;
    
    int dim = floor(sqrt(end - start)) + 1;
    int middle = ceil(dim/2.0) - 1;

    int grid[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            grid[i][j] = 0;
        }
    }
    int i = start, j = 0, currrow = middle, currcol = middle, count = 0;

    while(i <= end){
        count++;
        j = 1;
        while(j <= count && i <= end){
            grid[currrow][currcol] = i;
            i++;
            currrow++;
            j++;
        }
        j = 1;
        while(j <= count && i <= end){
            grid[currrow][currcol] = i;
            i++;
            currcol++;
            j++;
        }
        count++;
        j = 1;
        while(j <= count && i <= end){
            grid[currrow][currcol] = i;
            i++;
            currrow--;
            j++;
        }
        j = 1;
        while(j <= count && i <= end){
            grid[currrow][currcol] = i;
            i++;
            currcol--;
            j++;
        }
    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(grid[i][j] != 0){
                if(grid[i][j] < 10) cout << " " << grid[i][j] << " ";
                else cout << grid[i][j] << " ";
            }
            else if(grid[i][j] == 0 && j == 0) continue;
            else cout << "   ";
        }
        cout << endl;
    }
    return 0;
}