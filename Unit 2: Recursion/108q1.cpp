#include <iostream>

using namespace std;

int sum1(int n){
    if(n == 1) return 3;
    return sum1(n - 1) - 2;
}

int sum2(int n){
    if(n == 1) return -1;
    return 2 * sum2(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << sum1(n) << endl << sum2(n);
    return 0;
}
