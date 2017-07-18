/// BTP200 Workshop 8: Virtual Functions
// File: w8_at_home.cpp
// Version: 1.0
// Date: 2017/07/15
// Author: Galina Erostenko
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
    //Default constructor
    SavingsAccount::SavingsAccount() : Account(0)
    {
        m_interestRate = 0;
    }
    //Constructor sets interest rate and balance
    SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
    {
        interestRate < 0 ? m_interestRate = 0 : m_interestRate = interestRate;
    }
    //Function calculating interest rate
    double SavingsAccount::calculateInterest()
    {
        return getBalance() * m_interestRate;
    }
    //Display function
    void SavingsAccount::display(ostream& ostr) const
    {
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << "Account type: Saving" << endl;
        ostr << "Balance: $ " << getBalance() << endl;
        ostr << "Interest Rate (%): " << m_interestRate*100 << endl;
    }
}