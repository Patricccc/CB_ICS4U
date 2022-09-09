#include <iostream>

using namespace std;

int power(int x, int y){
    if(y == 0 ) return 1;
    if(y == 1) return x;
    return x * power(x, y-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    cout << power(x, y);
    return 0;
}