// OOP244 Workshop 6: class with resources
// File: w6_in_lab.cpp
// Version: 1.0
// Date: 2017/20/06
// Author: Galina Erostenko
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__
#define SIZE 21

namespace sict {
    class Contact{
    private:
        char m_name[SIZE];
        long long *m_phone;
        int m_size;
        void setEmptyState();
    public:
        Contact();
        Contact(const char* name, const long long* phone, int size);
        bool isValid(const long long* phone) const;
        int countryCode(const long long* phone) const;
        int areaCode(const long long* phone) const;
        int phoneNum(const long long* phone) const;
        ~Contact();
        bool isEmpty() const;
        void display() const;
    };


}
#endif