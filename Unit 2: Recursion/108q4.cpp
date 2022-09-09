#include <iostream>

using namespace std;

string decimalToBinary(int n){
    if(n == 0) return "";
    return decimalToBinary(n/2) + to_string(n%2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 0) cout << "0";
    cout << decimalToBinary(n);
    return 0;
}