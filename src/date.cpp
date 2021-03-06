/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : date.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 8.03.2020

But         : Function definition for header date.h
Remarque(s) :
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include "date.h"
#include <sstream>
#include <iomanip>

const char* const MONTH_NAME[] = {
    "UNDEFINED",
    "JANUARY",
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER"
};

size_t MONTH_NAME_SIZE = sizeof(MONTH_NAME) / sizeof(const char*);
const unsigned REF_YEAR = 1582;

std::string monthToString(unsigned month) {
    if(month < MONTH_NAME_SIZE)
        return MONTH_NAME[month];
    return MONTH_NAME[0];
}

std::string toString(Month month) {
    return monthToString(unsigned(month));
}

unsigned convertMonth(std::string month) {
    for(size_t index = 0; index < MONTH_NAME_SIZE; ++index) {
        if(MONTH_NAME[index] == month) {
            return (unsigned)index;
        }
    }
    return 0;
}


Date::Date(unsigned day, unsigned month, unsigned year): _day(day), _month(month), _year(year) {
    setValidity();
}

Date::Date(unsigned day, std::string month, unsigned year): Date(day, convertMonth(month), year) {

}

Date::Date(unsigned day, Month month, unsigned year): Date(day, unsigned(month), year) {

}


Date::operator std::string() {

    std::stringstream stream;
    stream << *this;
    return stream.str();
}

Date& Date::setDay(unsigned day) {
    _day = day;
    setValidity();
    return *this;
}

Date& Date::setMonth(unsigned month) {
    _month = month;
    setValidity();
    return *this;
}

Date& Date::setMonth(Month month) {
    return setMonth(unsigned(month));
}

Date& Date::setMonth(std::string month) {
    return setMonth(convertMonth(month));
}

Date& Date::setYear(unsigned year) {
    _year = year;
    setValidity();
    return *this;
}

unsigned Date::getDay() const {
    return _day;
}

unsigned Date::getMonthNo() const {
    return _month;
}

std::string Date::getMonthString() const {
    return monthToString(_month);
}

Month Date::getMonthEnum() const {
    return Month(_month);
}

unsigned Date::getYear() const {
    return _year;
}

bool Date::isLeap(unsigned year) {
    return (!(year % 4) and year % 100) or !(year % 400);
}

void Date::setValidity() {
    _is_valid = isDateValid(_day, _month, _year);
}

bool Date::isDateValid(unsigned day, unsigned month, unsigned year) {
    return isYearValid(year) and isMonthValid(month) and isDayValid(day, month, year);
}

bool Date::isYearValid(unsigned year) {
    return year >= REF_YEAR;
}

bool Date::isMonthValid(unsigned month) {
    return unsigned(Month::JANUARY) <= month and month <= unsigned(Month::DECEMBER);
}

bool Date::isDayValid(unsigned day, unsigned month, unsigned year) {
    return 0 < day and day <= dayInMonth(month, year);
}

bool Date::isValid() const {
    return _is_valid;
}

unsigned Date::dayInMonth(unsigned month, unsigned year) {
    switch ((Month)month) {
        case Month::JANUARY:
        case Month::MARCH:
        case Month::MAY:
        case Month::JULY:
        case Month::AUGUST:
        case Month::OCTOBER:
        case Month::DECEMBER:
            return 31;

        case Month::APRIL:
        case Month::JUNE:
        case Month::SEPTEMBER:
        case Month::NOVEMBER:
            return 30;
        case Month::FEBRUARY:
            return isLeap(year) ? 29 : 28;
    }
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
    return date.display(os);
}

std::istream& operator>>(std::istream& is,  Date& date){
    return date.receive(is);
}

// On doit pouvoir utiliser getline
std::istream & Date::receive(std::istream &is)  {
    const char DELIMITER = '.';
    char first_delimiter;
    char second_delimiter;

    is >> _day
       >> first_delimiter
       >> _month
       >> second_delimiter
       >> _year;

    if(is.fail()) {
        _is_valid = false;
        is.clear();
        while(is.get() != '\n');
    } else if (first_delimiter != DELIMITER or second_delimiter != DELIMITER){
        _is_valid = false;  // Si la date est juste mais avec les mauvais delimiter, il suffira de setDay(getDay()),
                            // ce n'est donc pas une bonne façon de gérer le mauvais format
    } else {
        setValidity();
    }

    return is;
}


std::ostream & Date::display(std::ostream &os) const{
    if(_is_valid)
        return os << std::setfill('0') << std::setw(2) << _day  << "." << _month << "." << _year;
    return os << "invalide";

}

bool Date::operator==(const Date &date) const {
    if(_year == date._year){
        if(_month == date._month){
            if(_day == date._day){
                return true;
            }
        }
    }
    return false;
}

bool Date::operator!=(const Date &date) const {
    return !(*this == date);
}

bool Date::operator<(const Date &date) const {
    if(_year < date._year) {
        return true;
    }
    else if(_year == date._year) {
        if(_month < date._month) {
            return true;
        }
        else if(_month == date._month) {
            if(_day < date._day) {
                return true;
            }
        }

    }
    return false;
}

bool Date::operator>(const Date &date) const {
    return (date < *this);
}

bool Date::operator<=(const Date &date) const {
    return !(*this > date);
}

bool Date::operator>=(const Date &date) const {
    return !(*this < date);
}

Date& Date::operator+=(unsigned days) {
    if(!isValid())
        return *this;

    while(days) {
        unsigned nbDays = dayInMonth(_month, _year) - _day + 1;
        if(nbDays > days) {
            _day += days;
            days = 0;
        } else {
            days -= nbDays;
            _day = 1;
            if(_month == unsigned(Month::DECEMBER)) {
                _month = 1;
                ++_year;
            } else {
                ++_month;
            }
        }
    }
    return *this;
}

Date& Date::operator-=(unsigned days) {
    if(!isValid())
        return *this;

    while (days) {
        if (_day > days) {
            _day -= days;
            days = 0;
        } else {
            days -= _day;
            if (_month == unsigned(Month::JANUARY)) {
                _month = unsigned(Month::DECEMBER);
                --_year;
            } else {
                --_month;
            }
            _day = dayInMonth(_month, _year);
        }
    }
    return *this;

}


Date& Date::operator+=(int days) {
    if(days < 0)
        return *this -= unsigned(-days);
    return *this += unsigned(days);
}

Date& Date::operator-=(int days) {
    if(days < 0)
        return *this += unsigned(-days);
    return *this -= unsigned(days);
}

int Date::get_days_since_reference_day() const {

   const int DAY_PER_YEAR   = 365;
   const int MONTH_PER_YEAR = 12;
   const int REFERENCE_YEAR = 1600; // Must be a leap year

   int start_of_year_shifter = (14 - _month) / MONTH_PER_YEAR;
   int number_of_months = _month + MONTH_PER_YEAR * start_of_year_shifter - 3;
   int number_of_years = _year - REFERENCE_YEAR - start_of_year_shifter;
   int number_of_leap_years = number_of_years / 4 - number_of_years / 100 + number_of_years / 400;

   int days = _day + (153 * number_of_months + 2) / 5 + DAY_PER_YEAR * number_of_years + number_of_leap_years + 58;

   return days;

}

int Date::operator-(const Date& date) const {
    return get_days_since_reference_day() - date.get_days_since_reference_day();
}

Date operator+(Date date, unsigned days) {
    return date += days;
}

Date operator+(unsigned days, const Date& date) {
    return date + days;
}

Date operator-(Date date, unsigned days) {
    return date -= days;
}

Date operator+(Date date, int days) {
    return date += days;
}

Date operator+(int days, const Date& date) {
    return date + days;
}

Date operator-(Date date, int days) {
    return date -= days;
}

Date& Date::operator++() {
    return *this += 1;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++*this;
    return temp;
}

Date& Date::operator--() {
    return *this -= 1;
}

Date Date::operator--(int) {
    Date temp = *this;
    --*this;
    return temp;
}

Date& Date::operator=(const Date &date) {
    _day   = date._day;
    _month = date._month;
    _year  = date._year;

    /*
        safer than copying _is_valid:
        e.g: Suppose that a class inherits from Date and overrides
        functions which leads to change the behaviour of _is_valid.

        To ensure the integrity of the object, we use setValidity.
    */
    setValidity();
    return *this;
}
