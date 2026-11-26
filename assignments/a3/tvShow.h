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
// Grace Currier-Moritsugu  11/26/2026      Fixing typos and adding in more functions
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "mediaItem.h"
namespace seneca {
    class TvShow;
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
    class TvShow : public MediaItem {
        private:
            std::string m_id{}; // stored as a string due to the length and complexities of these ids
            std::vector<TvEpisode> m_episodes; // stored as a vector for ease of scaling and addition
            TvShow(const std::string& title, const std::string& summary, unsigned short year, const std::string id);
            bool matchingId(std::string otherId) const;
            bool isLong(const TvEpisode episode) const;
            unsigned int convertTime(const std::string& time) const;
        public:
            void display(std::ostream& out) const override;
            TvShow* createItem(const std::string& strShow);

            template<typename Collection_t> 
            static void addEpisode(Collection_t& col, const std::string& strEpisode) {
                if (strEpisode.empty() || strShow[0] == '#') {
                    throw std::invalid_argument("Not a valid episode.");
                }
                std::size_t indexA, indexB;
                TvEpisode episode;

                // find the id
                indexA = strEpisode.find(',');
                std::string id = strEpisode.substr(0, indexA);

                // find the overall episode number
                indexA = strEpisode.substr(indexA).find_first_not_of(' ');
                indexB = strEpisode.find(',', indexA);
                episode.m_numberOverall = std::stoi(strEpisode.substr(indexA, indexB - indexA), nullptr);
            
                // find the season
                indexA = strShow.substr(indexA).find_first_not_of(' ');
                indexB = strShow.find(',', indexA);
                if ((strEpisode.substr(indexA, size), nullptr) == ' ') {
                    episode.m_season = 1;
                }
                else {
                    episode.m_season = std::stoi(strEpisode.substr(indexA, indexB - indexA), nullptr);
                }

                // find the episode number in season
                indexA = strEpisode.substr(indexB).find_first_not_of(' ');
                indexB = strEpisode.find(',', indexA);
                episode.m_numberInSeason = std::stoi(strEpisode.substr(indexA, indexB - indexA), nullptr);

                // find the air date
                indexA = strEpisode.substr(indexB).find_first_not_of(' ');
                indexB = strEpisode.find(',', indexA);
                episode.m_airDate = strEpisode.substr(indexA, indexB - indexA);

                // find the length
                indexA = strEpisode.substr(indexB).find_first_not_of(' ');
                indexB = strEpisode.find(',', indexA);
                episode.m_length = convertTime(strEpisode.substr(indexA, indexB - indexA));

                // find the title
                indexA = strEpisode.substr(indexB).find_first_of('"');
                indexB = strEpisode.substr(indexA + 1).find_first_of('"');
                episode.m_title = strEpisode.substr(indexA, indexB - indexA);

                // find the summary
                indexA = strEpisode.substr(indexB + 1).find_first_of('"');
                episode.m_title = strEpisode.substr(indexA);

                for (std::size_t i = 0; i < col.size(); i++) {
                    if (dynamic_cast<TvShow*> col[i].matchingId(id)) {
                        col[i].m_episodes.push_back(episode);
                        break;
                    }
                }
            }

            double getEpisodeAverageLength() const;
            std::list<std::string> getLongEpisodes() const;
    };
}
#endif