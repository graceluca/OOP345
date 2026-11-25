/***********************************************************************
// OOP345 Assignment 3, tvShow module
//
// File	tvShow.h
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
#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H
#include <iostream>
#include <string>
#include <vector>
#include "mediaItem.h"
namespace seneca {
    struct TvEpisode
    {
        const TvShow* m_show{};
        unsigned short m_numberOverall{};
        unsigned short m_season{};
        unsigned short m_numberInSeason{};
        std::string m_airDate{};
        unsigned int m_length{};
        std::string m_title{};
        std::string m_summary{};
    };
    class tvShow : public MediaItem {
        private:
            std::string m_id{}; // stored as a string due to the length and complexities of these ids
            std::vector<TvEpisode> m_episodes; // stored as a vector for ease of scaling and addition
            TvShow(const std::string& title, const std::string& summary, unsigned short year, const std::string id);
        public:
            void display(std::ostream& out) const override;
            TvShow* createItem(const std::string& strShow);
            template<typename Collection_t> 
            void addEpisode(Collection_t& col, const std::string& strEpisode);
            double getEpisodeAverageLength() const;
    };
}
#endif