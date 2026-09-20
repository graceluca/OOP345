#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "FoodOrder.h"

using namespace std;

double g_taxrate = 0;
double g_dailydiscount = 0;

namespace seneca {

    FoodOrder::FoodOrder(){
        m_name[0] = '\0';
        m_description = nullptr;
    }

    void FoodOrder::read(std::istream& is){
        if (is) {
            is.getline(m_name,10,',');

            if (m_description) {
                delete[] m_description;
            }

            std::string buffer;
            getline(is,buffer,',');

            m_description = new char[buffer.length() + 1];
            std::strcpy(m_description, buffer.c_str());

            is >> m_price;
            char tmp{ 'Y' };
            is.ignore();
            is >> tmp;
            m_isSpecial = (tmp == 'Y');
        }
    }
    
    void FoodOrder::display() const {
        static std::size_t counter = 0;
        std::cout << std::left << std::setw(2) << ++counter << ". ";
        if (m_name[0] == '\0') {
            std::cout << "No Order";
        }
        else {
            double taxedPrice = m_price - (m_price * g_taxrate);
            std::cout 
                << std::left << std::setw(10) << m_name << "|"
                << std::left << std::setw(25) << m_description << "|"
                << std::left << std::setw(12) << std::setprecision(2) << taxedPrice << "|";
            if (m_isSpecial) {
                std::cout << std::right << std::setw(13) << std::setprecision(2) << taxedPrice - g_dailydiscount;
            }
        }
        std::cout << std::endl;
    }

    FoodOrder::~FoodOrder(){
        delete [] m_description;
    }

     FoodOrder::FoodOrder(const FoodOrder& f) {
        m_description = nullptr;
        *this = f;
    }

    FoodOrder& FoodOrder::operator=(const FoodOrder& f) {
        if (this != &f) {

            std::strcpy(m_name, f.m_name);
            m_price = f.m_price;
            m_isSpecial = f.m_isSpecial;
            
            if (f.m_description) {
                m_description = new char[std::strlen(f.m_description) + 1];
                std::strcpy(m_description, f.m_description);
            }
        }
        return *this;
    }

   

}