/***********************************************************************
// OOP244 workshop 9, Dictionary module
//
// File	dictionary.h
// Author: Grace Currier-Moritsugu
// Email: gcurrier-moritsugu@myseneca.ca
// Student ID: 136335247
// Contains the headers for the dictionary module
// 
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my assignments. 
// This submitted piece of work has not been shared with any other student or 3rd party content provider except for the code copied from the professor.
// Revision History
// -----------------------------------------------------------
// Name                     Date            Reason
// Grace Currier-Moritsugu  09/18/2026      Beginning dictionary module
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <iostream>
#include <vector>
namespace seneca {
    enum class PartOfSpeech
    {
        Unknown,
        Noun,
    Pronoun,
    Adjective,
    Adverb,
    Verb,
    Preposition,
    Conjunction,
    Interjection,
    };

    struct Word
    {
        std::string m_word{};
        std::string m_definition{};
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };


    class Dictionary {
        private: 
            Word* m_words;
            int m_wordCount;
            void allocateWord(const std::string line, const int dest);
        public: 
            Dictionary();
            Dictionary(const char* filename);
            void searchWord(const char* word);
            
        
    }
}
#endif