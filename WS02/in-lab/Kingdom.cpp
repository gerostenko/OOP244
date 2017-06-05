/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2017-05-25
// Author Galina Erostenko
// Description
// The program accepts numbers of kingdoms and returns the first one
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
using namespace std;
#include "Kingdom.h"

// TODO: the sict namespace
namespace sict {
    // TODO:definition for display(...) 
    void display(const Kingdom& object)
    {
        //KINGDOM_NAME, population POPULATION<ENDL>
        cout << object.m_name << ", " << "population " << object.m_population << endl;
    }
}
