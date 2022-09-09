#include <iostream>

using namespace std;

double birthday(int n){
    double ans = 1;
    if(n >= 365) return 1;
    for(int i = 1; i < n; i++){
        ans = ans * (365 - i) / i;
    }
    return 1 - ans;
}

double recursive_birthday(int n){
    if(n > 365) return 0;
    if(n <= 1) return 1;
    return recursive_birthday(n - 1) * (365 - n + 1) / 365;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << 1 - recursive_birthday(n);
    return 0;
}