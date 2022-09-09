#include <iostream>

using namespace std;

void printArrayRecursive(int a[], int i){
    if(i < 0) return;
    printArrayRecursive(a, i - 1);
    cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    printArrayRecursive(a, n);
    return 0;
}