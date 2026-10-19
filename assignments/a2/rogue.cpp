/***********************************************************************
// OOP345 Assignment 2, rogue module
//
// File	rogue.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the rogue module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/14/2026      Beginning rogue module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <algorithm>
#include "character.h"
#include "characterTpl.h"
#include "rogue.h"
using namespace std;
namespace seneca {
    // initializes a new object to the values receives received as parameters
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, 
        int healthMax, int baseAttack, int baseDefense) 
        : CharacterTpl<T>(name, healthMax), 
            m_baseAttack(baseAttack), m_baseDefense(baseDefense)
        {
        }
    // copy constructor (for clone function)
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const Rogue& other) : 
        CharacterTpl<T>(other), 
        m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense)
    {
    }
    // returns the damage that character can do in an attack
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
        return m_baseAttack+(2*static_cast<double>(m_weapon));
    }
    // returns the base defense value.
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
        return m_baseDefense;
    }
    // dynamically creates a copy of the current instance and returns its address to the client
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
        return new Character(*this);
    }
    // attacks the enemy received as parameter and inflicts damage to it
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
        m_firstAbility.useAbility(*this);
        m_secondAbility.useAbility(*this);
        int damage = getAttackAmnt();
        m_firstAbility.transformDamageDealt(&damage);
        m_secondAbility.transformDamageDealt(&damage);
        std::cout << "Rogue deals " << damage << " melee damage!" << std::endl;
        enemy->takeDamage(damage);
    }
    // some other character inflicts damage to the current rogue in the amount specified as parameter.
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
        std::cout 
            << this->getName() << " is attacked for " << dmg << " damage." << std::endl
            << "Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
        dmg -= getDefenseAmnt();
        dmg = std::max(dmg, 0);
        m_firstAbility.transformDamageReceived(&dmg);
        m_secondAbility.transformDamageReceived(&dmg);
        this->takeDamage(dmg);
    }
}