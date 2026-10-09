/***********************************************************************
// OOP345 Assignment 2, characterTpl module
//
// File	characterTpl.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the characterTpl module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning characterTpl module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"
namespace seneca {
    template <typename T>
    class CharacterTpl : public Character {
        private:
            int m_healthMax;
            T m_health;
        public:
            CharacterTpl(const char* name, const int health);
            CharacterTpl(const CharacterTpl& other)
            void takeDamage(int dmg) override;
            int getHealth() const override;
            int getHealthMax() const override;
            void setHealth(int health) override;
            void setHealthMax(int health) override;
    }
}
#endif