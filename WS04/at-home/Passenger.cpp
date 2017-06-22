/***********************************************************
// OOP244 Workshop 4: Constructors
// File w4_at_home.cpp
// Version 1.0
// Date 2016-06-09
// Author Galina Erostenko
// Description
// Implementation file for the class Passenger
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: add your headers here 
#include <iostream>
#include"Passenger.h"
#include <cstring>

using namespace std;

// TODO: continue your namespace here
namespace sict {
    //Set to empty state
    void Passenger::set()
    {
        *m_passName = 0;
        *m_dest = 0;
        m_depYear = 0;
        m_depMonth = 0;
        m_depDay = 0;
    }
    //String copying function
    void Passenger::copyString(const char* name, const char* destin)
    {
        m_passName[0] = '\0';
        m_dest[0] = '\0';
        strncpy(m_passName, name, strlen(name));
        m_passName[strlen(name)] = '\0';
        strncpy(m_dest, destin, strlen(destin));
        m_dest[strlen(destin)] = '\0';
    }

    // TODO: implement the default constructor here
    Passenger::Passenger()
    {
        set();
    }

    // TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(const char* name, const char* destin)
    {
        if (isValidString(name, destin))
        {       
            copyString(name, destin);
            m_depYear = 2017;
            m_depMonth = 7;
            m_depDay = 1;
        }
        else
        {
            set();
        }
        
    }
    //Constructor with 5 arguments
    Passenger::Passenger(const char* name, const char* destin, int year, int month, int day)
    {
        if (isValidTime(year, month, day) && isValidString(name, destin))
        {
            copyString(name, destin);
            m_depYear = year;
            m_depMonth = month;
            m_depDay = day;
        }
        else
        {
            set();
        }

    }
    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const 
    {
        return (*m_passName == 0 && *m_dest == 0);

    }
    // TODO: implement display query here
    void Passenger::display() const 
    {
        cout << m_passName << " - " << m_dest << " on " << m_depYear << "/";
        cout.fill('0');
        cout.width(2);
        cout << m_depMonth << "/" << m_depDay << endl;
    }
    //Validation query for string
    bool Passenger::isValidString(const char* name, const char* destin) const
    {
        return (name != nullptr && destin != nullptr && name[0] != '\0' && destin[0] != '\0');
    }
    //Validation query for Departure time
    bool Passenger::isValidTime(int year, int month, int day) const
    {
        return (year>=2017 && year <=2020 && month>=1 && month<=12 && day>=1 && day<=31);
    }
    //Query returns the Passenger name's address
    const char* Passenger::name() const
    {
        return (m_passName);
    }
    //Checks if Current passenger and referenced passenger go same destintaion
    bool Passenger::canTravelWith(const Passenger& check) const
    {
        bool result = false;
        if (!(strcmp(check.m_dest, m_dest)) && check.m_depYear == m_depYear && check.m_depMonth == m_depMonth && check.m_depDay == m_depDay)
        {
            result = true;
        }
        return result;
    }
}
