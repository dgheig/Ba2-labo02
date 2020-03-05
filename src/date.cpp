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

size_t MONTH_NAME_SIZE = sizeof(MONTH_NAME);

std::string monthToString(unsigned month) {
    if(month < MONTH_NAME_SIZE)
        return MONTH_NAME[month];
    return MONTH_NAME[0];
}

std::string toString(Month month) {
    return monthToString(unsigned(month));
}

unsigned toMonth(std::string month) {
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
    return setMonth(toMonth(month));
}

Date& Date::setYear(unsigned year) {
    _year = year;
    setValidity();
    return *this;
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
    _is_valid = isDateValid(_day, _month, _year);
}

bool Date::isDateValid(unsigned day, unsigned month, unsigned year) {
    return isYearValid(year) and isMonthValid(month) and isDayValid(day, month, year);
}

bool Date::isYearValid(unsigned year) {
    return year > 1970;
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
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
    return date.display(os);
}

std::istream& operator>>(std::istream& is,  Date& date){
    return date.receve(is);
}

// On doit pouvoir utiliser getline
std::istream & Date::receve(std::istream &is)  {
    is >> this->_day;
    is.ignore(1);
    is >> this->_month;
    is.ignore(1);
    is >> this->_year;
    if(is.fail()) {
        this->_is_valid = false;
        is.clear();
        while(is.get() != '\n');
    } else
        setValidity();

    return is;
}


std::ostream & Date::display(std::ostream &os) const{
    if(this->_is_valid)
        return os << _day  << "." << _month << "." << _year;
    return os << "invalide";

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
    return (date < *this);
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
                _month = 1;
                ++_year;
            } else {
                ++_month;
            }
        }
    }
    return *this;
}

// Date Date::operator+(unsigned jours){
//     if(this->_is_valid){
//         while(jours > 0){
//             unsigned nbDays = this->dayInMonth(this->_month, this->_year);
//             if(this->_day + jours <= nbDays){
//                 this->_day += jours;
//                 break;
//             } else {
//                 if(this->_month == (unsigned)Month::DECEMBER){
//                     this->_year++;
//                     this->_month = (unsigned)Month::JANUARY;
//                 } else {
//                     this->_month += 1;
//                 }
//                 jours -= nbDays + 1 - this->_day;
//             }
//         }
//     }
//     return *this;
// }

Date& Date::operator-=(unsigned jours) {
    while(jours) {
        if(_day > jours) {
            _day -= jours;
            jours = 0;
        } else {
            jours -= _day;
            if(_month == unsigned(Month::JANUARY)) {
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

// Date Date::operator-(unsigned jours)  {
//     if(this->_is_valid){
//         while(jours > 0){
//             if(this->_day - jours > 1){
//                 this->_day -= jours;
//                 break;
//             } else {
//                 if(this->_month == (unsigned)Month::JANUARY){
//                     this->_year--;
//                     this->_month = (unsigned)Month::DECEMBER;
//                 } else {
//                     this->_month -= 1;
//                 }
//                 jours -= this->_day;
//                 this->_day = this->dayInMonth(this->_month, this->_year);
//             }
//         }
//     }
//     return *this;
// }

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

Date & Date::operator++() {
    return *this += 1;
}

Date Date::operator++(int) {

    Date temp = *this;
    ++*this;
    return temp;
}
