#include <iostream>

using namespace std;

void init_array(int a[], int i){
    if(i == 0) return;
    a[i] = rand() % 50 + 1;
    init_array(a, i - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(0);
    int a[10];
    init_array(a, 9);
    for(int i = 0; i < 10; i++) cout << a[i];
    return 0;
}