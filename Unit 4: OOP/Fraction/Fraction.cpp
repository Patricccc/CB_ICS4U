#include "Fraction.h"
#include <sstream>
#include <algorithm>

using namespace std;

int lcm(int a, int b){
    return (a*b)/__gcd(a,b);
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    if(denominator == 0) this->denominator = 1;
    else this->denominator = denominator;
    simplify();
}

Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
}

int Fraction::getNumerator(){
    return numerator;
}

int Fraction::getDenominator(){
    return denominator;
}

void Fraction::setNumerator(int numerator){
    this->numerator = numerator;
    simplify();
}

void Fraction::setDenominator(int denominator){
    if(denominator == 0) this->denominator = 1;
    else this->denominator = denominator;
    simplify();
}

string Fraction::toString(){
    stringstream ss;
    ss << numerator << "/" << denominator;
    return ss.str();
}

//part II

Fraction::Fraction(Fraction &f2){
    this->numerator = f2.numerator;
    this->denominator = f2.denominator;
}

void Fraction::print(){
    cout << toString() << endl;
}

void Fraction::simplify(){
    int gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if(denominator < 0){
        numerator *= -1;
        denominator *= -1;
    }
}

void Fraction::add(Fraction &f2){
    int lcm = ::lcm(this->denominator, f2.denominator);
    int n1 = this->numerator * (lcm/this->denominator);
    int n2 = f2.numerator * (lcm/f2.denominator);
    int num = n1 + n2;
    this->numerator = num;
    this->denominator = lcm;
    simplify();
}

void Fraction::subtract(Fraction &f2){
    int lcm = ::lcm(this->denominator, f2.denominator);
    int n1 = this->numerator * (lcm/this->denominator);
    int n2 = f2.numerator * (lcm/f2.denominator);
    int num = n1 - n2;
    this->numerator = num;
    this->denominator = lcm;
    simplify();
}

void Fraction::multiply(Fraction &f2){
    int num = this->numerator * f2.numerator;
    int den = this->denominator * f2.denominator;
    this->numerator = num;
    this->denominator = den;
    simplify();
}

void Fraction::divide(Fraction &f2){
    int num = this->numerator * f2.denominator;
    int den = this->denominator * f2.numerator;
    this->numerator = num;
    this->denominator = den;
    simplify();
}

Fraction Fraction::add(Fraction &f1, Fraction &f2){
    int lcm = ::lcm(f1.denominator, f2.denominator);
    int n1 = f1.numerator * (lcm/f1.denominator);
    int n2 = f2.numerator * (lcm/f2.denominator);
    int num = n1 + n2;
    Fraction fnew(num, lcm);
    return fnew;
}

Fraction Fraction::subtract(Fraction &f1, Fraction &f2){
    int lcm = ::lcm(f1.denominator, f2.denominator);
    int n1 = f1.numerator * (lcm/f1.denominator);
    int n2 = f2.numerator * (lcm/f2.denominator);
    int num = n1 - n2;
    Fraction fnew(num, lcm);
    return fnew;
}

Fraction Fraction::multiply(Fraction &f1, Fraction &f2){
    int num = f1.numerator * f2.numerator;
    int den = f1.denominator * f2.denominator;
    Fraction fnew(num, den);
    return fnew;
}

Fraction Fraction::divide(Fraction &f1, Fraction &f2){
    int num = f1.numerator * f2.denominator;
    int den = f1.denominator * f2.numerator;
    Fraction fnew(num, den);
    return fnew;
}



