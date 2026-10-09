/***********************************************************************
// OOP345 Assignment 2, characterTpl module
//
// File	characterTpl.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the characterTpl module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/09/2026      Beginning characterTpl module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "character.h"
#include "characterTpl.h"
using namespace std;
namespace seneca {
    template <typename T>
    CharacterTpl<T>::CharacterTpl(const char* name, const int health) : 
        Character(name), m_healthMax(health), m_health(health) {
        }
    template <typename T>
    CharacterTpl<T>::CharacterTpl(const CharacterTpl& other) :
        Character(other.getName()), m_healthMax(other.getHealth()), m_health(other.getHealth()) {
    }
    template <typename T>
    void CharacterTpl<T>::takeDamage(int dmg) {
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
    template <typename T> 
    int CharacterTpl<T>::getHealth() const {
        return m_health;
    }
    template <typename T> 
    int CharacterTpl<T>::getHealthMax() const {
        return m_healthMax;
    }
    template <typename T> 
    void CharacterTpl<T>::setHealth(int health) {
        m_health = health;
    }
    template <typename T> 
    void CharacterTpl<T>::setHealthMax(int health) {
        m_healthMax = health;
    }
}