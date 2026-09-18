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
        vector<string> split;
        stringstream ss(line);
        while (ss.good()) {
            std::string substr;
            std::getline(ss, substr, ',');
            split.push_back(substr);
        }
        m_words[dest].m_word = split[0];
        m_words[dest].m_definition = split[2]; 
        if (split[1] == "n." || split[1] == "n. pl") {
            m_words[dest].m_pos = PartOfSpeech::Noun;
        }
        else if (split[1] == "adv.") {
            m_words[dest].m_pos = PartOfSpeech::Adverb;
        }
        else if (split[1] == "a.") {
            m_words[dest].m_pos = PartOfSpeech::Adjective;
        }
        else if (split[1] == "v." || split[1] == "v. i." || split[1] == "v. t." || split[1] == "v. t. & i.") {
            m_words[dest].m_pos = PartOfSpeech::Verb;
        }
        else if (split[1] == "prep.") {
            m_words[dest].m_pos = PartOfSpeech::Preposition;
        }
        else if (split[1] == "pron.") {
            m_words[dest].m_pos = PartOfSpeech::Pronoun;
        }
        else if (split[1] == "conj.") {
            m_words[dest].m_pos = PartOfSpeech::Conjunction;
        }
        else if (split[1] == "interj.") {
            m_words[dest].m_pos = PartOfSpeech::Interjection;
        }
        else {
            m_words[dest].m_pos = PartOfSpeech::Unknown;
        }
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
        m_words = new Word[];
        while (std::getline(file, line)) {
            allocateWord(line, m_wordCount);
            m_wordCount++;
        }
    }
    void Dictionary::searchWord(const char* word) {
    }
}