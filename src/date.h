#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

enum class Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Date {
    public:
        Date(unsigned day, unsigned month, unsigned year);
        Date(unsigned day, Month month, unsigned year);

        Date& setDay(unsigned day);
        Date& setMonth(unsigned month);
        Date& setMonth(Month month);
        Date& setMonth(std::string month);
        Date& setYear(unsigned year);

        unsigned getDay();
        unsigned getMonthNo();
        std::string getMonthString();
        Month getMonthEnum();
        unsigned getYear();

        static bool isLeap(unsigned year);
        static unsigned dayInMonth(unsigned month, unsigned year);

        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date) const;
        bool operator<=(const Date& date) const;
        bool operator>(const Date& date) const;
        bool operator>=(const Date& date) const;

        Date& operator+=(unsigned jours);
        Date& operator-=(unsigned jours);

        std::ostream& afficher(std::ostream& os = std::cout) const;

    private:
        void setValidity();
        static bool isYearValid(unsigned year);
        static bool isMonthValid(unsigned month);
        static bool isDayValid(unsigned day, unsigned month, unsigned year);

        bool _is_valid;
        unsigned _year;
        unsigned _month;
        unsigned _day;

};

std::ostream& operator<<(std::ostream& os, const Date& date);
Date operator+(Date date, unsigned jours);
Date operator+(int jours, const Date& date);
Date operator-(Date date, unsigned jours);
Date operator-(int jours, const Date& date);


#endif
