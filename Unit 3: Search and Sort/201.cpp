#include <iostream>
#include <algorithm>
using namespace std;

int* createRndArray(int n, int low, int high) {
    srand(0);
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % (high-low+1) + low;
    }
    return arr;
}

void printArray(int* arr, int high, int low) {
    for(int i = low; i <= high; i++) cout << arr[i] << " ";
    cout << endl;
}

int linear_search(int arr[], int n, int key) {
    for(int i = 0; i < n; i++){
        printArray(arr, n-1, i);
        if(arr[i] == key) return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int key){
    int low = 0, high = n-1, mid = n/2;
    while(low <= high){
        printArray(arr, high, low);
        mid = (low + high + 1)/2;
        if(arr[mid] == key){
            if(high != low) cout << arr[mid] << endl;
            return mid;
        }
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    cout << "Linear Search" << endl;
    int index = linear_search(a, n, x);
    if(index != -1) cout << "found at index " << index << endl << endl;
    else cout << "not found" << endl << endl;
    
    cout << "Binary Search" << endl;
    index = binary_search(a, n, x);
    if(index != -1) cout << "found at index " << index << endl << endl;
    else cout << "not found" << endl << endl;
    return 0;
}
