// OOP244 Workshop 7: Derived Classes
// File: hero.h
// Version: 1.0
// Date: 2017/04/07
// Author: Galina Erostenko
// Description:
// Header file for the workshop 7
/////////////////////////////////////////////

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>
    class Hero {
    private:
        char m_name[41];
        int  m_attack;
        int  m_maximumHealth;
        int  m_health;

        bool isEmpty() const;


    public:
        // constructors
        Hero();
        Hero(const char name[], int maximumHealth, int attack);

        // member functions
        void emptyHero();
        void respawn();
        bool isAlive() const;
        int  getAttack() const;
        void deductHealth(int);
        std::ostream& display(std::ostream& ostr) const;

        // friend helper function to insert name into ostream
        friend std::ostream& operator<<(std::ostream& ostr, const Hero& h);
    };

    void applyDamage(Hero& A, Hero& B);
    const Hero & operator*(const Hero &, const Hero &);

#endif
