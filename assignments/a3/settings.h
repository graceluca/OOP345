/***********************************************************************
// OOP345 Assignment 3, settings module
//
// File	settings.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the settings module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/17/2026      Beginning settings module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
#include <iostream>
#include <cstdint>
namespace seneca {
    struct Settings {
        std::int16_t m_maxSummaryWidth;
        bool m_tableView;
    };
    extern Settings g_settings;
}
#endif
