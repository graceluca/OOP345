/***********************************************************************
// OOP345 Assignment 1, Dictionary module
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
// Grace Currier-Moritsugu  09/28/2026      Trying to figure out a search algorithm
// Grace Currier-Moritsugu  10/06/2026      Realized an algorithm is unnecessary
// Grace Currier-Moritsugu  10/08/2026      Trying to fix issues with the difference in outputs
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <iostream>
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
            Word* m_words = nullptr;
            std::size_t m_wordCount{};
            void allocateWord(const std::string& line, const std::size_t dest);
        public: 
            Dictionary() = default;
            ~Dictionary();
            Dictionary(const char* filename);
            Dictionary(const Dictionary& D);
            Dictionary& operator=(const Dictionary& D);
            Dictionary(Dictionary&& D) noexcept;
            Dictionary& operator=(Dictionary&& D) noexcept;
            bool wordMatch(const std::size_t index, const char* word) const;
            std::string getStringPos(const std::size_t index) const;
            void printWord(const std::size_t index, const bool multiple) const;
            void printWord(const char* word) const;
            void searchWord(const char* word);
            
            
        
    };
    
}
#endif