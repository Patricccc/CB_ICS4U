#ifndef Fraction_h
#define Fraction_h
#include <iostream>

class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);
        Fraction();
        int getNumerator();
        int getDenominator();
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        std::string toString();
        //part II
        Fraction(Fraction &f2);
        void print();
        void simplify();
        void add(Fraction &f2);
        void subtract(Fraction &f2);
        void multiply(Fraction &f2);
        void divide(Fraction &f2);
        static Fraction add(Fraction &f1, Fraction &f2);
        static Fraction subtract(Fraction &f1, Fraction &f2);
        static Fraction multiply(Fraction &f1, Fraction &f2);
        static Fraction divide(Fraction &f1, Fraction &f2);

};

#endif /* Fraction_h */
