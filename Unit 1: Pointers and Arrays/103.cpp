#include <iostream>
#include <cmath>

using namespace std;

//Q1
void cubeByPointer(int *ptr){
    cout << *ptr << " cubed is ";
    *ptr = (*ptr) * (*ptr) * (*ptr);
    cout << *ptr << endl;
}

//Q2
void sumTwoInt(int *ptra, int *ptrb){
    cout << "Sum is " << (*ptra) + (*ptrb) << endl;
}

//Q3
void circle(int *radius, double *area, double *circumference){
    *area = M_PI * (*radius) * (*radius);
    *circumference = 2 * M_PI * (*radius);
}


//Q4
bool quadEquation(int a, int b, int c, int *ans1, int *ans2){
    int discriminant = b * b - 4 * a * c;
    if(discriminant < 0) return false;
    
    double sqrtdiscriminant = sqrt(discriminant);
    *ans1 = (-b + sqrtdiscriminant)/(a + a);
    *ans2 = (-b - sqrtdiscriminant)/(a + a);
    
    return true;
}

//Q5
void swap(float *p1, float *p2){
    /*
    In the original code, the function attempts to swap the two pointers instead of the values. 
    That is useless because it will not change the actual values that are being pointed to.
    A better solution would be to just swap the values the pointers are pointing to instead.
    */
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    //Alternatively, the pointers could also be passed by reference by using an ampersand (&).
}

//Q6
void SquareComplex(double &a, double &b){
    /*
    In the original code, a is calculated before b, leading to b being miscalculated.
    Instead of b being 2 * a * b, it becomes 2 * (a*a - b*b) * b
    A better solution would be to use a third temporary variable to store the value of a before it is computed.
    */
    double temp = a;
    a = a*a - b*b;
    b = 2*temp*b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    //Q1 test
    int a = 4;
    cubeByPointer(&a);
    cout << endl;
    
    //Q2 test
    int b = 5;
    sumTwoInt(&a, &b);
    cout << endl;
    
    //Q3 test
    double area, circumference;
    circle(&b, &area, &circumference);
    cout << "Area is " << area << endl << "Circumference is " << circumference << endl << endl;
    
    //Q4 test
    int ans1, ans2;
    cout << quadEquation(2, 13, 6, &ans1, &ans2) << ans1 << ans2 << endl;
    cout << quadEquation(1, 0, 0, &ans1, &ans2) << ans1 << ans2 << endl;
    cout << quadEquation(7, 9, 2, &ans1, &ans2) << endl << endl;
    
    //Q5 test
    float num1 = 1, num2 = 0;
    swap(&num1, &num2);
    cout << "After swap " << num1 << num2 << endl << endl;
    
    //Q6 test
    double val1 = 3, val2 = 6;
    SquareComplex(val1, val2);
    cout << "Real = " << val1 << endl << "Imaginary = " << val2 << endl;
    return 0;
}