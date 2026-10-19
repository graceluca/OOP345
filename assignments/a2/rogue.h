/***********************************************************************
// OOP345 Assignment 2, rogue module
//
// File	rogue.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers AND code for the rogue module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/14/2026      Beginning rogue module
// Grace Currier-Moritsugu  10/19/2026      Moving code from the .cpp files into here
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "weapons.h"
namespace seneca {
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpl<T> {
        private: 
            int m_baseDefense;
            int m_baseAttack;
            FirstAbility_t m_firstAbility;
            SecondAbility_t m_secondAbility;
            seneca::Dagger m_weapon;
        public:
            // initializes a new object to the values receives received as parameters
            Rogue(const char* name, 
                int healthMax, int baseAttack, int baseDefense) 
                : CharacterTpl<T>(name, healthMax), 
                m_baseAttack(baseAttack), m_baseDefense(baseDefense)
            {
            }
            // copy constructor (for clone function)
            Rogue(const Rogue& other) : 
                CharacterTpl<T>(other), 
                m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense)
            {
            }
            // returns the damage that character can do in an attack
            int getAttackAmnt() const override {
                return m_baseAttack+(2*static_cast<double>(m_weapon));
            }
            // returns the base defense value.
            int getDefenseAmnt() const override {
                return m_baseDefense;
            }
            // dynamically creates a copy of the current instance and returns its address to the client
            Character* clone() const override {
                return new Rogue(*this);
            }
            // attacks the enemy received as parameter and inflicts damage to it
            void attack(Character* enemy) override {
                std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
                m_firstAbility.useAbility(this);
                m_secondAbility.useAbility(this);
                int damage = getAttackAmnt();
                m_firstAbility.transformDamageDealt(&damage);
                m_secondAbility.transformDamageDealt(&damage);
                std::cout << "Rogue deals " << damage << " melee damage!" << std::endl;
                enemy->takeDamage(damage);
            }
            // some other character inflicts damage to the current rogue in the amount specified as parameter.
            void takeDamage(int dmg) override {
                std::cout 
                    << this->getName() << " is attacked for " << dmg << " damage." << std::endl
                    << "Rogue has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
                dmg -= getDefenseAmnt();
                dmg = std::max(dmg, 0);
                m_firstAbility.transformDamageReceived(&dmg);
                m_secondAbility.transformDamageReceived(&dmg);
                this->takeDamage(dmg);
            }
    };
}
#endif