#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H
#include <iostream>
#include <string>
namespace seneca {
    class ProteinDatabase {
        private:
            std::string* m_UIDs { nullptr };
            std::string* m_sequences{ nullptr };
            std::size_t m_count{ 0 };
        public:
            ProteinDatabase() = default;
            ProteinDatabase(const std::string filename);
            ProteinDatabase(const ProteinDatabase& other);
            ProteinDatabase(ProteinDatabase&& other) noexcept;
            ProteinDatabase& operator=(const ProteinDatabase& other);
            ProteinDatabase& operator(ProteinDatabase&& other) noexcept;

            ~ProteinDatabase();

            std::size_t size() const;
            std::string operator[](const std::size_t index) const;
            std::string getUID(const std::size_t index) const;
    };
}
#endif