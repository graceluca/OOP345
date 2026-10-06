/***********************************************************************
// OOP345 Assignment 1, Dictionary module
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
// Grace Currier-Moritsugu  09/28/2026      Trying to figure out a search algorithm
// Grace Currier-Moritsugu  10/06/2026      Realized an algorithm in unnecessary
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "dictionary.h"
#include "settings.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;
namespace seneca {

    void Dictionary::allocateWord(const std::string line, const std::size_t dest) {
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
        
        while (std::getline(file, line)) {
            m_wordCount++;
        }

        m_words = new Word[m_wordCount + 1];
        file.clear();
        file.seekg(0, ios::beg);
        std::string line2;
        std::size_t i = 0;
        while(std::getline(file,line2)) {
            allocateWord(line2, i);
            i++;
        }
    }

    bool Dictionary::wordMatch(const std::size_t index, const char* word) const{
        return m_words[index].m_word == word;
    }

    std::string Dictionary::getStringPos(const std::size_t index) const{
        switch (m_words[index].m_pos) {
            case PartOfSpeech::Unknown:
                return "unknown";
            case PartOfSpeech::Noun:
                return "noun";
            case PartOfSpeech::Pronoun:
                return "pronoun";
            case PartOfSpeech::Adjective:
                return "adjective";
            case PartOfSpeech::Adverb:
                return "adverb";
            case PartOfSpeech::Verb:
                return "verb";
            case PartOfSpeech::Preposition:
                return "preposition";
            case PartOfSpeech::Conjunction:
                return "conjunction";
            case PartOfSpeech::Interjection:
                return "interjection";
        }
    }

    void Dictionary::printWord(const std::size_t index, const bool multiple) const{
        if (!multiple) {
            std::cout << m_words[index].m_word;
        }
        else if (multiple) {
            std::cout << std::setw(m_words[index].m_word.length());
        }
        std::cout << " - ("  << getStringPos(index) << ") " << m_words[index].m_definition;
    }

    void Dictionary::printWord(const char* word) const{
        std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
    }

    void Dictionary::searchWord(const char* word) {
        bool matchMade = false, multiple = false;
        for (std::size_t i = 0; i < m_wordCount; i++) {
            if (wordMatch(i, word)) {
                matchMade = true;
                printWord(i, multiple);
                if (!g_settings.m_show_all) {
                    break;
                }
                multiple = true;
            }
        }
        if (!matchMade) {
            printWord(word);
        }
    }
}

