/***********************************************************************
// OOP345 Assignment 3, movie module
//
// File	movie.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the movie module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/24/2026      Beginning movie module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>
#include "mediaItem.h"
#include "movie.h"
#include "settings.h"
using namespace std;
namespace seneca {
    void Movie::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "M | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(9) << this->getYear() << " | ";
            out << std::left;
            if (g_settings.m_maxSummaryWidth > -1) {
                if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                    out << this->getSummary();
                 else
                    out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
            else
                out << this->getSummary();
                out << std::endl;
        }
        else {
            size_t pos = 0;
            out << this->getTitle() << " [" << this->getYear() << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
    }

    Movie* Movie::createItem(const std::string& strMovie) {
        if (strMovie.empty() || strMovie[0] == '#') {
            throw std::invalid_argument("Not a valid movie.");
        }
        std::size_t indexA, indexB;

        // find the title
        indexA = strMovie.find(',');
        std::string title = strMovie.substr(0, indexA);

        // find the year
        indexA = strMovie.substr(indexA, strMovie.length()).find_first_not_of(' ');
        indexB = strMovie.find(',', indexA);
        unsigned short year = std::stoi(strMovie.substr(indexA, indexB), nullptr);

        // find the summary
        indexA = strMovie.substr(indexB, strMovie.length()).find_first_not_of(' ');
        std::string summary = strMovie.substr(indexA);
        
        return new Movie(title,summary,year);
    }
}
