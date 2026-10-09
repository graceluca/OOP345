/***********************************************************************
// OOP345 Assignment 2, barbarian module
//
// File	barbarian.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the barbarian module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning barbarian module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <algorithm>
#include "character.h"
#include "characterTpl.h"
#include "barbarian.h"
using namespace std;
namespace seneca {
    // constructor using passed values
    template <typename T, typename Ability_t, typename Weapon_t>
    Barbarian<T, Ability_t, Weapon_t>::Barbarian(const char* name, 
        int healthMax, int baseAttack, int baseDefense, 
        Weapon_t primaryWeapon, Weapon_t secondaryWeapon) 
        : CharacterTpl(name, HealthMax), 
            m_baseAttack(baseAttack), m_baseDefense(baseDefense),  
            m_weapon[0](primaryWeapon), m_weapon[1](secondaryWeapon) {
            }
    // copy constructor (for clone function)
    template <typename T, typename Ability_t, typename Weapon_t>
    Barbarian<T, Ability_t, Weapon_t>::Barbarian(const Barbarian& other) 
    : CharacterTpl(other), 
        m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense),
        {
            std::copy(std::begin(other.m_weapon), std::end(other.m_weapon), std::begin(m_weapon));
        }
    // returns the damage that character can do in an attack, 
    // assuming that Weapon_t supports converting to double
    template <typename T, typename Ability_t, typename Weapon_t>
    int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
        return (m_baseAttack + (m_weapon[0]_damage/2) + (w_weapon[1]_damage/2));
    }
    // dynamically creates a copy of the current instance and returns its address to the client.
    // calls copy constructor
    template <typename T, typename Ability_t, typename Weapon_t>
    Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
        return new Character(*this);
    }

    // attacks the enemy received as parameter and inflicts damage to it
    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
        std::cout << Character::getName() <<  " is attacking " << enemy.getName() << "." << std::endl;
        m_ability.useAbility(*this);
        int damage = getAttackAmnt;
        m_ability.transformDamageDealt(damage);
        std::cout << "Barbarian deals " << damage << " melee damage!" << std::endl;
        enemy.takeDamage(damage);
    }
    // some other character inflicts damage to the current barbarian in the amount specified as parameter
    template <typename T, typename Ability_t, typename Weapon_t>
    void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
        std::cout 
            << Character::getName() << " is attacked for " << dmg << " damage." << std::endl
            << "Barbarian has a defense of " << getDefense() << ". Reducing damage received." << std::endl;
        dmg -= getDefense();
        dmg = std::max(dmg, 0);
        m_ability.transformDamageReceived(dmg);
        takeDamage(dmg);
    }


}