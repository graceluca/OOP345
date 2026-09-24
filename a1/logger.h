/***********************************************************************
// OOP244 workshop 9, Dictionary module
//
// File	logger.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the logger module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/24/2026      Beginning logger module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include <iostream>
namespace seneca {
    class Logger {
        private:
            Event* m_events;
            std::size_t numOfEvents;
        public:
            Logger() = default;
            ~Logger();
            Logger(const Logger& L) = delete;
            Logger& operator=(const Logger& L) noexcept;
            void addEvent(const Event& E);
            friend std::ostream& operator<<(std::ostream& os, const Event& E);
    }
}
#endif