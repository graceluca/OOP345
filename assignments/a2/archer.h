/***********************************************************************
// OOP345 Assignment 2, archer module
//
// File	archer.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the archer module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning archer module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
namespace seneca {
    template <typename Weapon_t>
    class Archer : public CharacterTpl {
        private:
            int m_baseDefense;
            int m_baseAttack;
            Weapon_t m_weapon;
        public:
            Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
            Archer(const Archer& other);
            int getAttackAmnt() const override;
            int getDefenseAmnt() const override;
            Character* clone() const override;
            void attack(Character* enemy) override;
            void takeDamage(int dmg);
    }
}
#endif