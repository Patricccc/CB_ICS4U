#include <bits/stdc++.h>

using namespace std;

void init_array(int* a, int i){
    a[i] = rand() % 50 + 1;
    if(i == 0) return;
    init_array(a, i - 1);
}

int main(){
    srand(time(NULL));
    int* a = new int[10];
    init_array(a, 9);
    for(int i = 0; i < 10; i++) cout << a[i] << endl;
    return 0;
}
