#include <iostream>
#include <cmath>

using namespace std;
//Q1
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void q1(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        print(arr, n);
    }
}

/*Q2
To sort the array in descending order, we can use the same insertion sort algorithm, but instead of comparing the current element with the previous one, we compare it with the next one. If the current element is smaller than the next one, we swap them. We repeat this process until the current element is greater than the next one. Then we move to the next element and repeat the process.
*/

//Q3
void printarr(string arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool compare(string a, string b){
    int n = min(a.length(), b.length());
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            return true;
        }
        else if(a[i] < b[i]){
            return false;
        }
    }

    return a.length() > b.length();
}

void q3(string arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        string temp = arr[i];
        while(j >= 0 && compare(arr[j], temp)){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        printarr(arr, n);
    }
}

//Q4
void q4(double arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        double temp = arr[i];
        while(j >= 0 && arr[j] < temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

/*Q5
Insertion sort is stable because when we insert an element into the sorted part of the array, we insert it before the first element that is smaller than it. This means that if there are two equal elements, the one that was inserted first will be in the same position as it was before the sorting process.
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << "Q1" << endl;
    int arr[] = {6, 2, 8, 3, 1, 7, 4};
    print(arr, 7);
    q1(arr, 7);

    cout << "Q3" << endl;
    string arr1[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"};
    printarr(arr1, 8);
    q3(arr1, 8);

    cout << "Q4" << endl;
    int n;
    cin >> n;
    double arr2[n];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    q4(arr2, n);
    double median;
    if(n % 2 == 0) median = (arr2[n / 2] + arr2[n / 2 - 1]) / 2.0;
    else median = arr2[n / 2];
    cout << median << endl;
    return 0;
}