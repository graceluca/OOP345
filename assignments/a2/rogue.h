/***********************************************************************
// OOP345 Assignment 2, rogue module
//
// File	rogue.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the rogue module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/14/2026      Beginning rogue module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include <iostream>
#include "character.h"
#include "characterTpl.h"
namespace seneca {
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : CharacterTpl<T> {
        private: 
            int m_baseDefense;
            int m_baseAttack;
            FirstAbility_t m_firstAbility;
            SecondAbility_t m_secondAbilty;
            seneca::Dagger m_weapon;
        public:
            Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
            Rogue(const Rogue& other);
            int getAttackAmnt() const override;
            int getDefenseAmnt() const override;
            Character* clone() const override;
            void attack(Character* enemy) override;
            void takeDamage(int dmg) override;

    };
}
#endif