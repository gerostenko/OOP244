/***********************************************************
// OOP244 Workshop 4: Constructors
// File w4_at_home.cpp
// Version 1.0
// Date 2016-06-09
// Author Galina Erostenko
// Description
// Header file for the class Passenger
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: add header file guard here 
#ifndef SICT_PASSENGER_H__
#define SICT_PASSENGER_H__
#define SIZE 32

// TODO: declare your namespace here
namespace sict {
    // TODO: define the Passenger class here
    class Passenger
    {
    private:
        char m_passName[SIZE];
        char m_dest[SIZE];
        int m_depYear;
        int m_depMonth;
        int m_depDay;


    public:
        Passenger();
        Passenger(const char* name, const char* destin);
        Passenger(const char* name, const char* destin, int year, int month, int day);
        void set();
        void copyString(const char* name, const char* destin);
        bool isEmpty() const;
        void display() const;
        bool isValidString(const char* name, const char* destin) const;
        bool isValidTime(int year, int month, int day) const;
        const char* name() const;
        bool canTravelWith(const Passenger& check) const;
    };
}
#endif 