/***********************************************************
// OOP244 Workshop 9: Classes with Resources Review
// File String.cpp
// Version 1.0
// Date 2017-07-27
// Author Galina Erostenko
// Description
// Implementation file for the class String
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String(int capacity);
    //
    // initialize the string with an internal buffer capacity of 
    // "capacity." 
    // default capacity is 1 (minimum needed for an empty string)
    //
    // 
    String::String(int capacity){
        m_pString = new char[m_capacity = capacity];
        m_pString[0] = '\0';
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const char* p, int capacity);
    //
    // Construct a String from a char array
    // Should initialize the internal buffer to at least 
    // the length of the string need to hold pSource, 
    // or capacity, whichever is greater.
    //
    // 
    String::String(const char* pSource, int capacity){
        int strLength = strlen(pSource) + 2;
        if (capacity >= strLength)
            m_capacity = capacity;
        else
            m_capacity = strLength;
        m_pString = new char[m_capacity];
        strcpy(m_pString, pSource);
        
    }
    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 
    String::String(const String& other, int capacity)
    {
        int othersLength = other.length() + 1;
        if (othersLength <= capacity)
            m_capacity = capacity;
        else
            m_capacity = othersLength;

        m_pString = nullptr;
        m_pString = new char[m_capacity];
        strcpy(m_pString, other.m_pString); 
    }
    //////////////////////////////////////////////////////
    //
    // String::resize(int newsize)
    //
    // resize the internal buffer to the value given
    // do NOT shrink the string buffer smaller than 
    // that needed to hold the existing string!
    // (length + 1);
    //    

    void String::resize(int newCapacity)
    {
        int strLength = strlen(m_pString)+2;
        if (strLength <= newCapacity)
            m_capacity = strLength;
        else
            m_capacity = newCapacity;

            String tmp(m_capacity);
            strcpy(tmp.m_pString, m_pString);
            delete[] m_pString;
            m_pString = new char[m_capacity];
            strcpy(m_pString, tmp.m_pString);
        
    }
    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    // 
    String& String::operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] m_pString;
            m_pString = new char[m_capacity = other.m_capacity+1];
            strcpy(m_pString, other.m_pString);
        }
        return *this;
    }


    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 
    String::~String()
    {
        delete[] m_pString;
        m_pString = nullptr;
    }

    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 
    int String::length() const
    {
        return strlen(m_pString);
    }


    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 
    String::operator const char *() const
    {
        return m_pString;
    }
    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.
    bool String::empty() const
    {
        return length() == 0;
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //     
    String::operator bool() const
    {
        return !empty();
    }
     
     
    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //      
    bool String::operator==(const String& s2) const
    {
        return strcmp(m_pString, s2.m_pString) == 0;
    }

    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    // 
    String& String::operator+=(const String& s2)
    {
        *this = (*this + s2);
        return *this;
    }
    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    // 
    String String::operator+(const String& s2) const
    {
        char* tmp = new char[m_capacity + s2.m_capacity +1];
        tmp[0] = '\0';
        strcat(tmp, m_pString);
        strcat(tmp, s2.m_pString);

        return tmp;

  
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // Grows the string buffer if necessary.
    //  
    String& String::operator+= (char c)
    {

        if (m_capacity < length() + 2)
            m_capacity = length() + 2;

            char tmp[2];
            tmp[0] = c;
            tmp[1] = '\0';
            resize(m_capacity);
            strcat(m_pString, tmp);

        return *this;
    }

    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    // 
    std::ostream& operator<<(std::ostream& ostream, const String &s)
    {
        ostream << (const char *)s;
        return ostream;

    }

    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 
    std::istream& operator>>(std::istream& istream, String &s)
    {
        s = "";
        char tempC = 0;
        do
        {
            tempC = istream.get();
            if (tempC != '\n')
            {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }

  
}
