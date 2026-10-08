/***********************************************************************
// OOP244 Assignment 1, Event module
//
// File	event.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the event module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor..
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/08/2026      Moving event stuff from timeMonitor.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "settings.h"
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
namespace seneca {
    Event::Event(const char* name, const std::chrono::nanoseconds& duration) {
        m_name = name;
        m_duration = duration;
    }

    std::string Event::getName() const{
        return m_name;
    }

    long long Event::getDuration(const std::string units) const {
        long long longUnit = 0;
        if (units == "seconds") {
            longUnit = std::chrono::duration_cast<std::chrono::seconds>(m_duration).count();
        }
        else if (units == "milliseconds") {
            longUnit = std::chrono::duration_cast<std::chrono::milliseconds>(m_duration).count();
        }
        else if (units == "microseconds") {
            longUnit = std::chrono::duration_cast<std::chrono::microseconds>(m_duration).count();
        }
        else if (units == "nanoseconds") {
            longUnit = m_duration.count();
        }
        return longUnit;
        
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

    std::ostream& operator<<(std::ostream& os, const Event& e) { 
        static int count = 0;
        os << std::setw(2) << std::right << ++count << ":" 
            << std::setw(40) << e.getName()
            << " -> " << std::setw(checkUnits(seneca::g_settings.m_time_units)) 
            << e.getDuration(seneca::g_settings.m_time_units) 
            << " "
            << seneca::g_settings.m_time_units;
        return os;
    }
}