// OOP244 Workshop 5: operators overloading
// File: w5_in_lab.cpp
// Version: 1.0
// Date: 2017/15/06
// Author: Galina Erostenko
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: insert header files
#include <iostream>
#include"Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict {
    //Empty state function
    void Fraction::setEmpty()
    {
        m_num = 0;
        m_denom = 0;
    }
    // TODO: implement the default constructor
    Fraction::Fraction()
    {
        setEmpty();
    }
    // TODO: implement the two-argument constructor
    Fraction::Fraction(int num, int denom)
    {
        if (num >= 0 && denom > 0)
        {
            m_num = num;
            m_denom = denom;
            this->reduce();
        }
        else
        {
            setEmpty();
        }
    }
    // TODO: implement the max query
    // max returns the maximum of the numerator and denominator
    //
    int Fraction::max() const
    {
        return (m_num > m_denom ? m_num : m_denom);
    }

    // TODO: implement the min query
    // min returns the maximum of the numerator and denominator
    //
    int Fraction:: min() const
    {
        return (m_num < m_denom ? m_num : m_denom);
    }
    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = max();  // min of numerator and denominator
        int mx = min();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier  
    // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
    //
    void Fraction::reduce() {
        int g_c_d = gcd();
        m_num /= g_c_d;
        m_denom /= g_c_d;
    }

    // TODO: implement the display query
    // display inserts num/denom into the output stream
    //
    void Fraction::display() const
    {

        if (isEmpty())
        {
            cout << "no fraction stored";
        }
        else if (m_denom > 1)
        {
            
            cout << m_num << "/" << m_denom;
        }
        else
        {
            cout << m_num;
        }
    }

    // TODO: implement the isEmpty query
    // isEmpty returns true if Fraction object is in a safe empty state
    //
    bool Fraction::isEmpty() const
    {
        bool result = false;
        if (m_num==0 && m_denom ==0)
        {
            result = true;
        }
        return result;
    }

    // TODO: implement the + operator
    // + operator adds the rhs to the current object and reduces the result
    //
    Fraction Fraction::operator+(const Fraction& src) const
    {
        Fraction temp;
        if (!isEmpty() && !src.isEmpty())
        {
            temp.m_denom = m_denom*src.m_denom;
            temp.m_num = m_num*src.m_denom + src.m_num*m_denom;
            temp.reduce();
        }
        return temp;
    }
}

