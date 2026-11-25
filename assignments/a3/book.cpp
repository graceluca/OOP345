/***********************************************************************
// OOP345 Assignment 3, book module
//
// File	book.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the code for the book module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  11/17/2026      Beginning book module
// Grace Currier-Moritsugu  11/24/2026      Added in display function from Github
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>
#include "mediaItem.h"
#include "book.h"
#include "settings.h"
using namespace std;
namespace seneca {
    Book::Book(const std::string title, const std::string& summary, unsigned short year, const std::string author, const std::string country, double price) : 
        mediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) { 

    }

    void Book::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "B | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_country << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "] [";
            out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
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

    Book* Book::createItem(const std::string& strBook) {
        if (strBook.empty() || strBook[0] == '#') {
            throw std::invalid_argument("Not a valid book.");
        }
        std::size_t indexA, indexB;

        // find the author
        indexA = strBook.find(',');
        std::string author = strBook.substr(0, indexA);

        // find the title
        indexA = strBook.substr(indexA, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA);
        std::string title = strBook.substr(indexA, indexB);

        // find the country
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA);
        std::string country = strBook.substr(indexA, indexB);

        // find the price
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA);
        double price = std::stod(strBook.substr(indexA, indexB), nullptr);

        // find the year
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA);
        unsigned short year = std::stoi(strBook.substr(indexA, indexB), nullptr);

        //find the summary
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        std::string summary = strBook.substr(indexA);

        return new Book(title, summary, year, author, country, price);
    }

}