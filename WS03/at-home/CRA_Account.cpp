#include <iostream>
#include <string>
#include "CRA_Account.h"
using namespace std;
namespace sict {
    bool CRA_Account::isValid() const
    {
        int arraym_sin[9] = {0};
        long long sin = 0;
        int i = 0, sum = 0, lastDig = 0;
        bool result = false;

        sin = m_sin;

        if (sin > 0) {
            for (i = 8; i >= 0; i--) {
                if (i % 2 != 0) {
                    arraym_sin[i] = (sin % 10) * 2;

                    if (arraym_sin[i] > 9) {
                        sum += (arraym_sin[i] % 10) + (arraym_sin[i] / 10);
                    }
                    else {
                        sum += arraym_sin[i];
                    }
                }
                else if (i == 8) {
                    lastDig = sin % 10;
                }
                else {
                    arraym_sin[i] = sin % 10;
                    sum += arraym_sin[i];
                }
                sin /= 10;
            }
            if (((sum % 10) == 0) && (lastDig==0)) {
                result = true;
            }
            else if ((10 - sum % 10) == lastDig) {
                result = true;
            }
        }
        return result;
    }
    void CRA_Account::set(const char* familyName, const char* givenName, long long sin)
    {
        int i;
        if (MIN_SIN <= sin && sin <= MAX_SIN)
        {
            m_sin = sin;
            m_years = 0;
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
        int i;

        if (m_sin != 0) {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
            for (i = 0; i < m_years; i++)
            {
                cout.precision(2);
                if (m_balance[i] > 2)
                {
                    cout.setf(ios::fixed);
                    cout << "Year (" << m_year[i] << ") balance owing: " << m_balance[i] << endl;
                }
                if (m_balance[i] < -2)
                {
                    cout.setf(ios::fixed);
                    cout << "Year (" << m_year[i] << ") refund due: " << -(m_balance[i]) << endl;
                }
                if (m_balance[i] < 2 && m_balance[i] > -2)
                {
                    cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
                }
            }
        }
        else
        {
            cout << "Account object is empty! " << endl;
        }
    }

    void CRA_Account::set(int year, double balance)
    {
        if (isValid() && m_years < MAX_YRS)
        {
            m_year[m_years] = year;
            m_balance[m_years] = balance;
            m_years++;
        }

    }
}
