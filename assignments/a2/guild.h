/***********************************************************************
// OOP345 Assignment 2, guild module
//
// File	team.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the guild module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/19/2026      Beginning team module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include <iostream>
#include <string>
#include "character.h"
#include "team.h"
namespace seneca {
    class Guild {
         private: 
            Character** m_members{};
            std::size_t m_numOfMembers{};
            std::string m_guildName{};
        public:
            Guild() = default;
            Guild(const char* name);
            virtual ~Guild();
            Guild(const Guild& other);
            Guild& operator=(const Guild& other);
            Guild(Guild&& other) noexcept;
            Guild& operator=(Guild&& other) noexcept;
            void addMember(Character* c);
            void removeMember(const std::string& c);
            Character* operator[](std::size_t idx) const;
            void showMembers() const;
    };
}
#endif