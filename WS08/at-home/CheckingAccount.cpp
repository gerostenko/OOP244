/// BTP200 Workshop 8: Virtual Functions
// File: w8_at_home.cpp
// Version: 1.0
// Date: 2017/07/15
// Author: Galina Erostenko
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here
    //Default constructor
    CheckingAccount::CheckingAccount()
    {
        transactionFee = 0;
    }
    //Constructor initializes balance and transaction fee
    CheckingAccount::CheckingAccount(double balance, double fee) : Account(balance)
    {
        fee < 0 ? transactionFee = 0 : transactionFee = fee;
    }
    //credit function
    void CheckingAccount::credit(double addAmount)
    {
        Account::credit(addAmount);
        chargeFee(transactionFee);
    }
    //Subtract the fee from balance
    void CheckingAccount::chargeFee(double fee)
    {
        double newBalance = getBalance() - fee;
        setBalance(newBalance);
    }
    //debit function
    bool CheckingAccount::debit(double deductAmount)
    {
        bool returnValue = false;
        if (Account::debit(deductAmount))
        {
            chargeFee(transactionFee);
            returnValue = true;
        }
        return returnValue;
    }
    //display function
    void CheckingAccount::display(ostream& ostr) const
    {
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << "Account type: Checking" << endl;
        ostr << "Balance: $ " << getBalance() << endl;
        ostr << "Transaction Fee: " << transactionFee << endl;
    }
}