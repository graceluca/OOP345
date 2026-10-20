#include <iostream>
#include <string>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace seneca {
    ProteinDatabase::ProteinDatabase(const std::string filename) {
        m_UIDs = nullptr;
        m_sequences = nullptr;
        m_count = 0;

        if (filename.empty()) {
            return;
        }

        std::ifstream file(filename.c_str());
        std::string line, uid, name;
        if (!file.is_open()) {
            return;
        }

        while (std::getline(file, line).good()) {
            if (line[0] == '>') {
                m_count++;
            }
        }

        m_UIDs = new string[m_count + 1];
        m_sequences = new string[m_count + 1];
        file.clear();
        file.seekg(0, std::ios::beg);
        line.clear();
        std::size_t i = 0;
        while (std::getline(file, line).good()) {
            if (line[0] == '>') {
                

                name = line.substr(1);
                m_UIDs[i++] = line.substr(4u, line.find_first_of('|', 4u) - 4u);
            }
            else {
                m_sequences[i] += line;
            }
        }
    }
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other) {
        *this = other;
    }
    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &src) {
            m_count = other.m_count;
            delete[] m_UIDs;
            m_UIDs = nullptr;
            deletep[] m_sequences;
            m_sequences = nullptr;
            if (m_count != 0) {
                m_UIDs = new std::string[m_count];
                m_sequences = new std::string[m_count];
                for (std::size_t i = 0; i < m_count; i++) {
                    m_UIDs[i] = other.m_UIDs[i];
                    m_sequences[i] = other.m_sequences[i];
                }
            }
        }
        return *this;
    }
    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept {
        *this = std::move(other);
    }
    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) noexcept {
        if (this != &other) {
            m_count = other.m_count;
            delete[] m_UIDs;
            delete[] m_sequences;
            m_UIDs = other.m_UIDs;
            m_sequences = other.m_sequences;
            delete[] other.m_UIDs;
            delete[] other.m_sequences;
            other.m_count = 0;
        }
        return *this;
    }
    std::size_t ProteinDatabase::size() const {
        return m_size;
    }
    std::string ProteinDatabase::operator[](const std::size_t index)  const {
        if (index < m_count) {
            return m_sequences[index];
        }
        return '';
    }
    std::string ProteinDatabase::getUID(const std::size_t index) const {
        if (index < m_count) {
            return m_UIDs[index];
        }
        return "None";
    }
}
