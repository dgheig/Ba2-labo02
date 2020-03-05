#include "date.h"


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

}

bool Date::isDateValid(unsigned day, unsigned month, unsigned year) {
    return isDayValid(day, month, year) and isMonthValid(month) and isYearValid(year);
}

bool Date::isYearValid(unsigned year) {
    return true;
}

bool Date::isMonthValid(unsigned month) {
    return 0 < month and month < 13;
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
    return date.display(os);
}
std::istream& operator>>(std::istream& is,  Date& date){
    return date.receve(is);
}

std::istream & Date::receve(std::istream &is)  {
    is >> this->_day;
    is.ignore(1);
    is >> this->_month;
    is.ignore(1);
    is >> this->_year;
    if(is.fail())
        this->_is_valid = false;
    else
        this->_is_valid = isDateValid(this->_day, this->_year, this->_month);
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
        if(this->_month < date._month){
            if(this->_day < date._day){
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
}

bool Date::operator<=(const Date &date) const {
    return !(*this > date);
}

bool Date::operator>=(const Date &date) const {
    return !(*this < date);
}

Date Date::operator+(int jours) const {

}

Date Date::operator-(int jours) const {

}
