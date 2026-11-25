/***********************************************************************
// OOP345 Assignment 3, movie module
//
// File	movie.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the movie module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/24/2026      Beginning movie module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iostream>
#include <string>
#include "mediaItem.h"
namespace seneca {
    class Movie : public MediaItem {
        public: 
            using MediaItem::MediaItem;
            void display(std::ostream& out) const override;
            Movie* createItem(const std::string& strMovie);
    };
}
#endif