// OOP244 Workshop 7: Derived Classes
// File: hero.h
// Version: 1.0
// Date: 2017/04/07
// Author: Galina Erostenko
// Description:
// Header file for the workshop 7
/////////////////////////////////////////////

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

    class SuperHero : public Hero {
        int m_superPowerAttackBonus; // superpower:  attack bonus
        int m_superPowerDefendBonus;      // superpower:  defense

    public:
        // constructors  
        SuperHero();
        SuperHero(const char* name,
            int maximumHealth,
            int attack,

            int superPowerAttack,
            int superPowerDefend);

        int getAttack() const;
        int getDefend() const;
    };

    void applyDamage(SuperHero& A, SuperHero& B);
    const SuperHero & operator*(const SuperHero &, const SuperHero &);

#endif
