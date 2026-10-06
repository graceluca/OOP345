/***********************************************************************
// OOP345 Assignment 1, Settings module
//
// File	settings.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the settings module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor..
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning settings module
// Grace Currier-Moritsugu  10/06/2026      Fixing default aspects
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
#include <iostream>
#include <chrono>
#include <string>
namespace seneca {

    class Settings {
        public:
            bool m_show_all = false;
            bool m_verbose = false;
            std::string m_time_units = "nanoseconds";
            Settings() = default;
    };
    
    
    #pragma once
    extern Settings g_settings;

}
#endif