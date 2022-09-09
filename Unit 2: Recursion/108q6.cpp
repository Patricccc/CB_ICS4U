#include <iostream>
using namespace std;
typedef long long ILOVEICS4U;

ILOVEICS4U gcd(ILOVEICS4U a, ILOVEICS4U b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ILOVEICS4U fractorial(ILOVEICS4U n){
    if(n == 1) return 1;
    return n * fractorial(n-1)/gcd(n, fractorial(n-1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ILOVEICS4U n;
    cin >> n;
    cout << fractorial(n);
    return 0;
}