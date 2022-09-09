#include <iostream>

using namespace std;

int sum(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    return sum;
}

int recursive_sum(int a[], int i){
    if(i == 0) return a[i];
    return a[i] + recursive_sum(a, i - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << recursive_sum(a, n - 1);
    return 0;
}