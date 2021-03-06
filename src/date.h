/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : date.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 8.03.2020

But         : Declare class Date, enum class Month and functions useful for it
Remarque(s) :
Compilateur : g++ 7.4.0
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
        Date(unsigned day, std::string month, unsigned year);

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
        unsigned getDay() const;

        /**
         * @brief get month value
         * @return unsigned
         */
        unsigned getMonthNo() const;

        /**
         * @brief get month value
         * @return string
         */
        std::string getMonthString() const;

        /**
         * @brief get month value
         * @return Month enum
         */
        Month getMonthEnum() const;

        /**
         * @brief get year value
         * @return unsigned
         */
        unsigned getYear() const;

        /**
         * @brief get a bool indicating if Date values are valid
         * @return bool
         */
        bool isValid() const;


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

        /**
         * @brief Convert month to string according to the define format
         * @return Month converted into string
         */
        operator std::string();

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the two dates are equal
         */
        bool operator==(const Date& date) const;

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the two dates are inequal
         */
        bool operator!=(const Date& date) const;

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the date tested is lower than the param date
         */
        bool operator<(const Date& date) const;

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the date tested is lower or equal to the param date
         */
        bool operator<=(const Date& date) const;

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the date tested is higher than the param date
         */
        bool operator>(const Date& date) const;

        /**
         * @brief Compare two dates
         * @param date
         * @return True if the date tested is higher or equal to the param date
         */
        bool operator>=(const Date& date) const;

        /**
         * @brief Add X day to a date
         * @param days
         * @return The object date modified
         */
        Date& operator+=(unsigned days);

        /**
         * @brief Substract X day to a date
         * @param days
         * @return The object date modified
         */
        Date& operator-=(unsigned days);

        /**
         * @brief Add X day to a date
         * @param days
         * @return The object date modified
         */
        Date& operator+=(int days);

        /**
         * @brief Substract X day to a date
         * @param days
         * @return The object date modified
         */
        Date& operator-=(int days);

        /**
         * @brief Get the number of days between two dates
         * @param days
         * @return days as int
         */
        int operator-(const Date& date) const;

        /**
         * @brief Assign an object date to an other object date
         * @param date
         * @return The object date modified
         */
        Date& operator=(const Date& date);

        /**
         * @brief Pre-incrementation of an object date
         * @return The object date modified
         */
        Date& operator++();

        /**
         * @brief Post-incrementation of an object date
         * @return The object date before incrementation
         */
        Date operator++(int);

        /**
         * @brief Pre-decrementation of an object date
         * @return The object date modified
         */
        Date& operator--();

        /**
         * @brief Post-decrementation of an object date
         * @return The object date before decrementation
         */
        Date operator--(int);

        /**
         * @brief Display date in a format DD.MM.YYYY
         * @param os
         * @return output stream "DD.MM.YYYY"
         */
        std::ostream& display(std::ostream& os = std::cout) const;

        /**
         * @brief Receive date in a format DD.MM.YYYY
         * @param is
         * @return  input stream "DD.MM.YYYY"
         */
        std::istream& receive(std::istream& is = std::cin);


    private:

        /**
         * @brief Set validity according to inner values
         */
        void setValidity();

        /**
         * @brief Get the number of days since a reference date,
         *        it is used to compute the number of day between two dates
         */
        int get_days_since_reference_day() const;
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

Date operator+(Date date, unsigned days);
Date operator+(unsigned days, const Date date);
Date operator-(Date date, unsigned days);

Date operator+(Date date, int days);
Date operator+(int days, const Date& date);
Date operator-(Date date, int days);


#endif
