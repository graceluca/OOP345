/***********************************************************************
// OOP345 Assignment 2, characterTpl module
//
// File	characterTpl.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers AND code for the characterTpl module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning characterTpl module
// Grace Currier-Moritsugu  10/19/2026      Moving code from the .cpp files into here
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"
#include "health.h"
namespace seneca {
    template <typename T>
    class CharacterTpl : public Character {
        private:
            int m_healthMax;
            T m_health;
        public:
        // receives the name of the character and the maximum health; 
        // initializes the current instance with the values of the parameters and sets the current health to maximum.
            CharacterTpl(const char* name, const int health) : 
                Character(name), m_healthMax(), m_health() 
                {
                    m_healthMax = health;
                    m_health = health;
                }
        // copy constructor (for classes with clone functions)
            CharacterTpl(const CharacterTpl& other) :
                Character(other.getName()), m_healthMax(other.getHealth()), m_health(other.getHealth()) {
            }
        // reduces the current health by the value of the parameter.
            void takeDamage(int dmg) override {
                m_health -= dmg;
                std::cout << Character::getName() << ' ';
                if (m_health <= 0) {
                    std::cout << "has been defeated!";
                }
                else {
                    std::cout << "took " << dmg << " damage, " << m_health << " health remaining.";
                }
                std::cout << std::endl;
            }
        // returns current health
            int getHealth() const override {
                return m_health;
            }
        // returns current maximum health
            int getHealthMax() const override {
                return m_healthMax;
            }
        // sets the current health to the value received as parameter
            void setHealth(int health) override {
                m_health = health;
            }
        // sets the maximum health and current health to the value of the paramter
            void setHealthMax(int health) override {
                m_healthMax = health;
                m_health = health;
            }
    };
}
#endif