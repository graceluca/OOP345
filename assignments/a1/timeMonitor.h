/***********************************************************************
// OOP244 Assignment 1, timeMonitor module
//
// File	timeMonitor.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the timeMonitor module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor..
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning timeMonitor module
// Grace Currier-Moritsugu  10/06/2026      Fixing units in getDuration
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>
#include <chrono>
namespace seneca {
    class Event {
        private: 
            std::string m_name{};
            std::chrono::nanoseconds m_duration{};
        public: 
            Event() = default;
            Event(const char* name, const std::chrono::nanoseconds& duration);
            std::string getName() const;
            int getDuration(const std::string units) const;
            friend std::ostream& operator<<(std::ostream& os, const Event& e);
    };
    int checkUnits(const std::string units);
}
#endif

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <iostream>
#include <chrono>
namespace seneca {
    
    class TimeMonitor {
        private:    
            char* m_name = nullptr;
            std::chrono::nanoseconds m_start{};
            std::chrono::nanoseconds m_end{};
        public:
            TimeMonitor() = default;
            ~TimeMonitor();
            void startEvent(const char* name);
            Event stopEvent();
    };
}
#endif  

