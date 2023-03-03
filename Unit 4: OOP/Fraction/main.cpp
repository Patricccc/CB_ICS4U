#include <bits/stdc++.h>
#include "Fraction.cpp"
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1(2,4);
    cout << "Fraction: " << f1.toString() << endl;

    f1.setNumerator(3);
    f1.setDenominator(6);
    cout << "New Fraction: " << f1.toString() << endl;

    int num = f1.getNumerator();
    int den = f1.getDenominator();
    cout << "Numerator: " << num << endl;
    cout << "Denominator: " << den << endl;

    Fraction f2(f1);
    f2.add(f1);
    f2.print();
    f2.subtract(f1);
    f2.print();
    f2.multiply(f1);
    f2.print();
    f2.divide(f1);
    f2.print();

    Fraction f3 = Fraction(1,2);
    Fraction f4 = Fraction(1,3);

    cout << "Addition: " << Fraction::add(f3, f4).toString() << endl;
    cout << "Subtraction: " << Fraction::subtract(f3, f4).toString() << endl;
    cout << "Multiplication: " << Fraction::multiply(f3, f4).toString() << endl;
    cout << "Division: " << Fraction::divide(f3, f4).toString() << endl;

    return 0;
}
