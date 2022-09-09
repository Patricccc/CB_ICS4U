#include <iostream>
#include <iomanip>
using namespace std;
 
double recursive_average(int a[], int n){
    if(n == 1) return a[0];
    else return ((n - 1) * recursive_average(a, n-1) + a[n-1])/n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << setprecision(1) << fixed << recursive_average(a, n) << endl;
    return 0;
}