#ifndef DATE_H
#define DATE_H

#include <iostream>

enum class Month {

};

class Date {
    public:
        Date(unsigned day, unsigned month, unsigned year);
        Date(unsigned day, Month month, unsigned year);

        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date) const;
        bool operator<=(const Date& date) const;
        bool operator>(const Date& date) const;
        bool operator>=(const Date& date) const;
        Date operator+(int jours) const;
        Date operator-(int jours) const;
        std::ostream& afficher(std::ostream& os = std::cout) const;

    private:
        unsigned _year;
        unsigned _month;
        unsigned _day;

};

std::ostream& operator<<(std::ostream& os, const Date& date);


#endif
