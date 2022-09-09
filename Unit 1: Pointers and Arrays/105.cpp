#include <iostream>
#include <cmath>
using namespace std;

void q1a(){
    int** a;
    int r, c;

    cout << "Enter the dimensions of the array: ";
    cin >> r >> c;

    a = new int*[r];
    for(int i = 0; i < r; i++) a[i] = new int[c];

    cout << "Enter the array: ";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    
    cout << "The array is: " << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < r; i++) delete[] a[i];
    delete[] a;
}

void q1b(){
    int** a;
    int r, c, sum = 0;

    cout << "Enter the dimensions of the array: ";
    cin >> r >> c;

    a = new int*[r];
    for(int i = 0; i < r; i++) a[i] = new int[c];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            a[i][j] = rand() % 1000 + 1;
            sum += a[i][j];
        }

    cout << "The average of the array is" << (double) sum / (r * c) << endl;

    for(int i = 0; i < r; i++) delete[] a[i];
    delete[] a;
}

void q1c(){
    int** a;
    int n;

    cout << "Enter the dimension of the array: ";
    cin >> n;

    a = new int*[n];
    for(int i = 0; i < n; i++) a[i] = new int[n];

    cout << "Enter the array: ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(i == j) cout << a[i][j] << " ";
            else cout << " ";
        cout << endl;
    }
    for(int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
}

void q2(){
    int** a;
    int r, c;

    cout << "Enter the dimensions of the first array: ";
    cin >> r >> c;

    a = new int*[r];
    for(int i = 0; i < r; i++) a[i] = new int[c];

    cout << "Enter the first array: ";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    
    int** b;
    int r2, c2;
    cout << "Enter the dimensions of the second array: ";
    cin >> r2 >> c2;

    b = new int*[r2];
    for(int i = 0; i < r2; i++) b[i] = new int[c2];

    cout << "Enter the second array: ";
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            cin >> b[i][j];
    
    int** d;
    int r3 = r + r2, c3 = c + c2;
    d = new int*[r3];
    for(int i = 0; i < r3; i++) d[i] = new int[c3];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            d[i][j] = a[i][j];
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            d[i + r][j + c] = b[i][j];
    
    cout << "The new array is: " << endl;
    for(int i = 0; i < r3; i++){
        for(int j = 0; j < c3; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < r3; i++) delete[] d[i];
    delete[] d;
}

void modifyArray(int b[], int n){
    for(int i = 0; i < n; i++)
        b[i] *= 2;
    
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
}
void modifyElement(int a){
    a *= 2;
    cout << a << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int element[5];
    for(int i = 0; i <= 4; i++) element[i] = i;
    cout << "Effects of passing entire array call by reference\n\n";
    cout << "Value of the original array is \n";
    for (int i = 0; i <= 4; i++)
        cout << element[i] << " ";
    cout << endl;
    modifyArray(element, 5);
    cout << endl << endl;
    cout << "Effects of passing array element call-by-value\n\n";
    cout << "The value of element[3] is " << element[3] << endl;
    modifyElement(element[3]);
    cout << "The value of element[3] is " << element[3] << endl;
    return 0;
}