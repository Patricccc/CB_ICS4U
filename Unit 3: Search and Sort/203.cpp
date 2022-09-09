#include <iostream>

using namespace std;

void q1(){
    cout << "Q1" << endl;
    cout << "Robert Brian Victor David Scott" << endl;
    cout << "Robert Brian Scott David Victor" << endl;
    cout << "Robert Brian David Scott Victor" << endl;
    cout << "David Brian Robert Scott Victor" << endl;
    cout << "Brian David Robert Scott Victor" << endl;
}

/*Q2
If the expression arr[j] > arr[max_pos] were to be changed to arr[j] < arr[max_pos], the program would sort the array in descending order.
*/

/*Q3
a) To avoid swapping an item with itself we can add an if statement to the swap function that checks if the two items are the same.
b) The algorithm still works without the if statement and makes the code look cleaner
*/

void q4a(){
    cout << "Q4" << endl;
    cout << "8 9 6 1 2 4" << endl;
    cout << "1 9 6 8 2 4" << endl;
    cout << "1 2 6 8 9 4" << endl;
    cout << "1 2 4 8 9 6" << endl;
    cout << "1 2 4 6 9 8" << endl;
    cout << "1 2 4 6 8 9" << endl;
}

void q4b(int arr[], int n){
    for(int i = 0; i < n; i++){
        int min_pos = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        swap(arr[i], arr[min_pos]);
    }
}

void selectSort(int arr[], int n, int k){
    for(int i = n - 1; i > n - k - 1; i--){
        int max_pos = 0;
        for(int j = 1; j <= i; j++)
            if(arr[j] > arr[max_pos]) 
                max_pos = j;
        swap(arr[i], arr[max_pos]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //q1
    q1();

    //q4
    q4a();

    //q5
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Q5" << endl;
    selectSort(arr, n, k);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}