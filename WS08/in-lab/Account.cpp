#include "Account.h"

using namespace std;

namespace ict{ 
	//default constructor
    Account::Account(){
        m_balance = 1;
    }
	// constructor with balance   
    Account::Account(double balance)
    {
        balance >= 0 ? m_balance = balance : m_balance = 1;

    }

	// credit (add) an amount to the account balance
    void Account::credit(double addAmount)
    {
        m_balance += addAmount;
    }
	
	// debit (subtract) an amount from the account balance return bool 
    bool Account::debit(double deductAmount)
    {
        bool returnValue = false;
        if (deductAmount <= m_balance)
        {
            m_balance -= deductAmount;
            returnValue = true;
        }
        return returnValue;
    }

	double Account::getBalance() const
	{
		return m_balance;
	} 

	void Account::setBalance( double newBalance )
	{
		m_balance = newBalance;
	} 
}