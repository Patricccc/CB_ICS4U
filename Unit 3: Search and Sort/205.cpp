#include <iostream>
#include <cmath>

using namespace std;

void ksort(int arr[], int n, int k){
    for(int i = 0; i < k; i++){
        for(int j = i + k; j < n; j += k){
            int temp = arr[j];
            int m = j;
            while(m > i && temp < arr[m - k]){
                arr[m] = arr[m - k];
                m -= k;
            }
            arr[m] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            if (i % 10 == 9) cout << endl;
            else cout << " ";
        }
    }
    cout << endl << endl;
}

void shell_sort(int arr[], int n){
    int k = 1;
    while(k < n / 3)
        k = 3 * k + 1;
    k /= 3;
    while(k > 0){
        cout << k << "k sort list: " << endl;
        ksort(arr, n, k);
        k /= 3;
    }
}

/*Q3
Although it may seem that shellsort is slower than insertion sort, it is actually faster. This is because shellsort is a generalization of insertion sort, and it is possible to choose the increment sequence so that the number of exchanges is small.
*/

/*Q4
a)
int k = 1;
while(k < n / 3)
    k = 3 * k + 1;
b)
k /= 3;
*/

/*Q6
Testing
3k sort list: 261988 ns
2k sort list: 498286 ns
4k sort list: 241612 ns

Based on my testing, the k-sequence given is not the best, since the 4k sort list is faster than the 3k sort list by a very narrow margin.
However, it is impossible to say which k-sequence is the best, since there are factors such as randomness.
*/


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //Q1
    cout << "Q1" << endl;
    cout << "19 18 21 22 29 26 37 26 41 63 47 61 72 55" << endl;

    //Q2
    cout << "Q2" << endl;
    cout << "19 18 21 22 29 26 37 26 41 55 47 61 72 63" << endl;

    //Q5
    cout << "Q5" << endl;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    shell_sort(arr, n);
    return 0;
}