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

bool Date::isYearValid() {

}

bool Date::isMonthValid() {
    return 0 < _month and _month < 13;
}

bool Date::isDayValid() {
    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;

    default:
        break;
    }
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
