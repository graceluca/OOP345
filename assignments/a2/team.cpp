/***********************************************************************
// OOP345 Assignment 2, team module
//
// File	team.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the team module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/16/2026      Beginning team module
// Grace Currier-Moritsugu  10/19/2026      Fixed issue in removeMember deallocating the character instead of just removing it
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include "character.h"
#include "team.h"
using namespace std;
namespace seneca {
    // creates a team with the name specified as parameter and no members
    Team::Team(const char* name) : Team()  {
        m_teamName = name;
    }
    // destructor 
    Team::~Team() {
        if (m_members != nullptr) {
            for (std::size_t i = 0; i < m_numOfMembers; i++) {
                delete m_members[i];
            }
            delete[] m_members;
        }
    }
    // copy constructor 
    Team::Team(const Team& other) : m_numOfMembers(other.m_numOfMembers), m_teamName(other.m_teamName) {
        if (m_numOfMembers == 0) {
            m_members = nullptr;
            return;
        }
        m_members = new Character*[m_numOfMembers];
        for (std::size_t i = 0; i < m_numOfMembers; i++) {
            if (other.m_members[i] != nullptr) {
                m_members[i] = other.m_members[i]->clone();
            }
            else {
                m_members[i] = nullptr;
            }   
        }
    }
    // copy operator 
    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            if (m_members != nullptr) {
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    delete m_members[i];
                }
                delete[] m_members;
            }
            m_numOfMembers = other.m_numOfMembers;
            m_teamName = other.m_teamName;
            if (other.m_numOfMembers != 0) {
                m_members = new Character*[m_numOfMembers];
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    if (other.m_members[i] != nullptr) {
                        m_members[i] = other.m_members[i]->clone();
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
    Team::Team(Team&& other) noexcept : m_members(other.m_members), m_numOfMembers(other.m_numOfMembers), m_teamName(other.m_teamName) {
        other.m_members = nullptr;
        other.m_numOfMembers = 0;
        other.m_teamName.clear();
    }
    // move operator
    Team& Team::operator=(Team&& other) noexcept {
        if (this != &other) {
            if (m_members != nullptr) {
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    delete m_members[i];
                }
                delete[] m_members;
            }
            m_members = other.m_members;
            m_numOfMembers = other.m_numOfMembers;
            m_teamName = other.m_teamName;
            other.m_members = nullptr;
            other.m_numOfMembers = 0;
            other.m_teamName.clear();
        }
        return *this;
    }
    // adds the character received as parameter to the team ONLY IF the team doesn't have a character with the same name
    void Team::addMember(const Character* c) {
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
            newMembers[m_numOfMembers] = c->clone();
            delete[] m_members; 
            m_members = newMembers;
            m_numOfMembers = newNumOfMembers;
        }
    }
    // searches the team for a character with the name received as parameter and removes it from the team
    void Team::removeMember(const std::string& c) {
        std::size_t index = m_numOfMembers;
        for (std::size_t i = 0; i < m_numOfMembers; i++) {
            if (m_members[i]->getName() == c) {
                index = i;
                break;
            }
        }
        if (index != m_numOfMembers) {
            delete m_members[index];
            for (std::size_t i = index; i < m_numOfMembers - 1; i++) {
                m_members[i] = m_members[i+1];
            }
            m_members[--m_numOfMembers] = nullptr;
        }
    }
    //  returns the character at the index specified as parameter, or null if the index is out of bounds
    Character* Team::operator[](size_t idx) const {
        if (idx < m_numOfMembers) {
            return m_members[idx];
        }
        else {
            return nullptr;
        }
    }
    /* prints to screen the content of current object in the format:
    [Team] TEAM_NAME<endl>
        1: FIRST_CHARACTER<endl>
        2: SECOND_CHARACTER<endl>
        3: THIRD_CHARACTER<endl>
        ...
    */
    void Team::showMembers() const {
        if (!m_teamName.empty()) {
            std::cout << "[Team] " << m_teamName << std::endl;
                for (std::size_t i = 0; i < m_numOfMembers; i++) {
                    std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
                }
        }
        else {
            std::cout << "No team." << std::endl;
        }
    }
}