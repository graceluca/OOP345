/***********************************************************************
// OOP345 Assignment 3, book module
//
// File	book.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the book module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/17/2026      Beginning book module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
#include "mediaItem.h"
namespace seneca {
    class Book : public MediaItem {
        private:
            std::string m_author{}; // stored as a string to stay consistent with the inherited title and summary
            std::string m_country{}; // stored as a string to stay consistent with the inherited title and summary
            double m_price{}; // stored as a double since the number might include decimals for cents
            Book() = default;
            Book(const std::string title, const std::string& summary, unsigned short year, const std::string author, const std::string country, double price);
        public: 
            void display(std::ostream& out) const override;
            Book* createItem(const std::string& strBook);
    };
}
#endif
