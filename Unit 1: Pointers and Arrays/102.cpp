#include <iostream>

using namespace std;

void q1(){
    int number = 123;
    int* pnumber = &number;
    cout << number << endl << &number << endl << *pnumber << endl << pnumber << endl;
}

void q2(){
    int num1 = 50, num2 = 100;
    int* pnum = NULL;
    pnum = &num1;
    *pnum += 50;
    cout << num1 << endl << pnum << endl;
    pnum = &num2;
    *pnum *= 2;
    num1 = *pnum;
    cout << num1 << endl << pnum << endl << *pnum << endl;
}

void q3(){
    double value1 = 200000, value2;
    double* lPtr = &value1;
    cout << *lPtr << endl;
    value2 = *lPtr;
    cout << value2 << endl;
    cout << &value1 << endl << lPtr << endl;
    //the two addresses are the same
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return 0;
}