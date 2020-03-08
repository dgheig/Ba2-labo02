/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : date.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 8.03.2020

But         : Declare class Date, enum class Month and functions useful for it
Remarque(s) :
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

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

const unsigned DEFAULT_YEAR = 1970;

class Date {
    public:
        /**
         * @brief Create a Date
         * @param day
         * @param month
         * @param year
         */
        Date(unsigned day, unsigned month, unsigned year);

        /**
         * @brief Create a Date
         * @param day
         * @param month
         * @param year
         */
        Date(unsigned day = 1, Month month = Month::JANUARY, unsigned year = DEFAULT_YEAR);


        /**
         * @brief Update day value
         * @param day
         * @return Reference on this
         */
        Date& setDay(unsigned day);

        /**
         * @brief Update month value
         * @param month
         * @return Reference on this
         */
        Date& setMonth(unsigned month);

        /**
         * @brief Update month value
         * @param month
         * @return Reference on this
         */
        Date& setMonth(Month month);

        /**
         * @brief Update month value
         * @param month
         * @return Reference on this
         */
        Date& setMonth(std::string month);

        /**
         * @brief Update year value
         * @param year
         * @return Reference on this
         */
        Date& setYear(unsigned year);

        /**
         * @brief get day value
         * @return unsigned
         */
        unsigned getDay();

        /**
         * @brief get month value
         * @return unsigned
         */
        unsigned getMonthNo();

        /**
         * @brief get month value
         * @return string
         */
        std::string getMonthString();

        /**
         * @brief get month value
         * @return Month enum
         */
        Month getMonthEnum();

        /**
         * @brief get year value
         * @return unsigned
         */
        unsigned getYear();

        /**
         * @brief get a bool indicating if Date values are valid
         * @return bool
         */
        bool isValid();


        /**
         * @brief Indicate if the year is a leap year
         * @return True if the year is leap, else return false
         */
        static bool isLeap(unsigned year);

        /**
         * @brief Get the number of day in a month
         * @return Number of day in the given month or unsigned max value
         */
        static unsigned dayInMonth(unsigned month, unsigned year);

        operator std::string();
        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date) const;
        bool operator<=(const Date& date) const;
        bool operator>(const Date& date) const;
        bool operator>=(const Date& date) const;

        Date& operator+=(unsigned jours);
        Date& operator-=(unsigned jours);
        Date& operator=(const Date& date);

        Date& operator++();     // ++date
        Date operator++(int);   // date++
        Date& operator--();     // --date
        Date operator--(int);   // date--
        std::ostream& display(std::ostream& os = std::cout) const;
        std::istream& receive(std::istream& is = std::cin);


    private:
        void setValidity();
        static bool isDateValid(unsigned day, unsigned month, unsigned year);
        static bool isYearValid(unsigned year);
        static bool isMonthValid(unsigned month);
        static bool isDayValid(unsigned day, unsigned month, unsigned year);

        bool _is_valid;
        unsigned _day;
        unsigned _month;
        unsigned _year;

};

std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);

Date operator+(Date date, unsigned jours);
Date operator+(int jours, const Date& date);
Date operator-(Date date, unsigned jours);


#endif
