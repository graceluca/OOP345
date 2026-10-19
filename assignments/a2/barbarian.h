/***********************************************************************
// OOP345 Assignment 2, barbarian module
//
// File	barbarian.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers AND code for the barbarian module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning barbarian module
// Grace Currier-Moritsugu  10/19/2026      Moving code from the .cpp files into here
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
namespace seneca {
    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpl<T> {
        private:
            int m_baseAttack;
            int m_baseDefense;
            Ability_t m_ability;
            Weapon_t m_weapon[2];
        public: 
            // constructor using passed values
            Barbarian(const char* name, 
                int healthMax, int baseAttack, 
                int baseDefense, 
                Weapon_t primaryWeapon, Weapon_t secondaryWeapon) 
                : CharacterTpl<T>(name, healthMax), 
                    m_baseAttack(baseAttack), m_baseDefense(baseDefense),  
                    m_weapon{ primaryWeapon, secondaryWeapon } 
                    {
                    }
            // copy constructor (for clone function)
            Barbarian(const Barbarian& other) 
                : CharacterTpl<T>(other), 
                    m_baseAttack(other.m_baseAttack), m_baseDefense(other.m_baseDefense), 
                    m_weapon{other.m_weapon[0], other.m_weapon[1]}
                    {
                    }
            // returns the damage that character can do in an attack, 
            // assuming that Weapon_t supports converting to double
            int getAttackAmnt() const override {
                return (m_baseAttack + (static_cast<double>(m_weapon[0]) / 2) + (static_cast<double>(m_weapon[1]) / 2));
            }
            // return the base defense value
            int getDefenseAmnt() const override {
                return m_baseDefense;
            }
            // dynamically creates a copy of the current instance and returns its address to the client.
            // calls copy constructor
            Character* clone() const override {
                return new Barbarian(*this);
            }
            // attacks the enemy received as parameter and inflicts damage to it
            void attack(Character* enemy) override {
                std::cout << this->getName() <<  " is attacking " << enemy->getName() << "." << std::endl;
                m_ability.useAbility(this);
                int damage = this->getAttackAmnt();
                m_ability.transformDamageDealt(damage);
                std::cout << "    Barbarian deals " << damage << " melee damage!" << std::endl;
                enemy->takeDamage(damage);
            }
            // some other character inflicts damage to the current barbarian in the amount specified as parameter
            void takeDamage(int dmg) override {
                std::cout 
                    << this->getName() << " is attacked for " << dmg << " damage." << std::endl
                    << "    Barbarian has a defense of " << this->getDefenseAmnt() << ". Reducing damage received." << std::endl;
                dmg -= this->getDefenseAmnt();
                dmg = std::max(dmg, 0);
                m_ability.transformDamageReceived(dmg);
                CharacterTpl<T>::takeDamage(dmg);
            }
    };
}
#endif