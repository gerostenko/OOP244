// OOP244 Workshop 5: operators overloading
// File: w5_in_lab.cpp
// Version: 1.0
// Date: 2017/15/06
// Author: Galina Erostenko
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: header file guard
#ifndef SICT_FRACTION_H__
#define SICT_FRACTION_H__


// TODO: create namespace
namespace sict {
    // TODO: define the Fraction class
    class Fraction {
    private:
        int m_num;
        int m_denom;

    int gcd() const; // returns the greatest common divisor of num and denom
    int max() const; // returns the maximum of num and denom
    int min() const; // returns the minimum of num and denom
    void reduce();   // simplifies a Fraction by dividing the numerator and denominator to their greatest common divisor 
public:
    // TODO: declare the member functions
    void setEmpty();
    Fraction();
    Fraction(int, int);
    bool isEmpty() const;
    void display() const;
    // TODO: declare the + operator overload
    Fraction operator+(const Fraction& src) const;
    Fraction operator*(const Fraction& src) const;
    bool operator==(const Fraction& src) const;
    bool operator!=(const Fraction& src) const;
    Fraction& operator+=(const Fraction& src);

};
}
#endif 