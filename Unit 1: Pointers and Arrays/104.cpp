#include <iostream>

using namespace std;

void q1a(){
    int n;
    int *ptr;
    
    cout << "Enter array length: ";
    cin >> n;
    
    ptr = new int[n];
   
    cout << "Enter the array: ";
    for(int i = 0; i < n; i++) cin >> ptr[i];
    
    cout << "Array: ";
    for(int i = 0; i < n; i++) cout << ptr[i] << " ";
    
    cout << endl << endl;
    delete[] ptr;
}

void q1b(){
    int n;
    int *ptr;
    
    cout << "Enter array length: ";
    cin >> n;
    
    ptr = new int[n];
    
    cout << "Enter the array: ";
    for(int i = 0; i < n; i++) cin >> ptr[i];
    
    cout << "Array in reverse order: ";
    for(int i = n-1; i >= 0; i--) cout << ptr[i] << " ";
    
    cout << endl << endl;
    delete[] ptr;
}

void q1c(){
    int n, sum = 0;
    int *ptr;
    
    cout << "Enter array length: ";
    cin >> n;
    
    ptr = new int[n];
    
    cout << "Random array: ";
    
    for(int i = 0; i < n; i++){
        ptr[i] = rand() % 50 + 1;
        cout << ptr[i] << " ";
        sum += ptr[i];
    }
    
    cout << endl << "Sum of elements: " << sum << endl << endl;
    delete[] ptr;
}

void q1d(){
    int n, n1, n2;
    int *ptr, *ptr1, *ptr2;
    
    cout << "Enter 1st array length: ";
    cin >> n1;
    
    cout << "Enter 2nd array length: ";
    cin >> n2;
    
    n = n1 + n2;
    
    ptr = new int[n];
    ptr1 = new int[n1];
    ptr2 = new int[n2];
    
    cout << "Enter 1st array: ";
    for(int i = 0; i < n1; i++){
        cin >> ptr1[i];
        ptr[i] = ptr1[i];
    }
    
    cout << "Enter 2nd array: ";
    for(int i = n1; i < n; i++){
        cin >> ptr2[i];
        ptr[i] = ptr2[i];
    }
    
    cout << "Combined array: " << endl;
    for(int i = 0; i < n; i++) cout << ptr[i] << " ";
    
    delete[] ptr;
    delete[] ptr1;
    delete[] ptr2;
}

int main() {
    srand(time(NULL));
    
    q1a();
    q1b();
    q1c();
    q1d();
    
    return 0;
}
