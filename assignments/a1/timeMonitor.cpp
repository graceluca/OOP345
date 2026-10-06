/***********************************************************************
// OOP345 Assignment 1, timeMonitor module
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
// Grace Currier-Moritsugu  10/06/2026      Fixing units in getDuration
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "timeMonitor.h"
#include "settings.h"
#include <iostream>
#include <iomanip>
#include <cstring>
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

    int Event::getDuration(const std::string units) const {
        int intUnit;
        if (units == "seconds") {
            intUnit = std::chrono::duration_cast<std::chrono::seconds>(m_duration).count();
        }
        else if (units == "milliseconds") {
            intUnit = std::chrono::duration_cast<std::chrono::milliseconds>(m_duration).count();
        }
        else if (units == "microseconds") {
            intUnit = std::chrono::duration_cast<std::chrono::microseconds>(m_duration).count();
        }
        else if (units == "nanoseconds") {
            intUnit = m_duration.count();
        }
        return intUnit;
        
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
        int count = 0;
        os << std::setw(2) << std::right << ++count << ":" 
            << std::setw(40) << e.getName()
            << " -> " << std::setw(checkUnits(seneca::g_settings.m_time_units)) 
            << e.getDuration(seneca::g_settings.m_time_units) 
            << " "
            << seneca::g_settings.m_time_units;
        return os;
    }

    TimeMonitor::~TimeMonitor() {
        delete[] m_name;
        m_name = nullptr;
    }

    void TimeMonitor::startEvent(const char* name) {
        delete[] m_name;
        m_name = nullptr;
        m_name = new char[std::strlen(name) + 1];
        std::strcpy(m_name, name);
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch(); 
        m_start = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    }

    Event TimeMonitor::stopEvent() {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        m_end = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
        Event e(m_name, m_end - m_start);
        return e;
    }   

    
    


    
}