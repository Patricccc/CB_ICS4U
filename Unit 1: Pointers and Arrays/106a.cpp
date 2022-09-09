#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void sieve(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;

    for (int i = 2; i <= ceil(sqrt(n)); i++){
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if (primes[i])
            cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    sieve(n);
    return 0;
}