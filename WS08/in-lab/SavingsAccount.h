#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double m_interestRate; // interest rate (percentage) 
		public:
		
			// TODO: put prototypes here
            SavingsAccount();
            SavingsAccount(double interestRate, double balance);
            double calculateInterest();
            void display(ostream& ostr) const;

   };
};
#endif
