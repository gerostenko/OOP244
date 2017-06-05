#include <iostream>
#include <string>
#include "CRA_Account.h"
using namespace std;
namespace sict {
    bool CRA_Account::isValid() const
    {
        bool result = false;
        if (m_sin > 0)
            result = true;
        return result;
    }
    void CRA_Account::set(const char* familyName, const char* givenName, long long sin)
    {
        int i;
        if (MIN_SIN <= sin && sin <= MAX_SIN)
        {
            m_sin = sin;
            for (i = 0; i <= MAX_NAME_LENGTH; i++)
            {
                m_familyName[i] = familyName[i];
                m_familyName[MAX_NAME_LENGTH + 1] = 0;
            }
            for (i = 0; i <= MAX_NAME_LENGTH; i++)
            {
                m_givenName[i] = givenName[i];
                m_givenName[MAX_NAME_LENGTH + 1] = 0;
            }
        }
        else { 
            m_sin = 0;
            *m_familyName = 0;
            *m_givenName = 0;
        }
    }
    void CRA_Account::display() const
    {
        if (isValid())
        {
            cout << "Family Name : " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
        }
        else
        {
            cout << "Account object is empty! " << endl;
        }
    }

}