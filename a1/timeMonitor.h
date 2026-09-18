/***********************************************************************
// OOP244 workshop 9, timeMonitor module
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
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <iostream>
#include <chrono>
namespace seneca {
    class Event {
        private: 
            std::string m_name;
            std::chrono::nanoseconds m_duration;
        public: 
            std::string getName() const;
            std::chrono::nanoseconds getDuration() const;
            Event();
            Event(const char* name, const std::chrono::nanoseconds& duration);
        friend std::ostream& operator<<(std::ostream& os, const Event& e);
    };
    int checkUnits(const std::string units);
    class timeMonitor {
        public:
            void startEvent(const char* name);
            Event stopEvent();
    }
}
#endif