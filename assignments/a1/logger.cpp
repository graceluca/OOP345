/***********************************************************************
// OOP345 Assignment 1, logger module
//
// File	logger.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the logger module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  10/06/2026      Adding in the rest of it
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "logger.h"
#include "timeMonitor.h"
using namespace std;
namespace seneca {
    Logger::Logger() {
        m_events = nullptr;
        m_capacity = 0;
        m_numOfEvents = 0;
    }

    Logger::~Logger() {
        if (m_events != nullptr) {
            delete[] m_events;
            m_events = nullptr;
        }
    }

    Logger::Logger(Logger&& L) noexcept {
        m_events = nullptr;
        *this = std::move(L);
    }

    Logger& Logger::operator=(Logger&& L) noexcept {
        if (this != &L) {
            delete[] m_events;
            m_events = L.m_events;
            m_capacity = L.m_capacity;
            m_numOfEvents = L.m_numOfEvents;
            delete[] L.m_events;
            L.m_events = nullptr;
        }
        return *this;
    }

    void Logger::addEvent(const Event& event) {
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        Event* newEvents = new Event[m_capacity];
        for (std::size_t i = 0; i < m_numOfEvents; i++) {
            newEvents[i] = m_events[i];
        }
        delete[] m_events;
        m_events = newEvents;
        m_events[m_numOfEvents] = event;
        m_numOfEvents++;
    }

    std::ostream& operator<<(std::ostream& os, const Event& event) {
        os << event << std::endl;
        return os;
    }
}