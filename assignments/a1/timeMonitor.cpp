/***********************************************************************
// OOP244 workshop 9, timeMonitor module
//
// File	timeMonitor.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the C++ code for the timeMonitor module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor..
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning timeMonitor module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "timeMonitor.h"
#include "settings.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace seneca {
    Event::Event(const char* name, const std::chrono::nanoseconds& duration) {
        m_name = name;
        m_duration = duration;
    }

    std::string Event::getName() const{
        return m_name;
    }

    std::chrono::nanoseconds Event::getDuration() const {
        return m_duration;
    }

    int checkUnits(const std::string units) {
        int s;
        if (units == "seconds") {
            s = 2;
        }
        else if (units == "milliseconds") {
            s = 5;
        }
        else if (units == "microseconds") {
            s = 8;
        }
        else if (units == "nanoseconds") {
            s = 11;
        }
        else {
            s = -1;
        }
        return s;
    };


    std::ostream& seneca::operator<<(std::ostream& os, const Event& e) { 
        int count = 0;
        os << std::setw(2) << std::right << ++count << ":" 
            << std::setw(40) << e.getName()
            << " -> " << std::setw(checkUnits(seneca::g_settings.m_time_units)) 
            << e.getDuration() 
            << " "
            << seneca::g_settings.m_time_units 
            << std::endl;
        return os;
    }
}