
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca{
    class FoodOrder {
        char m_name[10]{};
        char* m_description;
        double m_price{};
        bool m_isSpecial{};
    public:
        void read(std::istream &is);
        void display() const;

        FoodOrder();
        FoodOrder(const FoodOrder& f);
        FoodOrder& operator=(const FoodOrder& f);
        ~FoodOrder();
    };
}
#endif