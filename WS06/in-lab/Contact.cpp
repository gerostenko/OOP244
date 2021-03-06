// OOP244 Workshop 6: class with resources
// File: w6_in_lab.cpp
// Version: 1.0
// Date: 2017/20/06
// Author: Galina Erostenko
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Contact.h"
#include <cstring>
using namespace std;

namespace sict {
    void Contact::setEmptyState()
    {
        m_name[0] = '\0';
        m_phone = nullptr;
        m_size = 0;
    }
    Contact::Contact()
    {
        setEmptyState();
    }
    Contact::Contact(const char* name, const long long* phone, int size)
    {
        int validNumsSize = 0, j = 0;
        if (name != nullptr && name[0] != '\0') {
            m_name[0] = '\0';
            strncpy(m_name, name, SIZE);
            m_name[SIZE - 1] = '\0';

            if (size > 0) {
                for (int i = 0; i < size; i++)
                {
                    if (isValid(&phone[i]))
                    {
                        validNumsSize++;
                    }
                }
                m_phone = new long long[m_size = validNumsSize];
                for (int i = 0; i < size; i++)
                {
                    if (isValid(&phone[i]))
                    {
                        m_phone[j] = phone[i];
                        j++;
                    }
                }
            }
            else
            {
                m_phone = nullptr;
                m_size = 0;
            }
        }
        else
        {
            setEmptyState();
        }
    }
    bool Contact::isValid(const long long* phone) const
    {
        bool result = false;
        if (countryCode(phone) < 100 && countryCode(phone) != 0 && (int)(areaCode(phone) / 100) != 0 && (int)(phoneNum(phone) / 1000000) != 0)
            result = true;
        return result;
    }
    int Contact::countryCode(const long long* phone) const
    {
        return (int)(*phone / 10000000000);
    }
    int Contact::areaCode(const long long* phone) const
    {
        return (int)((*phone % 10000000000) / 10000000);
    }
    int Contact::phoneNum(const long long* phone) const
    {
        return *phone % 10000000;
    }
    Contact::~Contact()
    {
        delete[] m_phone;

    }
    bool Contact::isEmpty() const
    {
        return (m_size == 0 && m_name[0] == '\0') ? true : false;
    }
    void Contact::display() const
    {
        if (isEmpty())
        {
            cout << "Empty contact!" << endl;
        }
        else
        {
            cout << m_name << endl;
            for (int i = 0; i < m_size; i++)
            {
                cout << "(+" << countryCode(&m_phone[i]) << ") " << areaCode(&m_phone[i]) << " ";
                cout << (int)(phoneNum(&m_phone[i]) / 10000) << "-" << phoneNum(&m_phone[i]) % 10000 << endl;
            }
        }
    }
}