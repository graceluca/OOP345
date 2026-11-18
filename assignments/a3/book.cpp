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
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <stdexcept>
#include "mediaItem.h"
#include "book.h"
using namespace std;
namespace seneca {
    Book::Book(const std::string title, const std::string& summary, unsigned short year, const std::string author, const std::string country, double price) : 
        mediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) { 

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
        indexB = strBook.find(',', indexA + 1);
        std::string title = strBook.substr(indexA, indexB);

        // find the country
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA + 1);
        std::string country = strBook.substr(indexA, indexB);

        // find the price
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA + 1);
        double price = std::stod(strBook.substr(indexA, indexB), nullptr);

        // find the year
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        indexB = strBook.find(',', indexA + 1);
        unsigned short year = std::stoi(strBook.substr(indexA, indexB), nullptr);

        //find the summary
        indexA = strBook.substr(indexB, strBook.length()).find_first_not_of(' ');
        std::string summary = strBook.substr(indexA);

        return new Book(title, summary, year, author, country, price);
    }
}