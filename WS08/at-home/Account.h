#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account{
		private:
			double m_balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
            //Default constructor
            Account();
			// TODO: Write a prototype for constructor which initializes balance
            Account(double balance);
			// TODDO: Write a function prototype for the virtual function credit 
            virtual void credit(double addAmount);
			// TODO: Write a function prototype for the virtual function debit
            virtual bool debit(double deductAmount);
			// TODO: Write a function prototype for the virtual function display	
            virtual void display(ostream& ostr) const = 0;
   };
};
#endif
