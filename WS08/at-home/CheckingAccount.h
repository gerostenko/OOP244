/// BTP200 Workshop 8: Virtual Functions
// File: w8_at_home.cpp
// Version: 1.0
// Date: 2017/07/15
// Author: Galina Erostenko
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
            void chargeFee(double fee);
		public:
            //Default constructor
            CheckingAccount();
			// TODO: constructor initializes balance and transaction fee 
            CheckingAccount(double balance, double fee); // Account(balance);
			// TODO: Write a function prototype to override credit function
            void credit(double addAmount);
			// TODO: Write a function prototype to override debit function
            bool debit(double deductAmount);
			// TODO: Write a function prototype to  override display function
            void display(ostream& ostr) const;
	};
};
#endif
