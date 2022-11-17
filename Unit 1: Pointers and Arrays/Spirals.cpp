#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int start, end;
    cin >> start >> end;
    
    if(start == end){
        cout << start << endl;
        return 0;
    }
    
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
    
    bool first[dim] = {false};

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(grid[i][j] != 0){
                if(!first[i]){
                    first[i] = true;
                    cout << grid[i][j];
                }
                else if(grid[i][j] < 10 && (j == 0 || j == dim - 1)) cout << " " << grid[i][j];
                else if(grid[i][j] < 10) cout << "  " << grid[i][j];
                else if(j == 0) cout << grid[i][j];
                else cout << " " << grid[i][j];
            }
            else if(grid[i][j] == 0 && (j == 0 || j == dim - 1)) continue;
            else cout << "   ";
        }
        cout << endl;
    }
    return 0;
}
