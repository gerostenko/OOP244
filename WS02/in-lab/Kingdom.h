/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 2017-05-25
// Author Galina Erostenko
// Description
//The program accepts numbers of kingdoms and returns the first one
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H__
#define SICT_KINGDOM_H__


// TODO: sict namespace
namespace sict {

    // TODO: define the structure Kingdom in the sict namespace
    struct Kingdom {
        char m_name[32];
        int m_population;
    };
    // TODO: declare the function display(...),
    //         also in the sict namespace
    void display(const Kingdom& object);
}
#endif

