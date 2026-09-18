/***********************************************************************
// OOP244 workshop 9, Settings module
//
// File	settings.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the C++ code for the settings module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor..
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning settings module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "settings.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace seneca {
    seneca::Settings() 
        : m_show_all(false), m_verbose(false), m_time_units("nanoseconds") {}   

}