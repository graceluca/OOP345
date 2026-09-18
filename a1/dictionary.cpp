/***********************************************************************
// OOP244 workshop 9, Dictionary module
//
// File	dictionary.cpp
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the C++ code for the dictionary module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning dictionary module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
namespace seneca {

    void Dictionary::allocateWord(const std::string line, const int dest) {
       
    }

    Dictionary::Dictionary() : m_wordCount(0) {
        m_words = nullptr;
    }

    Dictionary::Dictionary(const char* filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            *this = Dictionary();
        }
        std::string line;
        m_wordCount = 0;
        while (std::getline(file, line)) {
            allocateWord(line, m_wordCount);
            m_wordCount++;
        }
    }
}