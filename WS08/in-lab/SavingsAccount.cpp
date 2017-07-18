#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
    SavingsAccount::SavingsAccount() : Account(0)
    {
        m_interestRate = 0;
    }
    SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
    {
        interestRate < 0 ? m_interestRate = 0 : m_interestRate = interestRate;
    }
    double SavingsAccount::calculateInterest()
    {
        return getBalance() * m_interestRate;
    }
    void SavingsAccount::display(ostream& ostr) const
    {
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << "Account type: Saving" << endl;
        ostr << "Balance: $ " << getBalance() << endl;
        ostr << "Interest Rate (%): " << m_interestRate*100 << endl;
    }
}