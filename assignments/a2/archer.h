/***********************************************************************
// OOP345 Assignment 2, archer module
//
// File	archer.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers AND code for the archer module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning archer module
// Grace Currier-Moritsugu  10/19/2026      Moving code from the .cpp files into here
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include <algorithm>
#include "character.h"
#include "characterTpl.h"
#include "health.h"
namespace seneca {
    template <typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        private:
            int m_baseDefense;
            int m_baseAttack;
            Weapon_t m_weapon;
        public:
            // constructor using passed values
            Archer(const char* name, 
                int healthMax, int baseAttack, int baseDefense, 
                Weapon_t weapon) 
                : CharacterTpl(name, healthMax), 
                    m_baseAttack(baseAttack), m_baseDefense(baseDefense),  
                    m_weapon(weapon)
                {
                }
            // copy constructor (for clone function)
            Archer(const Archer& other) :
                CharacterTpl(other), 
                m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense),
                m_weapon(other.m_weapon) 
                {
                }
            int getAttackAmnt() const override {
                return (1.3*m_baseAttack);
            }
            int getDefenseAmnt() const override {
                return (1.2*m_baseDefense);
            }
            // dynamically creates a copy of the current instance and returns its address to the client
            Character* clone() const override {
                return new Archer(*this);
            }
            // attacks the enemy received as a parameter and inflicts damage to it
            void attack(Character* enemy) override {
                std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
                int damage = this->getAttackAmnt();
                std::cout << "Archer deals " << damage << " ranged damage!" << std::endl;
                enemy->takeDamage(damage);
            }
            // some other character inflicts damage to the current archer in the amount specified as parameter.
            // modifies the damage received using the defense capabilities before calling the base class member
            // to update the health
            void takeDamage(int dmg) {
                int defense = this->getDefenseAmnt();
                std::cout 
                    << this->getName() << " is attacked for " << dmg << " damage." << std::endl
                    << "Archer has a defense of " << defense << ". Reducing damage received." << std::endl;
                dmg -= defense;
                dmg = std::max(dmg, 0);
                CharacterTpl<SuperHealth>::takeDamage(dmg);
            }
    };
}
#endif