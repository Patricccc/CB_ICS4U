#include <iostream>

using namespace std;

void printArray(int arr[], int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        if (i == a) cout << "(" << arr[i] << " ";
        else if(i == b) cout << " " << arr[i] << ")";
        else cout << " " << arr[i] << " ";
    }
    cout << endl;
}

void q1(){
    cout << "Q1" << endl;
    cout << "(3  8)  3  2  7  5" << endl;
    cout << "3  (8  3)  2  7  5" << endl;
    cout << "3  3  (8  2)  7  5" << endl;
    cout << "3  3  2  (8  7)  5" << endl;
    cout << "3  3  2  7  (8  5)" << endl;
    cout << "(3  3)  2  7  5  8" << endl;
    cout << "3  (3  2)  7  5  8" << endl;
    cout << "3  2  (3  7)  5  8" << endl;
    cout << "3  2  3  (7  5)  8" << endl;
    cout << "(3  2)  3  5  7  8" << endl;
    cout << "2  (3  3)  5  7  8" << endl;
    cout << "2  3  (3  5)  7  8" << endl;
    cout << "(2  3)  3  5  7  8" << endl;
    cout << "2  (3  3)  5  7  8" << endl;
    cout << "2  3  3  5  7  8" << endl;
}

/*Q2
To sort the elements in descending order, we can just flip the inequality sign in the if statement.
*/

void q3(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    for (int i = n - 1; i > n - 3; i--){
        if ((n - 1 - i) % 2 == 0){
            for (int j = left; j < right; j++) {
                printArray(arr, n, j, j + 1);
                if (arr[j + 1] < arr[j]) 
                    swap(arr[j], arr[j + 1]);
            }
            right--;
        }
        else{
            for (int j = right; j > left; j--){
                printArray(arr, n, j - 1, j);
                if (arr[j - 1] > arr[j])
                    swap(arr[j - 1], arr[j]);
            }
            left++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << " " << arr[i] << " ";
    }
}

void shakerSort(double arr[], int n){
    int swaps = 0;
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while(swapped){
        swapped = false;
        for(int i = start; i < end; i++){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                swapped = true;
                swaps++;
            }
        }
        if(!swapped) break;
        swapped = false;
        end--;
        for(int i = end - 1; i >= start; i--){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                swapped = true;
                swaps++;
            }
        }
        start++;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl << swaps;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //Q1
    q1();

    //Q3
    cout << "Q3" << endl;
    int arr3[] = {2, 9, 4, 6, 1, 7, 4};
    q3(arr3, 7);

    //Q4
    int n;
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << endl << "Q4" << endl;
    shakerSort(arr, n);
    return 0;
}