#include "date.h"

const char* const MONTH_NAME[] = {
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

size_t MONTH_NAME_SIZE = 12;

std::string monthToString(unsigned month) {
    size_t index = month - 1;
    if(index < MONTH_NAME_SIZE)
        return MONTH_NAME[index];
    return "undefined";
}

std::string toString(Month month) {
    size_t index = int(month) - 1;
    if(index < MONTH_NAME_SIZE)
        return MONTH_NAME[index];
    return "undefined";
}

unsigned toMonth(std::string month) {
    for(size_t index = 0; index < MONTH_NAME_SIZE; ++index) {
        if(MONTH_NAME[index] == month) {
            return index + 1;
        }
    }
    return MONTH_NAME_SIZE + 1;
}


Date::Date(unsigned day, unsigned month, unsigned year) {

}

Date::Date(unsigned day, Month month, unsigned year) {

}

Date& Date::setDay(unsigned day) {

}

Date& Date::setMonth(unsigned month) {

}

Date& Date::setMonth(Month month) {

}

Date& Date::setMonth(std::string month) {
    _month = toMonth(month);
    return *this;
}

Date& Date::setYear(unsigned year) {

}

unsigned Date::getDay() {
    return _day;
}

unsigned Date::getMonthNo() {
    return _month;
}

std::string Date::getMonthString() {
    return monthToString(_month);
}

Month Date::getMonthEnum() {
    return Month(_month);
}

unsigned Date::getYear() {
    return _year;
}

bool Date::isLeap(unsigned year) {
    return (!(year % 4) and year % 100) or !(year % 400);
}

void Date::setValidity() {
    _is_valid = isYearValid(_year) and isMonthValid(_month) and isDayValid(_day, _month, _year);
}

bool Date::isYearValid(unsigned year) {
    return true;
}

bool Date::isMonthValid(unsigned month) {
    return unsigned(Month::JANUARY) <= month and month <= unsigned(Month::DECEMBER);
}

bool Date::isDayValid(unsigned day, unsigned month, unsigned year) {
    return 0 < day and day <= dayInMonth(month, year);
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
    return 31;
}
std::ostream& operator<<(std::ostream& os, const Date& date){
    return date.afficher(os);
}
std::ostream & Date::afficher(std::ostream &os) const{
    return os << _day  << "." << _month << "." << _year;
}

bool Date::operator==(const Date &date) const {
    if(this->_year == date._year){
        if(this->_month == date._month){
            if(this->_day == date._day){
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
    if(this->_year < date._year){
        if(this->_month < date._month) {
            if(this->_day < date._day) {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator>(const Date &date) const {

    if(this->_year > date._year){
        if(this->_month > date._month){
            if(this->_day > date._day){
                return true;
            }
        }
    }
    return false;
    // return !(*this < date or *this == date);
}

bool Date::operator<=(const Date &date) const {
    return !(*this > date);
}

bool Date::operator>=(const Date &date) const {
    return !(*this < date);
}

Date& Date::operator+=(unsigned jours) {
    while(jours) {
        unsigned delta = dayInMonth(_month, _year) - _day;
        if(delta > jours) {
            _day += jours;
            jours = 0;
        } else {
            jours -= delta;
            _day = 1;
            if(_month == unsigned(Month::DECEMBER)) {
                _month == 1;
                _year += 1;
            } else {
                _month += 1;
            }
        }
    }
}

Date& Date::operator-=(unsigned jours) {
    while(jours) {
        unsigned delta = dayInMonth(_month, _year) - _day;
        if(_day > jours) {
            _day -= jours;
            jours = 0;
        } else {
            jours -= _day;
            if(_month == unsigned(Month::JANUARY)) {
                _month = unsigned(Month::DECEMBER);
                _year -= 1;
            } else {
                _month -= 1;
            }
            _day = dayInMonth(_month, _year);
        }
    }
}


Date operator+(Date date, unsigned jours) {
    return date += jours;
}

Date operator+(int jours, const Date& date) {
    return date + jours;
}

Date operator-(Date date, unsigned jours) {
    return date -= jours;
}

Date operator-(int jours, const Date& date) {
    return date - jours;
}
