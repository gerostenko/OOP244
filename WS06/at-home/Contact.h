// OOP244 Workshop 6: class with resources
// File: w6_at_home.cpp
// Version: 1.0
// Date: 2017/28/06
// Author: Galina Erostenko
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__
#define SIZE 20

namespace sict {
    class Contact{
    private:
        char m_name[SIZE];
        long long *m_phone;
        int m_size;
        void setEmptyState();
        char* copyName(const char* right);
    public:
        Contact();
        Contact(const char* name, const long long* phone, int size);
        Contact(const Contact& obj);
        bool isValid(const long long* phone) const;
        int countryCode(const long long* phone) const;
        int areaCode(const long long* phone) const;
        int phoneNum(const long long* phone) const;
        ~Contact();
        bool isEmpty() const;
        void display() const;
        Contact& operator=(const Contact& obj);
        Contact& operator+=(long long newPhone);
    };


}
#endif