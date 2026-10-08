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
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
namespace seneca {

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