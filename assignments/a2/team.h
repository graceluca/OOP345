/***********************************************************************
// OOP345 Assignment 2, team module
//
// File	team.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the team module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/16/2026      Beginning team module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include <iostream>
#include <string>
#include "character.h"
namespace seneca {
    class Team {
        private: 
            Character** m_members{};
            std::size_t m_numOfMembers{};
            std::string m_teamName{};
        public:
            Team() = default;
            Team(const char* name);
            ~Team();
            Team(const Team& other);
            Team& operator=(const Team& other);
            Team(Team&& other) noexcept;
            Team& operator=(Team&& other) noexcept;
            void addMember(const Character* c);
            void removeMember(const std::string& c);
            Character* operator[](std::size_t idx) const;
            void showMembers() const;
            

    };
}
#endif