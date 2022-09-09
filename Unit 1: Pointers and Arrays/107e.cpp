#include <iostream>

using namespace std;

int twopowerinit(int twopower[], int i){
    if(i == 0) return 1;
    return 2 * twopowerinit(twopower, i - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(0);
    int n;
    cin >> n;
    int twopower[n];
    for(int i = 0; i < n; i++) cout << twopowerinit(twopower, i) << " ";
    return 0;
}