#include <iostream>

using namespace std;


int largest(int a[], int n){
    int max = NULL;
    for(int i = 0; i < n; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

int recursive_largest(int a[], int i){
    if(i == 0) return a[i];
    return max(a[i], recursive_largest(a, i - 1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << recursive_largest(a, n - 1);
    return 0;
}