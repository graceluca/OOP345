/***********************************************************************
// OOP345 Assignment 2, barbarian module
//
// File	barbarian.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the barbarian module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning barbarian module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
namespace seneca {
    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public characterTpl {
        private:
            int m_baseDefense;
            int m_baseAttack;
            Ability_t m_ability;
            Weapon_t m_weapon[2];
        public: 
            Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
            Barbarian(const Barbarian& other);
            int getAttackAmnt() const override;
            int getDefenseAmnt() const override;
            Character* clone() const override;
            void attack(Character* enemy) override;
            void takeDamage(int dmg) override;

    }
}
#endif