/***********************************************************************
// OOP345 Assignment 3, tvShow module
//
// File	tvShow.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the tvShow module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/24/2026      Beginning tvShow module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "mediaItem.h"
#include "tvShow.h"
#include "settings.h"
namespace seneca {
    TvShow::TvShow(const std::string& title, const std::string& summary, unsigned short year, const std::string id) : 
        mediaItem(title,summary,year), m_id(id)
    {
        m_episodes
    }

    void TvShow::display(std::ostream& out) const {
        if (g_settings.m_tableView)
        {
            out << "S | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_episodes.size() << " | ";
            out << std::setw(4) << this->getYear() << " | ";
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
            while (pos < this->getSummary().size()) {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            for (auto& item : m_episodes) {
                out << std::setfill('0') << std::right;
                out << "    " << 'S' << std::setw(2) << item.m_season
                << 'E' << std::setw(2) << item.m_numberInSeason << ' ';
                if (item.m_title != "")
                    out << item.m_title << '\n';
                else
                    out << "Episode " << item.m_numberOverall << '\n';
                pos = 0;
                while (pos < item.m_summary.size())
                {
                    out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
                    pos += g_settings.m_maxSummaryWidth - 8;
                }
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
    }

    TvShow* TvShow::createItem(const std::string& strShow) {
        if (strShow.empty() || strShow[0] == '#') {
            throw std::invalid_argument("Not a valid show.");
        }
        std::size_t indexA, indexB;

        // find the id
        indexA = strShow.find(',');
        std::string id = strShow.substr(0, indexA);

        // find the title
        indexA = strShow.substr(indexA, strMovie.length()).find_first_not_of(' ');
        indexB = strMovie.find(',', indexA);
        std::string title = strMovie.substr(indexA, indexB);

        // find the year
        indexA = strMovie.substr(indexA, strMovie.length()).find_first_not_of(' ');
        indexB = strMovie.find(',', indexA);
        unsigned short year = std::stoi(strMovie.substr(indexA, indexB), nullptr);

        // find the summary
        indexA = strShow.substr(indexB, strShow.length()).find_first_not_of(' ');
        std::string summary = strShow.substr(indexA);
        
        return new TvShow(id,title,summary,year);
    }

    template<typename Collection_t> 
    void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode);
    double TvShow::getEpisodeAverageLength() const;
}