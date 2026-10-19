/***********************************************************************
// OOP345 Assignment 2, guild module
//
// File	team.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the guild module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/19/2026      Beginning guild module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include "character.h"
#include "guild.h"
using namespace std;
namespace seneca {
    // creates a team with the name specified as parameter and no members
    Guild::Guild(const char* name) : Guild()  {
        m_guildName = name;
    }
    // destructor 
    Guild::~Guild() {
        if (m_members != nullptr) {
            delete[] m_members;
        }
    }
    // copy constructor 
    Guild::Guild(const Guild& other) : m_numOfMembers(other.m_numOfMembers), m_guildName(other.m_guildName) {
        if (m_numOfMembers == 0) {
            m_members = nullptr;
            return;
        }
        m_members = new Character*[m_numOfMembers];
        for (std::size_t i = 0; i < m_numOfMembers; i++) {
            if (other.m_members[i] != nullptr) {
                m_members[i] = other.m_members[i];
            }
            else {
                m_members[i] = nullptr;
            }   
        }
    }
    // copy operator 
    Guild& Guild::operator=(const Guild& other) {
        if (this != &other) {
            delete[] m_members;
            m_numOfMembers = other.m_numOfMembers;
            m_guildName = other.m_guildName;
            if (other.m_numOfMembers != 0) {
                m_members = new Character*[m_numOfMembers];
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    if (other.m_members[i] != nullptr) {
                        m_members[i] = other.m_members[i];
                    }
                    else {
                        m_members[i] = nullptr;
                    }
                }
            }
            else {
                m_members = nullptr;
            }
        }
        return *this;
    }
    // move constructor
    Guild::Guild(Guild&& other) noexcept : m_members(other.m_members), m_numOfMembers(other.m_numOfMembers), m_guildName(other.m_guildName) {
        other.m_members = nullptr;
        other.m_numOfMembers = 0;
        other.m_guildName.clear();
    }
    // move operator
    Guild& Guild::operator=(Guild&& other) noexcept {
        if (this != &other) {
            if (m_members != nullptr) {
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    delete m_members[i];
                }
                delete[] m_members;
            }
            m_members = other.m_members;
            m_numOfMembers = other.m_numOfMembers;
            m_guildName = other.m_guildName;
            other.m_members = nullptr;
            other.m_numOfMembers = 0;
            other.m_guildName.clear();
        }
        return *this;
    }
    // adds the character received as parameter to the guild ONLY IF the guild doesn't have a character with the same name.
    // add 300 hp to character's max health
    void Guild::addMember(Character* c) {
        if (!c) {
            return;
        }
        bool sameName = false;
        for (std::size_t i = 0; i < m_numOfMembers && !sameName; i++) {
            sameName = (c->getName() == m_members[i]->getName());
        }
        if (!sameName) {
            std::size_t newNumOfMembers = m_numOfMembers + 1;
            Character** newMembers = new Character*[newNumOfMembers];
            for (std::size_t i = 0; i < m_numOfMembers; i++) {
                newMembers[i] = m_members[i]; 
            }
            c->setHealthMax(c->getHealthMax() + 300);
            newMembers[m_numOfMembers] = c;
            delete[] m_members; 
            m_members = newMembers;
            m_numOfMembers = newNumOfMembers;
        }
    }
    // searches the guild for a character with the name received as parameter and removes it from the guild
    // if fgound, decrease max health of the character by 300 points
    void Guild::removeMember(const std::string& c) {
        std::size_t index = m_numOfMembers;
        for (std::size_t i = 0; i < m_numOfMembers; i++) {
            if (m_members[i]->getName() == c) {
                index = i;
                break;
            }
        }
        if (index != m_numOfMembers) {
            m_members[index]->setHealthMax(m_members[index]->getHealthMax() - 300);
            for (std::size_t i = index; i < m_numOfMembers - 1; i++) {
                m_members[i] = m_members[i+1];
            }
            m_members[--m_numOfMembers] = nullptr;
        }
    }
    // returns the character at the index specified as parameter, or null if the index is out of bounds
    Character* Guild::operator[](std::size_t idx) const {
        if (idx < m_numOfMembers) {
            return m_members[idx];
        }
        else {
            return nullptr;
        }
    }
    /* prints to screen the content of current object in the format:
    [Guild] GUILD_NAME<endl>
        1: FIRST_CHARACTER<endl>
        2: SECOND_CHARACTER<endl>
        3: THIRD_CHARACTER<endl>
        ...
    */
    void Guild::showMembers() const {
        if (!m_guildName.empty()) {
            std::cout << "[Guild] " << m_guildName << std::endl;
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
                }
        }
        else {
            std::cout << "No guild." << std::endl;
        }
    }
}