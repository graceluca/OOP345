/***********************************************************************
// OOP345 Assignment 2, archer module
//
// File	archer.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the archer module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/14/2026      Beginning archer module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <algorithm>
#include "character.h"
#include "characterTpl.h"
#include "archer.h"
using namespace std;
namespace seneca {
    // magic numbers are bad practice, defining them here means that it's more obvious what they do
    constexpr double attackMult = 1.3;
    constexpr double defenseMult = 1.2;

    // constructor using passed values
    template <typename Weapon_t>
    Archer<Weapon_t>::Archer(const char* name, 
        int healthMax, int baseAttack, int baseDefense, 
        Weapon_t weapon) 
        : CharacterTpl(name, healthMax), 
            m_baseAttack(baseAttack), m_baseDefense(baseDefense),  
            m_weapon(weapon)
        {
        }
    // copy constructor (for clone function)
    template <typename Weapon_t>
    Archer<Weapon_t>::Archer(const Archer& other) :
        CharacterTpl(other), 
            m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense),
            m_weapon(other.m_weapon) 
            {
            }
    // returns the damage that the character can do in an attack. the weapon is ignored
    template <typename Weapon_t>
    int Archer<Weapon_t>::getAttackAmnt() const {
        return (attackMult*m_baseAttack);
    }
    // return the defense of the character
    template <typename Weapon_t>
    int Archer<Weapon_t>::getDefenseAmnt() const {
        return (defenseMult*m_baseDefense);
    }
    // dynamically creates a copy of the current instance and returns its address to the client
    template <typename Weapon_t>
    Character* Archer<Weapon_t>::clone() const {
        return new Character(*this);
    }
    // attacks the enemy received as a parameter and inflicts damage to it
    template <typename Weapon_t>
    void Archer<Weapon_t>::attack(Character* enemy) {
        std::cout << Character::getName() << " is attacking " << enemy.getName() << "." << std::endl;
        int damage = getAttackAmnt();
        std::cout << "Archer deals " << damage << " ranged damage!" << std::endl;
        enemy.takeDamage(damage);
    }
    // some other character inflicts damage to the current archer in the amount specified as parameter.
    // modifies the damage received using the defense capabilities before calling the base class member
    // to update the health
    template <typename Weapon_t>
    void Archer<Weapon_t>::takeDamage(int dmg) {
        int defense = getDefenseAmnt();
        std::cout 
            << Character::getName() << " is attacked for " << dmg << " damage." << std::endl
            << "Archer has a defense of " << defense << ". Reducing damage received." << std::endl;
        dmg -= defense;
        dmg = std::max(dmg, 0);
        CharacterTpl::takeDamage(dmg);

    }
}