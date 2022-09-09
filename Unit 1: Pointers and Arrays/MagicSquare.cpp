#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, sum;
    cin >> n >> sum;

    int magicsquare[n][n];
    memset(magicsquare, 0, sizeof(magicsquare));

    int magicconst = n * (n * n + 1) / 2, diff = (sum - magicconst) / n;
    int row = 0, col = n / 2;
    
    for (int i = 1; i <= n * n; i++) {
        magicsquare[row][col] = i + diff;
        int tempr = row, tempc = col;
        if(row == 0) row = n - 1;
        else row--;
        if(col == n - 1) col = 0;
        else col++;
        if(magicsquare[row][col] != 0){
            row = tempr + 1;
            col = tempc;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicsquare[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}