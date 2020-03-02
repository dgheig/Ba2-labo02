#ifndef DATE_H
#define DATE_H

#include <string>

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

    private:
        void setValidity();
        bool isYearValid();
        bool isMonthValid();
        bool isDayValid();

        bool _is_valid;
        unsigned _year;
        unsigned _month;
        unsigned _day;
};

#endif
