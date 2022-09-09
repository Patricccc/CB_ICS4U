#include <iostream>

using namespace std;

void quick_sort(int arr[], int low, int high) {
    const int moveleft = 0;
    const int moveright = 1;

    if (low < high) {
        int left = low;
        int right = high;
        int direction = moveleft;
        int pivot = arr[low];

        cout << pivot << " [" << left << " " << right << "]" << endl;

        while (left < right) {
            if (direction == moveleft) {
                while ((arr[right] >= pivot) && (left < right))
                    right--;

                swap(arr[left], arr[right]);
                direction = moveright;
            }

            if (direction == moveright){
                while ((arr[left] <= pivot) && (left < right))
                    left++;
                swap(arr[left], arr[right]);
                direction = moveleft;
            }
        }
        arr[left] = pivot;
        quick_sort(arr, low, left - 1);
        quick_sort(arr, right + 1, high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}